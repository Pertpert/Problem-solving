#include <iostream>
#include <climits>

using namespace std;


int main(int argc, char * argv[])
{
	if(!(1 < argc && argc < 3))
		return 0;

	int N = atoi(argv[1]);

	int coin[] = {1, 2, 4};
	int size = sizeof(coin) / sizeof(coin[0]);

	int value[N + 1] = {0};
	int choice[N + 1] = {0};

	for(int i = 1; i <= N; i++)
	{
		value[i] = INT_MAX;

		for(int j : coin)
			if(i - j >= 0 && value[i - j] + 1 < value[i])
			{
				value[i] = value[i - j] + 1;
				choice[i] = j;
			}
	}

	cout << value[N] << '\n';

	while(N > 0)
	{
		cout << choice[N] << ' ';
		N -= choice[N];
	}
	cout << '\n';

	return 0;
}