#include "Lib.h"

unsigned int len(string str) {
	return str.length();
}

vector<string> split(string str, char separator) {
	
	vector<string> vec = { };

	string substr = "";

	for (unsigned int i = 0; i < len(str); i++) {
		if (str[i] == separator)
			if (substr == "") continue;
			else {
				vec.push_back(substr);
				substr = "";
				continue;
			}
		else if (i == len(str) - 1) {
			substr += str[i];
			vec.push_back(substr);
			continue;
		}
		substr += str[i];
	}

	return vec;
}