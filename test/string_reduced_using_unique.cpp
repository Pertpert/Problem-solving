#include <iostream>
#include <algorithm>

using namespace std;

string string_reduce(string &str)
{
	return str.substr(0, distance(str.begin(), unique(str.begin(), str.end())));
}

int main()
{
	string str = "aabbbccc";

	cout << string_reduce(str) << '\n';

	return 0;
}