#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
  std::ifstream ifs("pairup.in");
  std::ofstream ofs("pairup.out");

  int n;
  ifs >> n;
  std::vector<std::pair<int, int>> cows(n);
  for (int i = 0; i < n; ++i) {
    ifs >> cows[i].first >> cows[i].second;
  }

  std::sort(cows.begin(), cows.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
  });

  int left = 0, right = n - 1;
  int ans = 0;
  while (left < right) {
    int take = std::min(cows[left].first, cows[right].first);
    int curr_sum = cows[left].second + cows[right].second;
    ans = std::max(ans, curr_sum);
    cows[left].first -= take;
    cows[right].first -= take;

    if (cows[left].first == 0) ++left;
    if (cows[right].first == 0) --right;
  }

  ofs << ans << std::endl;

  return 0;
}
