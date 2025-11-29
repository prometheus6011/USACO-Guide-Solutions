#include <climits>
#include <iostream>
#include <vector>

int main()
{
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    std::cin >> n;
    std::vector<int> bosses(n);
    for (int &j : bosses) std::cin >> j;

    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, 1e9));

    dp[1][0] = 0;
    for (int j = 0; j < n; ++j) {
      dp[0][j + 1] = std::min(dp[0][j + 1], dp[1][j] + bosses[j]);
      dp[1][j + 1] = std::min(dp[1][j + 1], dp[0][j]);

      if (j + 2 <= n) {
        dp[0][j + 2] = std::min(dp[0][j + 2], dp[1][j] + bosses[j] + bosses[j + 1]);
        dp[1][j + 2] = std::min(dp[1][j + 2], dp[0][j]);
      }
    }

    std::cout << std::min(dp[0][n], dp[1][n]) << std::endl;
  }

  return 0;
}
