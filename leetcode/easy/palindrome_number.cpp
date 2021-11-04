#include <iostream>

using namespace std;

bool is_palindrome(int x)
{
	if(0 > x)
		return false;

	int _x = x;
	long reverse_x = 0;

	while(_x)
	{
		reverse_x *= 10 + _x % 10;

		if(INT32_MAX <= reverse_x)
			return false;

		_x /= 10;
	}

	cout << reverse_x << endl;

	return x == reverse_x;
}

int main()
{
	int x = 121;

	cout << (is_palindrome(x) ? "yes" : "no") << '\n';

	return 0;
}