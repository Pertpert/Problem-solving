#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
	return a[0] <= b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
	sort(intervals.begin(), intervals.end(), compare);

	vector<vector<int>> output_vec;
	vector<int> &current_interval = intervals[0];
	intervals.push_back({INT_MAX, INT_MAX});

	for(auto interval : intervals)
	{
		if(current_interval[1] >= interval[0])
		{
			current_interval[1] = max(current_interval[1], interval[1]);
		}
		else
		{
			output_vec.push_back(current_interval);
			current_interval = interval;
		}
	}

	return output_vec;
}

int main()
{
	vector<vector<int>> input{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

	vector<vector<int>> output = mergeIntervals(input);

	for(auto vec : output)
	{
		for(auto val : vec)
			cout << val << ' ';
		cout << '\n';
	}

	return 0;
}