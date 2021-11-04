#include <iostream>

using namespace std;

void findAllDuplicates(int * array, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(array[abs(array[i]) - 1] < 0)
			cout << abs(array[i]) << " ";
		
		array[abs(array[i]) - 1] *= -1;
	}

	cout << '\n';
}

int main()
{
	int array[] = {4, 3, 2, 7, 8, 2, 3, 1};
	int size = sizeof(array) / sizeof(array[0]);

	findAllDuplicates(array, size);

	return 0;
}