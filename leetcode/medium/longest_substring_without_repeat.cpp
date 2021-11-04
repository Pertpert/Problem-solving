#include <iostream>

using namespace std;

int length_of_longest_substring(string &s)
{
	int result = 0;

	int container[128] = {0};

	for(int i = 0, j = 0; i < s.size(); i++)
	{
		if(container[s[i]])
			j = max(container[s[i]], j);

		result = max(result, i - j + 1);
		container[s[i]] = i + 1;
	}

	cout << '\n';

	return result;
}

int main()
{
	string s = "pwwkew";

	cout << length_of_longest_substring(s) << '\n';

	return 0;

}