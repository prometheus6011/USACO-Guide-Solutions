#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }

  std::sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    int left = i + 1, right = n - 1;
    while (left < right) {
      int sum = a[i].first + a[left].first + a[right].first;
      if (sum == x) {
        std::cout << a[i].second << " " << a[left].second << " " << a[right].second << std::endl;
        return 0;
      }
      if (sum < x) {
        ++left;
      } else {
        --right;
      }
    }
  }

  std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}
