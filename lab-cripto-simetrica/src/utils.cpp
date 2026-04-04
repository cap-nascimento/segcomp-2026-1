#include "utils.h"

string read_input_file(string filename){
  ifstream ReadFileByName(filename);
  string line, output = "";
  while(getline (ReadFileByName, line)){
    output += (line + SEPARATOR);
  }
  ReadFileByName.close();
  return output;
}

string clear_input(string str){
	string res = "";
	for(size_t i=0;i<str.size();i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		}else if(str[i] < 'a' || str[i] > 'z'){
      str[i] = SEPARATOR;
    }
    res += str[i];
	}
	return res;
}

vector<string> dict_pt_br(){
  ifstream ReadFileByName("../dict_pt_br.txt");
  string line;
  vector<string> dict;
  while(getline (ReadFileByName, line)){
    dict.push_back(line);
  }
  ReadFileByName.close();
  return dict;
}