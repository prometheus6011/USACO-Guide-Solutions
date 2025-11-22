#include <iostream>
#include <vector>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int& i : a) std::cin >> i;

  int left = 0, curr_sum = 0;
  int res = 0;
  for (int right = 0; right < n; ++right) {
    if (curr_sum == x) {
      ++res;
    }
    curr_sum += a[right];

    while (left < right && curr_sum > x) {
      curr_sum -= a[left++];
    }
  }

  if (curr_sum == x) ++res;

  std::cout << res << std::endl;

  return 0;
}
