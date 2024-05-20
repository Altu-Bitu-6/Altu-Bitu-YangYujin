#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int snakeGame(int n, vector<vector<int>>& board, vector<pair<int,char>>& rotate){
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x=0, y=0;
    int dir=0;
    int i=0; // rotate 몇 번째까지 확인했는지 체크하는 인덱스
    
    int time=0;
    
    deque<pair<int,int>> dq;
    dq.push_front(make_pair(x,y));
    board[x][y]=2; 
    // 0: 빈 공간, 1: 사과 있음, 2: 뱀 있음
    
    while(true){
        time++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 벽이나 몸통에 닿으면 게임 종료
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2){
            break;
        }
        
        // 사과가 없는 경우 꼬리 이동
        if(board[nx][ny] == 0){
            int tx = dq.back().first;
            int ty = dq.back().second;
            board[tx][ty] = 0; // 꼬리가 있던 자리를 비움
            dq.pop_back();
        }
        
        // 새로운 위치로 머리 이동
        x = nx;
        y = ny;
        board[x][y] = 2;
        dq.push_front(make_pair(x,y));
        
        // 사과가 있는 경우 사과를 없앰
        if(board[x][y] == 1){
            board[x][y] = 0;
        }
        
        // 방향 전환
        if(i < rotate.size() && time == rotate[i].first){
            if(rotate[i].second == 'D'){
                dir = (dir + 1) % 4;
            }
            else{
                dir = (dir + 3) % 4;
            }
            i++; // 다음 방향 전환 정보로 업데이트
        }
        
    }
    return time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    int n, k;
    int l, x;
    char c;
    
    cin >> n >> k;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 1; // 사과 위치 표시
    }
    
    cin >> l;
    vector<pair<int, char>> rotate(l);
    
    for(int i = 0; i < l; i++){
        cin >> x >> c;
        rotate[i] = make_pair(x, c);
    }
    
    cout << snakeGame(n, board, rotate);
    
    return 0;
}
