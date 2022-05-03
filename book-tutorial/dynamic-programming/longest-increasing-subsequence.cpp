#include <iostream>
#include <vector>

int main() {
	std::vector<int> array{6, 2, 5, 1, 7, 4, 8, 3};
	std::vector<int> dp(100);

	for (int i : array) {
		dp[i] = 1;
	}

	return 0;
}