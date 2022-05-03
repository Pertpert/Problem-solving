#include <iostream>
#include <vector>

int coinProblem(const std::vector<int> &coins, int x) {
	if (x < 0) {
		return x + 1;
	} else if (x == 0) {
		return 0;
	}

	int minCoin = x + 1;

	for (int coin : coins) {
		minCoin = std::min(minCoin, coinProblem(coins, x - coin) + 1);
	}

	return minCoin;
}

int main(int argc, char **argv) {
	std::vector<int> coins{1, 3, 4};
	int x = 10;

	std::vector<int> cacheMin(x + 1);
	std::vector<int> first(x + 1);

	cacheMin[0] = 0;

	for (int i = 1; i < cacheMin.size(); i++) {
		cacheMin[i] = x + 1;

		for (int coin : coins) {
			if (0 <= i - coin && cacheMin[i - coin] + 1 < cacheMin[i]) {
				cacheMin[i] = cacheMin[i - coin] + 1;
				first[i] = coin;
			}
		}
	}

	// std::cout << coinProblem(coins, x) << '\n';
	// std::cout << cache[x] << '\n';

	for (int i = 0; i < cacheMin.size(); i++) {
		std::cout << i << ": " << cacheMin[i] << '\n';
	}

	int c = x;
	while (c) {
		std::cout << first[c] << ' ';
		c -= first[c];
	}

	std::cout << std::endl;

	return 0;
}