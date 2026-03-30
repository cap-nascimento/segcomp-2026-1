#include <bits/stdc++.h>
using namespace std;

string clear_string(string s){
	string res = "";
	for(size_t i=0;i<s.size();i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] += 32;
		}
		if(s[i] != ' ') res += s[i];
	}
	return res;
}

string enc(string s, int k){
	k%=26;
	for(size_t i=0;i<s.size();i++){
		int c = s[i] - 'a';
		c = (c+k)%26;
		s[i] = c + 'a';
	}
	return s;
}

string dec(string s, int k){
	k%=26;
	for(size_t i=0;i<s.size();i++){
		int c = s[i] - 'a';
		c -= k;
		if (c < 0) c += 26;
		s[i] = c + 'a';
	}
	return s;
}

int main(){

	string s;
	cin >> s;
	int k;
	cin >> k;

	//  criptografando e descriptografando a entrada
	cout << "Criptografando e descriptografando a entrada." << endl;
	cout << enc(clear_string(s), 3) << endl;
	cout << dec(enc(clear_string(s), 3), 3) << endl;

	// testando 26 chaves
	cout << "Testando as chaves" << endl;
	string enc_s = enc(clear_string(s), 3);
	for(int i=1;i<=26;i++){
		cout << "chave " << i << " " << dec(enc_s, i) << endl;
	}

}
