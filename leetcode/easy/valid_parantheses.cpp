#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValid(string str)
{
	map<char, char> m{
		{'(', ')'},
		{'[', ']'},
		{'{', '}'}
	};

	vector<char> stack;

	for(char c : str)
	{
		if(!stack.empty() && m[stack.back()] == c)
			stack.pop_back();
		else
			stack.push_back(c);
	}

	return stack.empty();
}

int main()
{
	string str = "()";

	cout << (isValid(str) ? "true" : "no") << endl;

	return 0;
}