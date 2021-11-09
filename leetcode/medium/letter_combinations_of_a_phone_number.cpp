#include <iostream>
#include <vector>

using namespace std;

vector<string> alphabet{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> output;
string digit;

void backtrack(int i, string str)
{
	if(i == digit.size())
	{
		output.push_back(str);
		return;
	}

	for(char c : alphabet[digit[i] - '0' - 2])
		backtrack(i + 1, str + c);
}

vector<string> letter_combinations(string &digits)
{
	if(digits.empty()) return {};

	digit = digits;
	backtrack(0, "");

	return output;
}

int main()
{
	string digits = "23";

	vector<string> result = letter_combinations(digits);

	for(string str : result)
		cout << str << " ";
	cout << endl;w

	return 0;
}
