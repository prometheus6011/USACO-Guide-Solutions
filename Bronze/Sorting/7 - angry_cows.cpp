#include <climits>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::ifstream ifs("angry.in");
  std::ofstream ofs("angry.out");

  int n;
  ifs >> n;
  std::vector<long long> cows(n);
  for (int i = 0; i < n; ++i) {
    ifs >> cows[i];
  }

  std::sort(cows.begin(), cows.end());

  int best = 1;
  for (int i = 0; i < n; ++i) {
    int left = i, rad = 1;
    while (true) {
      int new_left = left;
      while (new_left - 1 >= 0 && cows[left] - cows[new_left - 1] <= rad) {
        --new_left;
      }
      if (new_left == left) break;
      left = new_left;
      ++rad;
    }

    int right = i;
    rad = 1;
    while (true) {
      int new_right = right;
      while (new_right + 1 < n && cows[new_right + 1] - cows[right] <= rad) {
        ++new_right;
      }
      if (new_right == right) break;
      right = new_right;
      ++rad;
    }

    best = std::max(best, right - left + 1);
  }

  ofs << best;

  return 0;
}
