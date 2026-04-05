#ifndef CESAR_H
#define CESAR_H

// Tamanho do alfabeto de referência
#define ALPHA_SIZE 26

#include "utils.h"

/*
  Encriptação de César
  str = texto claro
  key = deslocamento
*/
string cesar_encrypt(string str, int key);

/*
  Decriptação de César
  str = texto cifrado
  key = deslocamento
*/
string cesar_decrypt(string str, int key);

/*
  Decriptação via força bruta (consulta em dicionário)
  str = texto cifrado
  dict = dicionário com 245366 palavras em português
*/
void brute_force_cesar_decrypt(string str, vector<string> dict);

/*
  Decriptação via análise de frequência
  str = texto cifrado
*/
string auto_cesar_decrypt(string str);

#endif
