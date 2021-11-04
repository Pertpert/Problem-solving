#include <iostream>

using namespace std;

/*string*/ int reduce_string(string &s)
{
	string output = "";

	s += '0';
	int count = 1;
	
	int result = 0;
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i - 1] != s[i])
		{
			if(count % 2) 
			{
				output += s[i - 1];
				result++;
			}

			count = 1;
		}
		else count++;
	}

	// return output;
	return result;
}

int main()
{
	string s = "aa";

	cout << reduce_string(s) << '\n';

	return 0;
}