#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> three_sum(vector<int> &nums)
{
	if(nums.size() < 3) return {};

	sort(nums.begin(), nums.end());

	vector<vector<int>> output;
	
	for(int i = 0; i < nums.size() - 2; i++)
	{
		if(i != 0 && nums[i - 1] == nums[i]) continue;

		int l = i + 1, r = nums.size() - 1;

		while(l < r)
		{
			if(nums[i] + nums[l] + nums[r] == 0)
			{
				output.push_back({nums[i], nums[l++], nums[r--]});

				while(l < r && nums[l - 1] == nums[l]) l++;
				while(l < r && nums[r] == nums[r + 1]) r--;
			}
			else if(nums[i] + nums[l] + nums[r] > 0) r--;
			else l++;
		}
	}

	return output;
}

int main()
{
	vector<int> nums{-1, 0, 1, 2, -1, -4};

	vector<vector<int>> output = three_sum(nums);

	for(auto vec : output)
	{
		cout << '[';
		for(auto i : vec)
			cout << i << ' ';
		cout << "]\n";
	}

	return 0;
}