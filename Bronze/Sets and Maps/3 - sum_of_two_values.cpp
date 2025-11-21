#include <iostream>
#include <vector>
#include <map>

int main()
{
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int& i : a) std::cin >> i;

  std::map<int, int> complements;
  for (int i = 0; i < n; ++i) {
    int comp = x - a[i];
    if (complements.find(comp) != complements.end()) {
      std::cout << i + 1 << " " << complements[comp] + 1 << std::endl;
      return 0;
    }
    complements[a[i]] = i;
  }

  std::cout << "IMPOSSIBLE" << std::endl;

  return 0;
}
