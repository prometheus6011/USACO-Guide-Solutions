#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (int& i : p) std::cin >> i;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += p[j];
      int len = j - i + 1;

      if (sum % len != 0) continue;

      int avg = sum / len;

      for (int k = i; k <= j; ++k) {
        if (p[k] == avg) {
          ++res;
          break;
        }
      }
    }
  }

  std::cout << res << std::endl;

  return 0;
}
