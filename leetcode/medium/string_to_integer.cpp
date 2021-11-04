#include <iostream>
#include <climits>

using namespace std;


int my_atoi(string input)
{
	string number = "0";
	bool seen = false;
	bool is_positive = true;
	long output = 0;
	for(int i = 0; i < input.size(); i++)
	{
		if(    'a' <= input[i] && input[i] <= 'z'
			|| 'A' <= input[i] && input[i] <= 'Z'
			|| input[i] == '.'
			|| ((number.size() > 1 || seen) && (input[i] == '+' || input[i] == '-' || input[i] == ' '))
			|| (number.size() != 1 && input[i] == ' '))
		{
			if(number.size() == 1)
				return 0;
			else
				break;
		}

		if(input[i] == '+' || input[i] == '-')
		{
			seen = true;
			is_positive = input[i] == '+' ? true : false;
		}

		if('0' <= input[i] && input[i] <= '9')
		{
			number += input[i];
			
			output = stol(number) * (is_positive ? 1 : -1);
			if(output < INT32_MIN || output > INT32_MAX)
			{
				output = output <= INT32_MIN ? INT32_MIN : INT32_MAX;
				break;
			}
		}
	}

	return output;
}

int main()
{
	string input = "4193 with words";

	cout << my_atoi(input) << '\n';

	return 0;
}	