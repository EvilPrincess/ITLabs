#include "Lib.h"

using namespace strf;
using namespace SpecialFunctionsForLabs;
using namespace arrf;

unsigned int strf::len(string str) 
{
	return (unsigned int)str.length();
}
vector<string> strf::split(string str, char separator) 
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
int randi(int low, int high)
{
	return (low == NULL && high == NULL ? rand()-16383 : low + rand() % (high - low + 1));
}
double randf(double low, double high, int precision) {
	double value = rand() % (int)pow(10, precision);
	return (low==NULL && high == NULL? value / pow(10, precision) + rand() - 16383 : low + (value / pow(10, precision)) * (high - low));
}

bool SpecialFunctionsForLabs::is_int(string str)
{
	char availables[]{'-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	for (char c : str) {
		if (find(begin(availables), end(availables), c) == end(availables)) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_float(string str)
{
	char availables[]{ '-', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	if (count(str.begin(), str.end(), '-') > 0 && str[0] != '-') return false;
	if (count(str.begin(), str.end(), '-') > 1) return false;

	if (count(str.begin(), str.end(), '.') > 1) return false;
	if (count(str.begin(), str.end(), '.') > 0 && (str[0] == '.' || str[0] == '-' && str[1] == '.' || str.back() == '.')) return false;

	for (char c : str) {
		if (find(begin(availables), end(availables), c) == end(availables)) return false;
	}

	return true;
}
bool SpecialFunctionsForLabs::is_natural(string str)
{
	char availables[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	if (!is_int(str) || stoi(str) < 1) return false;

	return true;
}
double SpecialFunctionsForLabs::round(double value, unsigned int precision)
{
	double k = pow(10, precision);
	return (int)(value * k + 0.5) / k;
}
bool SpecialFunctionsForLabs::is_char(string str)
{
	if (len(str) == 1) return true;
	return false;
}

