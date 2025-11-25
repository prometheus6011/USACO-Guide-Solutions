#include <climits>
#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (int& i : h) std::cin >> i;

  std::vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  if (n >= 2) {
    dp[1] = std::abs(h[1] - h[0]);
  }

  for (int i = 2; i <= n; ++i) {
    dp[i] = std::min(
      dp[i - 1] + std::abs(h[i] - h[i - 1]),
      dp[i - 2] + std::abs(h[i] - h[i - 2])
    );
  }

  std::cout << dp[n - 1] << std::endl;

  return 0;
}
