#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> two_sum(vector<int> &nums, int target, int i)
{
	vector<vector<int>> result;

	int left = i, right = nums.size() - 1;

	while(left < right)
	{
		if(nums[left] + nums[right] == target)
		{
			result.push_back({nums[left++], nums[right--]});

			while(left < right && nums[left - 1] == nums[left]) left++;
			while(left < right && nums[right] == nums[right + 1]) right--;

			continue;
		}

		if(nums[left] + nums[right] < target) left++;
		else right--;
	}

	return result;
}

vector<vector<int>> k_sum(vector<int> &nums, int target, int i, int k)
{
	if(i == nums.size()) return {};
	if(target / k < nums[i] || nums.back() < target / k) return {};
	if(k == 2) return two_sum(nums, target, i);

	vector<vector<int>> output;
	for(int j = i; j < nums.size(); j++)
	{
		if(j != i && nums[j - 1] == nums[j]) continue;

		vector<vector<int>> result = k_sum(nums, target - nums[j], j + 1, k - 1);
		for(auto &vec : result)
		{
			vec.insert(vec.begin(), nums[j]);
			output.push_back(vec);
		}
	}

	return output;
}

vector<vector<int>> four_sum(vector<int> &nums, int target)
{
	sort(nums.begin(), nums.end());

	return k_sum(nums, target, 0, 4);
}

int main()
{
	vector<int> nums{0};
	int target = 0;

	vector<vector<int>> result = four_sum(nums, target);

	for(auto vec : result)
	{
		for(auto i : vec)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}