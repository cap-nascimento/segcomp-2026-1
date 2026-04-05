#ifndef VIGENERE_H
#define VIGENERE_H
#define ALPHA_SIZE 26
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

#include "utils.h"

string vigenere_encrypt(string str, string key);
string vigenere_decrypt(string str, string key);
string generate_random_key();

#endif