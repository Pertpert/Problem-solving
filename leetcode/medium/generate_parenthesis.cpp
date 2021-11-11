#include <iostream>
#include <vector>

using namespace std;

vector<string> generate_parenthesis(int n)
{
	if(n == 0) return {""};

	vector<string> result;
	for(int i = 0; i < n; i++)
	{
		vector<string> left_parenthesis = generate_parenthesis(i);
		vector<string> right_parenthesis = generate_parenthesis(n - 1 - i);
		for(string left : left_parenthesis)
			for(string right : right_parenthesis)
				result.push_back('(' + left + ')' + right);
	}

	return result;
}

int main()
{
	int n = 4;

	vector<string> result = generate_parenthesis(n);
	for(string str : result)
		cout << str << ' ';
	cout << '\n';

	return 0;
}