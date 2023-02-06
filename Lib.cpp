#include "Lib.h"

unsigned int len(string str) 
{
	return (unsigned int)str.length();
}

vector<string> split(string str, char separator) 
{
	
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

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));

	return y;
}