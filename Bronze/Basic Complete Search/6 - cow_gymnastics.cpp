#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

bool solve(const std::vector<std::vector<int>>& order, int first, int second)
{
  int matches = 0;
  for (int i = 0; i < order.size(); ++i) {
    int first_idx = std::find(order[i].begin(), order[i].end(), first) - order[i].begin();
    int second_idx = std::find(order[i].begin(), order[i].end(), second) - order[i].begin();
    if (first_idx < second_idx) ++matches;
  }

  return matches == order.size();
}

int main()
{
  std::ifstream ifs("gymnastics.in");
  std::ofstream ofs("gymnastics.out");

  int k, n;
  ifs >> k >> n;
  std::vector<std::vector<int>> order(k, std::vector<int>(n));
  for (auto& vec : order) {
    for (auto& i : vec) {
      ifs >> i;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      ans += solve(order, i, j);
    }
  }

  ofs << ans << std::endl;

  return 0;
}
