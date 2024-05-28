#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int bfs(int p1, int p2, int n, vector<vector<bool>>& family){
    queue<pair<int, int>> q; // 현재 위치와 해당 위치까지의 촌수를 함께 저장
    vector<bool> visit(n+1, false);
    
    q.push({p1, 0}); // 시작점과 초기 촌수 0을 큐에 삽입
    visit[p1] = true; 
    
    while(!q.empty()){
        int node = q.front().first;
        int cnt = q.front().second; // 현재 노드까지의 촌수
        q.pop();
        
        if(node == p2){
            return cnt; // 목표 노드에 도달했으면 현재 촌수 반환
        }
        
        for(int i=1; i<=n; i++){
            if(family[node][i] && !visit[i]){ // i와 연결되어 있고 방문하지 않았다면
                visit[i] = true;
                q.push({i, cnt + 1}); // 촌수를 1 증가시켜 다음 노드로 이동
            }
        }
    }
 
    return -1; // p2에 도달할 수 없는 경우
}

int main()
{
    int n, p1, p2, m;
    
    int cnt=0;
    
    cin>>n;
    cin>>p1>>p2;
    cin>>m;
    
    vector<vector<bool>> family(n+1, vector<bool>(n+1, 0));

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        family[x][y]=true;
        family[y][x]=true;
    }
    
    cout<<bfs(p1, p2, n, family);
    
    
    return 0;
}
