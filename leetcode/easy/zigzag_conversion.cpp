#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convert(string word, int num_rows)
{
	if(num_rows == 1)
		return word;

	string output = "";
	int step = 2 * (num_rows - 1);
	for(int row = 0, idx; row < num_rows; row++)
	{
		for(int i = row; i < word.size(); i += step)
		{
			output += word[i];

			if(row > 0 && row < num_rows - 1 && i + step - 2 * row < word.size())
				output += word[i + step - 2 * row];
		}
	}

	return output;
}

int main()
{
	string word = "AB";
	int num_rows = 1;

	cout << convert(word, num_rows) << '\n';

	return 0;
}