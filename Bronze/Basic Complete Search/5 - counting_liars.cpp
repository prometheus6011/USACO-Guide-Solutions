#include <climits>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<char, int>> vec(n);
  for (auto& p : vec) {
    std::cin >> p.first >> p.second;
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int liars = 0;
    for (int j = 0; j < n; ++j) {
      if (vec[j].first == 'L' && vec[i].second > vec[j].second) ++liars;
      if (vec[j].first == 'G' && vec[i].second < vec[j].second) ++liars;
    }
    ans = std::min(ans, liars);
  }

  std::cout << ans << std::endl;

  return 0;
}
