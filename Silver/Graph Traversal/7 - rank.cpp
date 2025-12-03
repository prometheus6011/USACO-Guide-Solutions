#include <iostream>
#include <vector>
#include <algorithm>

void dfs(const std::vector<std::vector<int>>& adj, int start, std::vector<bool>& visited, std::vector<bool>& rec_stack, std::vector<bool>& in_cycle, std::vector<int>& path)
{
  visited[start] = true;
  rec_stack[start] = true;
  path.push_back(start);

  for (int i : adj[start]) {
    if (!visited[i]) {
      dfs(adj, i, visited, rec_stack, in_cycle, path);
    } else if (rec_stack[i]) {
      auto it = std::find(path.begin(), path.end(), i);
      if (it != path.end()) {
        int pos = it - path.begin();
        int cycle_len = path.size() - pos;
        if (cycle_len >= 3) {
          for (int i = 0; i < path.size(); ++i) {
            in_cycle[path[i]] = true;
          }
        }
      }
    }
  }

  rec_stack[start] = false;
  path.pop_back();
}

int main()
{
  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < k ; ++i) {
    int a = 0, b = 0, s_a = 0, s_b = 0;
    std::cin >> a >> b >> s_a >> s_b;
    --a, --b;
    if (s_a > s_b) adj[a].push_back(b);
    if (s_a < s_b) adj[b].push_back(a);
  }

  std::vector<bool> visited(n, false);
  std::vector<bool> rec_stack(n, false);
  std::vector<bool> in_cycle(n, false);
  std::vector<int> path;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(adj, i , visited, rec_stack, in_cycle, path);
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (in_cycle[i]) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
