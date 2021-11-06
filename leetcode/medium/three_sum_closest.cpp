#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int three_sum_closest(vector<int>& nums, const int &target) {
	sort(nums.begin(), nums.end());

	int closest = 100001;
	
	for(int i = 0; i < nums.size() - 2; i++)
	{
		int l = i + 1, r = nums.size() - 1;
	
		while(l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
	
			if(sum == target) return target;
	
			if(abs(target - closest) > abs(target - sum)) closest = sum;
	
			if(sum > target) r--;
			else l++;
		}
	}
	
	return closest;
}

int main()
{
	vector<int> nums{-1, 2, 1, -4};
	int target = 1;

	cout << three_sum_closest(nums, target) << endl;

	return 0;
}