#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int remove_duplicates(vector<int> &nums)
{
	return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

int main()
{
	vector<int> nums{1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};

	int n = remove_duplicates(nums);
	for(int i = 0; i < n; i++)
		cout << nums[i] << ' ';
	cout << '\n';

	return 0;
}