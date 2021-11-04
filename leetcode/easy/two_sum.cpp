#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target)
{
	map<int, int> data;

	for(int i = 0; i < nums.size(); i++)
	{
		if(data.find(target - nums[i]) != data.end())
			return {data[target - nums[i]], i};

		data[nums[i]] = i;
	}

	return {-1, -1};
}

int main()
{
	vector<int> nums{2, 7, 11, 15};
	int target = 9;

	vector<int> result = two_sum(nums, target);

	for(int idx : result)
		cout << idx << ' ';
	cout << '\n';

	return 0;
}