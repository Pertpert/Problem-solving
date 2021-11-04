#include <iostream>

using namespace std;

string int_to_roman(int num) {
	int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	
	string output = "";
	
	int i = 12;
	while(i >= 0)
	{
		if(num >= val[i]) output += symbol[i], num -= val[i];
		else i--;
	}
	
	return output;
}

int main()
{
	int num = 1234;

	cout << int_to_roman(num) + '\n';

	return 0;
}