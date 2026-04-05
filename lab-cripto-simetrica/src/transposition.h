#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H
#define ALPHA_SIZE 26
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

#include "utils.h"

string transposition_encrypt(int rows, int cols, vector<int> key, string str);
string transposition_decrypt(int rows, int cols, vector<int> key, string str);
vector<int> insert_key(int cols);

#endif