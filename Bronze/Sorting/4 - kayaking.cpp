#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main(void)
{
  int n;
  std::cin >> n;
  std::vector<int> w(2 * n);
  for (int &i : w) std::cin >> i;

  std::sort(w.begin(), w.end());

  int answer = INT_MAX;

  for (int i = 0; i < 2 * n; ++i) {
    for (int j = i + 1; j < 2 * n; ++j) {
      std::vector<int> rem;
      rem.reserve(2 * n - 2);

      for (int k = 0; k < 2 * n; ++k) {
        if (k == i || k == j) continue;
        rem.push_back(w[k]);
      }

      int curr = 0;
      for (int k = 0; k < rem.size(); k += 2) {
        curr += rem[k + 1] - rem[k];
      }
      answer = std::min(curr, answer);
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
