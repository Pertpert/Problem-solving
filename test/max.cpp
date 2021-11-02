#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a = 11, b = 0, c = 1;
	vector<int> vec{a, b, c};

	// auto it = *max_element(vec.begin(), vec.end());

	cout << *max_element(vec.begin(), vec.end()) << endl;

	return 0;
}