#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; // 무한대를 나타내는 큰 값
typedef vector<vector<int>> vvi;

// 플로이드-워셜 알고리즘 함수
void floyd(vvi& weight, int n){
    // 모든 노드 i, j, k에 대해 최단 경로를 갱신
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                // weight[j][k]가 weight[j][i] + weight[i][k]보다 크다면 갱신
                if(weight[j][k] > weight[j][i] + weight[i][k]){
                    weight[j][k] = weight[j][i] + weight[i][k];
                }
            }
        }
    }
}

//자신의 키가 몇 번째인지 알 수 있는 경우 = 자신을 제외한 모든 학생과 비교가 가능한 경우 = 거리가 INF(무한)가 아닌 학생 수가 n-1인 경우
int getHeight(vvi& weight, int n){
    int ans = 0; 
    for(int i=1; i<n+1; i++){
        int cnt = 0; 
        for(int j=1; j<n+1; j++){
            if(i == j){
                continue; // 자기 자신으로의 경로는 무시
            }
            if(weight[i][j] != INF || weight[j][i] != INF){
                cnt++;
            }
        }
        
        if(cnt == n-1){
            ans++;
        }
    }
    return ans; 
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; 

    cin >> n >> m;

    vvi weight(n+1, vector<int>(n+1)); 

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i != j){
                weight[i][j] = INF; // 자기 자신 외의 경로를 무한대로 초기화
            }
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        weight[a][b] = 1; // a에서 b로 가는 경로의 가중치를 1로 설정
    }
    
    floyd(weight, n); // 플로이드-워셜 알고리즘으로 최단 경로 계산

    cout << getHeight(weight, n); 

    return 0;
}
