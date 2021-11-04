#include <iostream>
#include <cmath>

using namespace std;

int expandPalindrom(string word, int left, int right)
{
	while(left >= 0 && right < word.size() && word[left] == word[right])
	{
		left--;
		right++;
	}

	return right - left - 1;
}

int longestPalindrom(string word)
{
	int max_len = 0;

	for(int i = 0; i < word.size(); i++)
		max_len = max(max_len, max(expandPalindrom(word, i, i), expandPalindrom(word, i, i + 1)));

	return max_len;
}

int main()
{
	string word = "abc";

	// int max = 0;
	// for(int i = 0; i < word.size(); i++)
	// {
	// 	for(int j = i; j < word.size(); j++)
	// 	{
	// 		string subword = word.substr(i, j - i + 1);
	// 		bool isPalindrom = true;
	// 		for(int p = 0; p < subword.size(); p++)
	// 			if(subword[p] != subword[subword.size()- 1 - p])
	// 				isPalindrom = false;

	// 		if(isPalindrom && max < subword.size())
	// 			max = subword.size();
	// 	}
	// }

	cout << longestPalindrom(word) << endl;

	return 0;
}