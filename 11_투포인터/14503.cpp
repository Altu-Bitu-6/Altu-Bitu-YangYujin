#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
int n, m;

int cleaning(vvi& map, vvi& visit, int x, int y, int d, int sum) {
    static int dx[4] = {-1, 0, 1, 0};
    static int dy[4] = {0, 1, 0, -1};
    
    // 현재 위치 청소
    visit[x][y] = 1;
    
    // 현재 방향에서 반시계 방향으로 4번 회전하며 탐색
    for (int i = 0; i < 4; i++) {
        d = (d + 3) % 4; // 반시계 방향으로 회전
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        // 청소하지 않은 빈 칸이라면 이동 후 재귀 호출
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0 && visit[nx][ny] == 0) {
            return cleaning(map, visit, nx, ny, d, sum + 1);
        }
    }
    
    // 4방향 모두 청소가 되어있거나 벽인 경우 후진
    int back_d = (d + 2) % 4; // 후진 방향
    int back_x = x + dx[back_d];
    int back_y = y + dy[back_d];
    
    // 후진할 수 있는 경우
    if (back_x >= 0 && back_x < n && back_y >= 0 && back_y < m && map[back_x][back_y] == 0) {
        return cleaning(map, visit, back_x, back_y, d, sum);
    }
    
    // 후진할 수 없는 경우(벽인 경우) 현재까지의 청소 칸 수 반환
    return sum;
}

int main() {
    int r, c, d;
    
    cin >> n >> m;
    cin >> r >> c >> d;
    
    vvi map(n, vector<int>(m, 0));
    vvi visit(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    cout << cleaning(map, visit, r, c, d, 1) << endl;
    
    return 0;
}
