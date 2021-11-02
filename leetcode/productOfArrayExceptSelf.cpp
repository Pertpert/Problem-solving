#include <iostream>
#include <vector>

using namespace std;

/*int * productOfArrayExceptSelf(int *array, int size)
{
	int *result = (int *)malloc(size * sizeof(int));

	int forward[size] = {1};
	int backward[size];
	backward[size - 1] = 1;

	for(int i = 1; i < size; i++)
	{
		forward[i] = forward[i - 1] * array[i - 1];
		backward[size - 1- i] = backward[size - i] * array[size - i];
	}

	for(int i = 0; i < size; i++)
		result[i] = forward[i] * backward[i];

	return result;
}*/

vector<int> productExceptSelf(vector<int>& nums)
{
	vector<int> result(nums.size(), 1);

	for(int i = 1; i < nums.size(); i++)
		result[i] = result[i - 1] * nums[i - 1];

	int product = 1;
	for(int i = nums.size() - 1; i >= 0; i--)
	{
		result[i] = result[i] * product;
		product *= nums[i];
	}
	return result;
}

int main()
{
	vector<int> array{1, 2, 3, 4};

	// int size = sizeof(array) / sizeof(array[0]);

	// int *result = productOfArrayExceptSelf(array, size);

	vector<int> result = productExceptSelf(array);
	
	for(int i = 0; i < array.size(); i++)
		cout << result[i] << " ";
	cout << '\n';

	return 0;
}