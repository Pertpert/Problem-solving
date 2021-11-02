#include <iostream>

using namespace std;

int * findFirstAndLastPosition(int *array, int size, int target)
{
	int *result = (int *)malloc(2 * sizeof(int));

	int left = 0, right = size - 1;
	while(left <= right)
	{
		int midpoint = left + (right - left) / 2;

		if(array[midpoint] == target)
		{
			int l = midpoint - 1, r = midpoint + 1;
			
			while((l >= 0 && r < size) && (array[l] == target || array[r] == target))
			{
				if(l >=0 && array[l] == target)
					l--;
				if(r < size && array[r] == target)
					r++;
			}

			result[0] = l + 1;
			result[1] = r - 1;

			return result;
		}
		else if(array[midpoint] < target)
			left = midpoint + 1;
		else
			right = midpoint - 1;
	}

	result[0] = result[1] = -1;

	return result;
}

int main()
{
	int nums[] = {1};
	int size = sizeof(nums) / sizeof(nums[0]);
	int target = 1;

	int *result = findFirstAndLastPosition(nums, size, target);
	cout << result[0] << " " << result[1] << endl;

	return 0;
}