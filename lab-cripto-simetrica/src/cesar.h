#ifndef CESAR_H
#define CESAR_H
#define ALPHA_SIZE 26

#include "utils.h"

string cesar_encript(string str, int key);
string cesar_decript(string str, int key);
void brute_force_cesar_decript(string str, vector<string> dict);

#endif
