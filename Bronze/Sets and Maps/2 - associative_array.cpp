#include <iostream>
#include <map>

int main(void)
{
  int q;
  std::cin >> q;
  std::map<unsigned long long, unsigned long long> mp;
  for (int i = 0; i < q; ++i) {
    int cmd;
    unsigned long long k, v;
    std::cin >> cmd;

    if (cmd == 0) {
      std::cin >> k >> v;
      mp[k] = v;
    } else {
      std::cin >> k;
      std::cout << mp[k] << std::endl;
    }
  }

  return 0;
}
