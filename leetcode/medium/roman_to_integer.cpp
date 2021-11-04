#include <iostream>

using namespace std;

int roman_to_integer(string &s)
{
	int table[26] = {0};
	table['I' - 'A'] = 1;
	table['V' - 'A'] = 5;
	table['X' - 'A'] = 10;
	table['L' - 'A'] = 50;
	table['C' - 'A'] = 100;
	table['D' - 'A'] = 500;
	table['M' - 'A'] = 1000;

	int output = 0;
	for(int i = 0; i < s.size(); i++)
		if(i + 1 < s.size() and table[s[i] - 'A'] < table[s[i + 1] - 'A'])
			output += table[s[i + 1] - 'A'] - table[s[i] - 'A'];
		else
			output += table[s[i] - 'A'];
	return output;
}

int main()
{
	string s = "III";

	cout << roman_to_integer(s) << '\n';

	return 0;
}