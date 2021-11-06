#include <iostream>
#include <vector>

using namespace std;

string longest_common_prefix(vector<string> &strs)
{
	string common_prefix = "";

	for(int i = 0; i < strs[0].size(); i++)
	{
		char c = strs[0].at(i);

		for(int j = 1; j < strs.size(); j++)
			if(i >= strs[j].size() || strs[0].at(i) != strs[j].at(i))
				return common_prefix;

		common_prefix += strs[0].at(i);
	}

	return common_prefix;
}

int main()
{
	vector<string> strs{"flower", "flow", "flight"};

	cout << longest_common_prefix(strs) + '\n';

	return 0;
}