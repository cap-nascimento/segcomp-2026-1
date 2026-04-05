#include "vigenere.h"

string vigenere_encrypt(string str, string key){
  size_t j = 0;
  for(size_t i=0;i<str.size();i++){
    if(str[i] != SEPARATOR){
      int c = str[i] - 'a';
      int k = (key[j%key.size()] - 'a')+1;
      c = (c + k)%ALPHA_SIZE;
      str[i] = c + 'a';
      j++;
    }
  }
  return str;
}

string vigenere_decrypt(string str, string key){
  size_t j = 0;
  for(size_t i=0;i<str.size();i++){
    if(str[i] != SEPARATOR){
      int c = str[i] - 'a';
      int k = (key[j%key.size()] - 'a')+1;
      c = (c - k);
      if(c < 0) c += ALPHA_SIZE;
      str[i] = c + 'a';
      j++;
    }
  }
  return str;
}

string generate_random_key(){
  string current_alpha = ALPHABET;
  string result = ALPHABET;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(1, ALPHA_SIZE);

  for(int i=0;i<ALPHA_SIZE;i++){
    int curr = distr(gen);
    swap(current_alpha[curr-1], current_alpha[ALPHA_SIZE-curr]);
  }
  
  int iterations = distr(gen);

  do{
    result = current_alpha;
    iterations--;
  }while(next_permutation(current_alpha.begin(), current_alpha.end()) && iterations > 0);
  return result;
}