#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string longest_word_in_dictionary(vector<string> &words)
{
	sort(words.begin(), words.end());

	unordered_set<string> data;
	string output = "";


	for(string& word : words)
	{
		if(word.size() == 1 || data.find(word.substr(0, word.size() - 1)) != data.end())
		{
			if(output.size() < word.size())
				output = word;

			data.insert(word);
		}
	}

	return output;
}

int main()
{
	vector<string> words = {"w","wo","wor","worl","world"};

	cout << longest_word_in_dictionary(words) << '\n';

	return 0;
}