#include <iostream>

using namespace std;

int binarySearch(int * array, int left, int right, int target)
{
	if(left > right)
		return -1;

	int middle = left + (right - left) / 2;
	
	if(target == array[middle])
		return middle;
	else if(target < array[middle])
		return binarySearch(array, left, middle, target);
	else
		return binarySearch(array, middle + 1, right, target);
}


/*
int searchRotatedArray(int * array, int size, int target)
{
	int pivot = 0;
	for(int i = 0; i < size - 1; i++)
		if(array[i] > array[i + 1])
			pivot = i + 1;

	if(target <= array[size - 1])
		return binarySearch(array, pivot, size - 1, target);
	else
		return binarySearch(array, 0, pivot == 0 ? size - 1 : (pivot - 1), target);
}
*/

int main()
{
	int array[] = {3, 4, 5, 6, 7, 0, 1, 2};
	int size = sizeof(array) / sizeof(array[0]);
	int target = 2;

	// cout << searchRotatedArray(array, size, target) << '\n';

	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		int midpoint = left + (right - left) / 2;

		if(array[midpoint] > array[right])
			left = midpoint + 1;
		else
			right = midpoint;
	}

	cout << array[left] << '\n';

	cout << left << ' ' << right << '\n';

	if(target <= array[size - 1])
		right = size - 1;
	else
	{
		left = 0;
		right--;
	}

	cout << binarySearch(array, left, right, target) << '\n';

	return 0;
}