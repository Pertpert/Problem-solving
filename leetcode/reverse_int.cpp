#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int reverse(int x) {
	bool is_positive = 0 <= x;
	int clone_x = abs(x);
	int reversed_x = 0;

	while(clone_x)
	{
		reversed_x = reversed_x * 10 + clone_x % 10;
		clone_x /= 10;

		if(INT32_MAX < reversed_x)
			return 0;
	}

	return is_positive ? reversed_x : -reversed_x;


	// bool is_positive = 0 <= x;
	// string strx = to_string(abs(x));
	// std::reverse(strx.begin(), strx.end());

	// if(INT32_MAX < stoll(strx))
	// 	return 0;
	
	// return stoi(is_positive ? strx : "-" + strx);
}

int main()
{
	int x = -123;
	cout << reverse(x) << endl;

	return 0;
}