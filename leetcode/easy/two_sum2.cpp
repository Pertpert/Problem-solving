#include <iostream>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int> &nums, int target)
{
	int left = 0, right = nums.size() - 1;

	while(left < right)
	{
		if(nums[left] + nums[right] == target) return {left + 1, right + 1};

		if(nums[left] + nums[right] < target) left++;
		else right--;
	}

	return {0, 0};
}

int main()
{
	vector<int> nums{2, 7, 11, 15};
	int target = 9;

	vector<int> result = two_sum(nums, target);

	for(int i : result)
		cout << i << ' ';
	cout << '\n';

	return 0;
}