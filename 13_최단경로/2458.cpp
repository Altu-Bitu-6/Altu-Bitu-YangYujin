#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;
typedef vector<vector<int>> vvi;

void floyd(vvi& weight, int n){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                if(weight[j][k]>weight[j][i]+weight[i][k]){
                    weight[j][k]=weight[j][i]+weight[i][k];
                }
            }
        }
    }
}

int getHeight(vvi& weight, int n){
    int ans=0;
    
    for(int i=1; i<n+1; i++){
        int cnt=0;
        for(int j=1; j<n+1; j++){
            if(i==j){
                continue;
            }
            if(weight[i][j]!=INF||weight[j][i]!=INF){
                cnt++;
            }
        }
        
        if(cnt==n-1){
            ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,m;

    cin>>n>>m;
    
    vvi weight(n+1, vector<int>(n+1));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i!=j){
                weight[i][j]=INF;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        weight[a][b]=1;
    }
    
    floyd(weight, n);
    
    
    
    cout<<getHeight(weight, n);

    return 0;
}