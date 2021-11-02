#include <iostream>
using namespace std;

int main()
{
	double d;
	cin >> d;
	int my_int(3.14);
	int my_int2 = static_cast<int>(d);
	cout << my_int << '\n';
	cout << my_int2 << '\n';


	return 0;
}
