#include <iostream>
#include <vector>
#include <utility>

void dfs(const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int start)
{
  visited[start] = true;
  for (const auto& child : adj[start]) {
    if (!visited[child]) dfs(adj, visited, child);
  }
}

bool solve(const std::vector<std::pair<int, int>>& edges, int skip_idx, int n)
{
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < edges.size(); ++i) {
    if (i == skip_idx) continue;
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }

  std::vector<bool> visited(n);
  dfs(adj, visited, 0);

  bool ret = true;
  for (int i = 0; i < n; ++i) {
    ret &= visited[i];
  }
  return ret;
}

int main()
{
  int p, c;
  while ((std::cin >> p >> c) && (p != 0 && c != 0)) {
    std::vector<std::pair<int, int>> edges(c);
    for (int i = 0; i < c; ++i) {
      std::cin >> edges[i].first >> edges[i].second;
    }

    bool can_break = false;
    for (int i = 0; i < c; ++i) {
      if (!solve(edges, i, p)) {
        can_break = true;
        break;
      }
    }

    if (can_break) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
