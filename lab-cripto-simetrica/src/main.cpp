#include "utils.h"
#include "cesar.h"
#include "vigenere.h"
#include "transposition.h"

int menu(){
  cout << "================== Laboratório de Criptografia Simétrica ==================\n\n";
  cout << "Escolha uma opção:\n";
  cout << "1 - Cifra de César;\n";
  cout << "2 - Decifrar a cifra de César com brute force;\n";
  cout << "3 - Tentar decifrar com análise de frequência;\n";
  cout << "4 - Cifra de Vigenère;\n";
  cout << "5 - Permutação do alfabeto como chave;\n";
  cout << "6 - Cifra de transposição de colunas;\n";
  cout << "7 - Transposições sucessivas;\n";
  cout << "Qualquer outra coisa - Sair.\n";
  int option = -1;
  cin >> option;
  return option;
}

void about_input_msg(){
  cout << "O texto utilizado está no arquivo \"input_text.txt\".\n";
  cout << "Edite-o para testar outras entradas.\n\n";
}

void parte_1(string s){
  string enc_s;
  int k;
  cout << "================== Parte 1 - Caesar Cipher ==================\n";
  about_input_msg();
  cout << "Insira a chave (deslocamento): ";
  cin >> k;
  
  enc_s = cesar_encrypt(s, k);
  cout << "Entrada criptografada:\n\n";
  cout << enc_s << "\n\n";
  cout << "Entrada descriptografada:\n\n";
  cout << cesar_decrypt(enc_s, k) << "\n\n";
}

void parte_2(string s, vector<string> dict){
  string enc_s;
  int k;
  cout << "================== Parte 2 - Caesar Brute Force Decrypt ==================\n";
  about_input_msg();
  cout << "Insira a chave (deslocamento): ";
  cin >> k;

  cout << "Criptografando a entrada com o deslocamento " << k << "...\n\n";
  enc_s = cesar_encrypt(s, k);
  brute_force_cesar_decrypt(enc_s, dict);
}

void parte_3(string s){
  string enc_s;
  int k;
  cout << "================== Parte 3 - Caesar Auto Decrypt ==================\n";
  about_input_msg();
  cout << "Insira a chave (deslocamento): ";
  cin >> k;

  enc_s = cesar_encrypt(s, k);
  cout << "Entrada criptografada:\n\n";
  cout << enc_s << "\n\n";
  cout << "Descriptografando por análise de frequência...\n\n";
  string auto_dec_s = auto_cesar_decrypt(enc_s);
  cout << "\nResultado:\n\n" << auto_dec_s << "\n\n";
}

void parte_4(string s){
  string enc_s, k;
  cout << "================== Parte 4 - Vigenère Cipher ==================\n";
  about_input_msg();
  cout << "Insira a chave (palavra): ";
  cin >> k;

  enc_s = vigenere_encrypt(s, k);
  cout << "Entrada criptografada:\n\n";
  cout << enc_s << "\n\n";
  cout << "Entrada descriptografada:\n\n";
  cout << vigenere_decrypt(enc_s, k) << "\n\n";
}

void parte_5(string s){
  string enc_s, k;
  cout << "================== Parte 5 - Vigenère Cipher w/ Random Key ==================\n";
  about_input_msg();
  k = generate_random_key();
  cout << "Chave gerada: \"" << k <<"\"\n\n";

  enc_s = vigenere_encrypt(s, k);
  cout << "Entrada criptografada:\n\n";
  cout << enc_s << "\n\n";
  cout << "Entrada descriptografada:\n\n";
  cout << vigenere_decrypt(enc_s, k) << "\n\n";
}

void parte_6(string s){
  string new_s, enc_s;
  size_t cols, rows;

  for(char c : s) if (c != SEPARATOR) new_s += c;
  cout << "================== Parte 6 - Transposition Cipher ==================\n";
  about_input_msg();
  
  cout << "Quantas colunas? (min. 1, max. " << new_s.size() << ") ";
  cin >> cols;
  if(cols < 1 ) cols = 1;
  if(cols > new_s.size()) cols = new_s.size();
  rows = ceil((double)new_s.size()/cols);

  vector<int> k = insert_key(cols);

  enc_s = transposition_encrypt(rows, cols, k, new_s);
  cout << "\nEntrada criptografada:\n\n";
  cout << enc_s << "\n\n";
  cout << "Entrada descriptografada:\n\n";
  cout << transposition_decrypt(cols, rows, k, enc_s) << "\n\n";
}

void parte_7(string s){
  string new_s, enc_s;
  size_t cols, rows;

  for(char c : s) if (c != SEPARATOR) new_s += c;
  cout << "================== Parte 7 - Transposition Cipher, Two Times, Two Keys ==================\n";
  about_input_msg();
  
  cout << "Quantas colunas? (min. 1, max. " << new_s.size() << ") ";
  cin >> cols;
  if(cols < 1 ) cols = 1;
  if(cols > new_s.size()) cols = new_s.size();
  rows = ceil((double)new_s.size()/cols);

  vector<int> k1 = insert_key(cols);
  enc_s = transposition_encrypt(rows, cols, k1, new_s);
  cout << "\nEntrada criptografada 1 vez:\n\n";
  cout << enc_s << "\n\n";

  vector<int> k2 = insert_key(cols);
  enc_s = transposition_encrypt(rows, cols, k2, enc_s);
  cout << "\nEntrada criptografada 2 vezes:\n\n";
  cout << enc_s << "\n\n";

  string dec_s = transposition_decrypt(cols, rows, k2, enc_s);
  cout << "Entrada descriptografada 1 vez:\n\n";
  cout << dec_s << "\n\n";

  dec_s = transposition_decrypt(cols, rows, k1, dec_s);
  cout << "Entrada descriptografada 2 vezes:\n\n";
  cout << dec_s << "\n\n";
}

int main(){

  vector<string> dict = dict_pt_br();
  sort(dict.begin(), dict.end());
  bool loop = true;
  while(loop){
    string s = clear_input(read_input_file("../input_text.txt"));
    int option = menu();
    switch(option){
      case 1:
        parte_1(s);
        break;
      case 2:
        parte_2(s, dict);
        break;
      case 3:
        parte_3(s);
        break;
      case 4:
        parte_4(s);
        break;
      case 5:
        parte_5(s);
        break;
      case 6:
        parte_6(s);
        break;
      case 7:
        parte_7(s);
        break;
      default:
        loop = false;
        break;
    }
  }

  return 0;
}
