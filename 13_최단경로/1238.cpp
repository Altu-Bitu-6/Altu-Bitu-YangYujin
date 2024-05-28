#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000 

using namespace std;
typedef pair<int, int> pii;

// 다익스트라 알고리즘 함수 활용: 하나의 노드에서 다른 모든 노드까지 최단 거리를 계산
vector<int> dijkstra(int start, int n, vector<vector<pii>>& graph) {
    vector<int> dist(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0; 
    pq.push({0, start}); 
    
    while (!pq.empty()) { 
        int wei = pq.top().first;  // 현재 노드까지의 거리
        int node = pq.top().second;  // 현재 노드
        pq.pop();
        
        if (wei > dist[node]) {  
            continue;
        }
        
        // 현재 노드와 연결된 모든 인접 노드 탐색
        for (auto& edge : graph[node]) {
            int nnode = edge.first;  // 인접 노드
            int nwei = edge.second + wei;  // 인접 노드까지의 거리
            
            if (nwei < dist[nnode]) {  // 더 짧은 경로를 발견하면
                dist[nnode] = nwei;  // 최단 거리 갱신
                pq.push({nwei, nnode});
            }
        }
    }
    
    return dist; 
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;  
    
    vector<vector<pii>> graph(n+1);  // 정방향 그래프
    vector<vector<pii>> reverse_graph(n+1);  // 역방향 그래프
    
    for (int i = 0; i < m; ++i) {
        int s, e, t;
        cin >> s >> e >> t; 
        graph[s].push_back({e, t});  // 정방향 그래프에 간선 추가
        reverse_graph[e].push_back({s, t});  // 역방향 그래프에 간선 추가
    }
    
    vector<int> to_party = dijkstra(x, n, graph);
    vector<int> from_party = dijkstra(x, n, reverse_graph);
    
    int max_time = 0;
    for (int i = 1; i <= n; ++i) {
        if (to_party[i] != INF && from_party[i] != INF) {  // 유효한 경로가 있는 경우
            max_time = max(max_time, to_party[i] + from_party[i]);  // 최대 왕복 시간 갱신
        }
    }
    
    cout << max_time << endl;
    
    return 0;
}
