#include "transposition.h"

vector<string> create_table(int rows, int cols, string str){
  vector<string> table(rows, "");
  int jj = 0, k = 0;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(jj >= str.size()){
        table[i] += ALPHABET[k];
        k = (k + 1)%ALPHA_SIZE;
      }else{
        table[i] += str[jj];
        jj++;
      }
    }
  }
  return table;
}

vector<int> insert_key(int cols){
  vector<int> k(cols);
  bool loop = true;
  while(loop){
    cout << "Insira a chave (ordem das colunas): ";
    vector<int> check(cols, 0);
    bool err = false;
    for(size_t i=0;i<cols;i++){
      cin >> k[i];
      if(k[i] >= 1 && k[i] <= cols){
        check[k[i]-1]++;
      } else {
        err = true;
      }
      if(check[k[i]-1] >= 2) {
        err = true;
      }
    }
    for(int col : check){
      if(col != 1) {
        cout << "\n***** ERRO NA CHAVE! VERIFIQUE OS NÚMEROS. *****\n\n"; 
        err = true;
        break;
      }
    }
    loop = err;
  }
  return k;
}

string transposition_encrypt(int rows, int cols, vector<int> key, string str){
  vector<string> table = create_table(rows, cols, str);
  map<int, string> transposed;
  for(int i=0;i<cols;i++){
    for(int j=0;j<rows;j++){
      transposed[key[i]] += table[j][i];
    }
  }
  string result = "";
  for(int i=0;i<cols;i++){
    result += transposed[i+1];
  }
  return result;
}

string transposition_decrypt(int rows, int cols, vector<int> key, string str){
  vector<string> table = create_table(rows, cols, str);
  map<int, string> transposed;
  for(int i=0;i<rows;i++){
    transposed[i+1] = table[key[i]-1];
  }
  string result = "";
  for(int i=0;i<cols;i++){
    for(int j=0;j<rows;j++){
      result += transposed[j+1][i];
    }
  }
  return result;
}