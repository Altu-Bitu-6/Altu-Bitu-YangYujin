#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int START = 1;

int virus(vector<vector<bool>>& edge, int n){
    queue<int> q;
    vector<bool> visit(n+1,0);
    int cnt=0;
    
    q.push(START);
    visit[START]=true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        
        for(int i=1; i<=n; i++){
            if(edge[node][i] && !visit[i]){
                visit[i]=true;
                q.push(i);
            }
        }
        
        
    }
    
    return cnt;
    
    
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<bool>> edge(n+1, vector<bool>(n+1, 0));
    

    
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        edge[x][y]=true;
        edge[y][x]=true;
    }
    
    cout<<virus(edge, n)-1;
    
    return 0;
}
