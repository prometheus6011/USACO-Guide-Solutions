#include <climits>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>

int main()
{
  std::ifstream ifs("triangles.in");
  std::ofstream ofs("triangles.out");

  int n;
  ifs >> n;
  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    ifs >> points[i].first >> points[i].second;
  }

  int best = INT_MIN;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (k == j || k == i) continue;
        if ((points[i].first == points[j].first || points[i].first == points[k].first) &&
            (points[i].second == points[j].second || points[i].second == points[k].second)) {
          int b = 0;
          if (points[i].first == points[j].first) b = std::abs(points[i].second - points[j].second);
          else if (points[i].first == points[k].first) b = std::abs(points[i].second - points[k].second);
          int h = 0;
          if (points[i].second == points[j].second) h = std::abs(points[i].first - points[j].first);
          else if (points[i].second == points[k].second) h = std::abs(points[i].first - points[k].first);

          best = std::max(best, b * h);
        }
      }
    }
  }

  ofs << best << std::endl;
  return 0;
}
