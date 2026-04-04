#include "cesar.h"

string cesar_encript(string str, int key){
  key%=ALPHA_SIZE;
	for(size_t i=0;i<str.size();i++){
    if(str[i] != SEPARATOR){
      int c = str[i] - 'a';
      c = (c+key)%ALPHA_SIZE;
      str[i] = c + 'a';
    }
	}
	return str;
}

string cesar_decript(string str, int key){
	key%=ALPHA_SIZE;
	for(size_t i=0;i<str.size();i++){
    if(str[i] != SEPARATOR){
      int c = str[i] - 'a';
      c -= key;
      if (c < 0) c += ALPHA_SIZE;
      str[i] = c + 'a';
    }
	}
	return str;
}

void brute_force_cesar_decript(string str, vector<string> dict){
  map<int, vector<string>> tokens;
  cout << "Saídas para chaves de 1 a " << ALPHA_SIZE << ":\n";
  for(int i=1;i<=ALPHA_SIZE;i++){
    string token, dec_s = cesar_decript(str, i);
    cout << "Chave " << i << ": " << dec_s << endl;
    istringstream tokenStream(dec_s);
    while(getline (tokenStream, token, SEPARATOR)){
      if(token.size() > 0)
        tokens[i].push_back(token);
    }
  }
  
  vector<int> results(ALPHA_SIZE, 0);
  for(int i=1;i<=ALPHA_SIZE;i++){
    for(int j=0;j<tokens[i].size();j++){
      auto it = lower_bound(dict.begin(), dict.end(), tokens[i][j]);
      if(it != dict.end()){
        if(*it == tokens[i][j]) results[i-1]++;
      }
    }
  }

  int poss_res = 0;
  for(int i=0;i<ALPHA_SIZE;i++){
    if(results[i] > results[poss_res]) poss_res = i;
  }

  cout << "\n\nA possível chave utilizada é: " << poss_res+1 << ".\n";
  cout << ((float)results[poss_res]/tokens[poss_res].size())*100;
  cout << "% das palavras possuem correspondentes na língua portuguesa.\n\n";
}