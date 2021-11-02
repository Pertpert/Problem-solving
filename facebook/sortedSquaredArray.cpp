#include <iostream>

using namespace std;

int * sortedSquaredArray(int * array, int size)
{
	int * output = (int * )malloc(size * sizeof(int));

	int left = 0, right = size - 1;
	for(int i = size - 1; i >= 0; i--)
		output[i] = abs(array[left]) >= array[right] ? array[left] * array[left++] : array[right] * array[right--];

	return output;
}

void print(int * arr, int size)
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << '\n';
}

int main()
{
	int array[] = {-7, -3, -1, 4, 8, 12};
	int size = sizeof(array) / sizeof(array[0]);

	print(array, size);
	print(sortedSquaredArray(array, size), size);

	return 0;
}