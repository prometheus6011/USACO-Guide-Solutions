#include <climits>
#include <fstream>
#include <vector>

struct Cow {
  int x, y;
  bool visited;
};

void dfs(int start, std::vector<Cow>& cows, std::vector<int>& curr_net, const std::vector<std::vector<int>>& adj)
{
  cows[start].visited = true;
  curr_net.push_back(start);

  for (int i : adj[start]) {
    if (!cows[i].visited) dfs(i, cows, curr_net, adj);
  }
}

int main()
{
  std::ifstream ifs("fenceplan.in");
  std::ofstream ofs("fenceplan.out");

  int n, m;
  ifs >> n >> m;
  std::vector<Cow> cows(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    ifs >> x >> y;
    cows[i].x = x;
    cows[i].y = y;
    cows[i].visited = false;
  }

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    ifs >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  std::vector<std::vector<int>> networks;
  for (int i = 0; i < n; ++i) {
    if (!cows[i].visited) {
      std::vector<int> curr_net;
      dfs(i, cows, curr_net, adj);
      networks.push_back(curr_net);
    }
  }

  int min_perimeter = INT_MAX;
  for (const std::vector<int>& nets : networks) {
    int max_x = 0, min_x = INT_MAX;
    int max_y = 0, min_y = INT_MAX;
    for (int id : nets) {
      max_x = std::max(max_x, cows[id].x);
      min_x = std::min(min_x, cows[id].x);
      max_y = std::max(max_y, cows[id].y);
      min_y = std::min(min_y, cows[id].y);
    }

    min_perimeter = std::min(min_perimeter, (2 * (max_x - min_x)) + (2 * (max_y - min_y)));
  }

  ofs << min_perimeter << std::endl;

  return 0;
}
