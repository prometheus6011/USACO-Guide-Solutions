#include <algorithm>
#include <fstream>
#include <vector>

void dfs(int start, std::vector<bool>& visited, int& cows_visited, const std::vector<std::vector<int>>& adj)
{
  if (visited[start]) return;
  ++cows_visited;
  visited[start] = true;
  for (const auto& node : adj[start]) {
    if (!visited[node]) dfs(node, visited, cows_visited, adj);
  }
}

int main()
{
  std::ifstream ifs("moocast.in");
  std::ofstream ofs("moocast.out");

  int n;
  ifs >> n;
  std::vector<std::vector<int>> cows(n, std::vector<int>(3));

  for (int i = 0; i < n; ++i) {
    ifs >> cows[i][0] >> cows[i][1] >> cows[i][2];
  }

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int dist_x = cows[i][0] - cows[j][0], dist_y = cows[i][1] - cows[j][1];
      if (dist_x * dist_x + dist_y * dist_y <= cows[i][2] * cows[i][2]) {
        adj[i].push_back(j);
      }
    }
  }

  std::vector<bool> visited(n, false);
  int cows_visited = 0, max_cows_reached = 1;
  for (int i = 0; i < n; ++i) {
    cows_visited = 0;
    std::fill(visited.begin(), visited.end(), false);
    dfs(i, visited, cows_visited, adj);
    max_cows_reached = std::max(max_cows_reached, cows_visited);
  }

  ofs << max_cows_reached;

  return 0;
}
