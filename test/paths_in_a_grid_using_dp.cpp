#include <iostream>

using namespace std;

int main()
{
	int N = 5;
	int grid[N][N] = {
		{3, 7, 9, 2, 7},
		{9, 8, 3, 5, 5},
		{1, 7, 9, 8, 5},
		{3, 8, 6, 4, 10},
		{6, 3, 9, 7, 8}
	};

	int sum[N + 1][N + 1];

	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= N; j++)
			sum[i][j] = 0;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			sum[i + 1][j + 1] = max(sum[i + 1 - 1][j + 1], sum[i + 1][j + 1 - 1]) + grid[i][j];

	cout << sum[N][N] << '\n';

	return 0;
}