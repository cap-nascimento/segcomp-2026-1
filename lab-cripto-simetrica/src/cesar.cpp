#include "cesar.h"

string cesar_encrypt(string str, int key){
  // módulo do deslocamento caso key > ALPHA_SIZE
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

string cesar_decrypt(string str, int key){
  // módulo do deslocamento caso key > ALPHA_SIZE
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

void brute_force_cesar_decrypt(string str, vector<string> dict){
  map<int, vector<string>> tokens;
  cout << "Saídas para chaves de 1 a " << ALPHA_SIZE << ":\n";
  for(int i=1;i<=ALPHA_SIZE;i++){
    string token, dec_s = cesar_decrypt(str, i);
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

string auto_cesar_decrypt(string str){
  map<char, double> pt_br_freq;
  pt_br_freq['a'] = 14.63; pt_br_freq['n'] = 5.05;
  pt_br_freq['b'] = 1.04;  pt_br_freq['o'] = 10.73;
  pt_br_freq['c'] = 3.88;  pt_br_freq['p'] = 2.52;
  pt_br_freq['d'] = 4.99;  pt_br_freq['q'] = 1.20;
  pt_br_freq['e'] = 12.57; pt_br_freq['r'] = 6.53;
  pt_br_freq['f'] = 1.02;  pt_br_freq['s'] = 7.81;
  pt_br_freq['g'] = 1.30;  pt_br_freq['t'] = 4.34;
  pt_br_freq['h'] = 1.28;  pt_br_freq['u'] = 4.63;
  pt_br_freq['i'] = 6.18;  pt_br_freq['v'] = 1.67;
  pt_br_freq['j'] = 0.40;  pt_br_freq['w'] = 0.01;
  pt_br_freq['k'] = 0.02;  pt_br_freq['x'] = 0.21;
  pt_br_freq['l'] = 2.78;  pt_br_freq['y'] = 0.01;
  pt_br_freq['m'] = 4.74;  pt_br_freq['z'] = 0.47;
  priority_queue<pair<double, char>> pt_br_freq_pq;
  for(pair<char, double> p : pt_br_freq) {
    pt_br_freq_pq.push(make_pair(p.second, p.first));
  }

  vector<double> letter_freq(ALPHA_SIZE, 0);
  size_t text_size = 0;
  for(size_t i=0;i<str.size();i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      letter_freq[str[i] - 'a']++;
      text_size++;
    }
  }
  map<char, char> new_alpha;
  priority_queue<pair<double, char>> new_alpha_pq;
  for(int i=0;i<ALPHA_SIZE;i++){
    letter_freq[i] = (letter_freq[i]/text_size)*100;
    new_alpha_pq.push(make_pair(letter_freq[i], i+'a'));
  }

  cout << "Análise inicial dos alfabetos: \n";
  while(!pt_br_freq_pq.empty() && !new_alpha_pq.empty()){
    new_alpha[new_alpha_pq.top().second] = pt_br_freq_pq.top().second;
    cout << "(" << pt_br_freq_pq.top().second << ", " << 
    pt_br_freq_pq.top().first << "%) (" << new_alpha_pq.top().second << 
    ", " << new_alpha_pq.top().first << "%) \n";
    new_alpha_pq.pop();
    pt_br_freq_pq.pop();
  }

  string decripted = "";
  for(char c : str){
    if(c >= 'a' && c <= 'z'){
      c = new_alpha[c];
    }
    decripted += c;
  }
  return decripted;
}