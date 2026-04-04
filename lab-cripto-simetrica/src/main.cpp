#include "utils.h"
#include "cesar.h"

int main(){

  vector<string> dict = dict_pt_br();
  sort(dict.begin(), dict.end());

  while(true){
    string s = read_input_file("../input_text.txt");
    int k;
    cout << "================== Parte 1 - Caesar Cipher ==================\n";
    cout << "O texto utilizado está no arquivo \"input_text.txt\".\n";
    cout << "Edite-o para testar outras entradas.\n\n";
    cout << "Insira a chave (deslocamento): ";
    cin >> k;
    
    cout << "Entrada criptografada:\n\n";
    cout << cesar_encript(clear_input(s), k) << "\n\n";
    cout << "Entrada descriptografada:\n\n";
    cout << cesar_decript(cesar_encript(clear_input(s), k), k) << "\n\n";

    cout << "================== Parte 2 - Caesar Brute Force Decrypt ==================\n";
    cout << "Criptografando a entrada com o deslocamento " << k << "...\n\n";
    string enc_s = cesar_encript(clear_input(s), k);
    brute_force_cesar_decript(enc_s, dict);

    cout << "================== Parte 3 - Caesar Auto Decrypt ==================\n";

    cout << "Deseja parar os testes? (y/n) ";
    string stop;
    cin >> stop;
    if (stop == "y" || stop == "Y" || stop == "yes") break;
  }

}
