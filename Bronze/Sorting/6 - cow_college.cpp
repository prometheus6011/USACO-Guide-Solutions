#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (int& i : c) std::cin >> i;

  std::sort(c.begin(), c.end());

  long long max_profit = LLONG_MIN, max_price = LLONG_MIN;

  for (int i = 0; i < n; ++i) {
    int price = c[i];
    long long students = n - i;
    long long profit = 1LL * students * price;


    if (profit > max_profit) {
      max_profit = profit;
      max_price = price;
    }
  }

  std::cout << max_profit << " " << max_price << std::endl;

  return 0;
}
