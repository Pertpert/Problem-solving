#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_area(vector<int> &height)
{
	int output = 0;
	
	int left = 0, right = height.size() - 1;
	while(left < right)
	{
		output = max(output, min(height[left], height[right]) * (right - left));

		height[left] < height[right] ? left++ : right--;
	}

	return output;
}

int main()
{
	vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};

	cout << max_area(input) << '\n';

	return 0;
}