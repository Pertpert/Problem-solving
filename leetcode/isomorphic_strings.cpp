#include <iostream>

using namespace std;

bool is_isomorpic(string &s, string &t)
{
	if(s.size() != t.size())
		return false;

	int s_to_t[128] = {0};
	int t_to_s[128] = {0};

	for(int i = 0; i < s.size(); i++)
	{
		if(!s_to_t[s[i]]) s_to_t[s[i]] = t[i];
		if(!t_to_s[t[i]]) t_to_s[t[i]] = s[i];
		if(s_to_t[s[i]] != t[i] || t_to_s[t[i]] != s[i]) return false;
	}

	return true;
}

int main()
{
	string s = "paper";
	string t = "title";

	cout << (is_isomorpic(s, t) ? "true" : "false") << '\n';

	return 0;
}