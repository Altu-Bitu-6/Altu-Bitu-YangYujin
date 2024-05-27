#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000

using namespace std;
typedef pair<int, int> pii;

vector<int> dijkstra(int start, int n, vector<vector<pii>>& graph) {
    vector<int> dist(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int wei = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (wei > dist[node]) {
            continue;
        }
        
        for (auto& edge : graph[node]) {
            int nnode = edge.first;
            int nwei = edge.second + wei;
            
            if (nwei < dist[nnode]) {
                dist[nnode] = nwei;
                pq.push({nwei, nnode});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<vector<pii>> graph(n+1);
    vector<vector<pii>> reverse_graph(n+1);
    
    for (int i = 0; i < m; ++i) {
        int s, e, t;
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
        reverse_graph[e].push_back({s, t});
    }
    
    vector<int> to_party = dijkstra(x, n, graph);
    vector<int> from_party = dijkstra(x, n, reverse_graph);
    
    int max_time = 0;
    for (int i = 1; i <= n; ++i) {
        if (to_party[i] != INF && from_party[i] != INF) {
            max_time = max(max_time, to_party[i] + from_party[i]);
        }
    }
    
    cout << max_time << endl;
    
    return 0;
}
