#include <iostream>

using namespace std;

int main()
{
	int array[] = {6, 2, 5, 1, 7, 4, 8, 3};
	int size = sizeof(array) / sizeof(array[0]);
	int length[size] = {0};

	int max_length = 0;
	for(int i = 0; i < size; i++)
	{
		length[i] = 1;

		for(int j = 0; j < i; j++)
			if(array[j] < array[i])
			{
				length[i] = max(length[i], length[j] + 1);
				max_length = max(max_length, length[i]);
			}
	}

	cout << max_length << endl;

	return 0;
}