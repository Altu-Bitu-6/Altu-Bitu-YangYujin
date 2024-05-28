#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 101;

/*
→ ↑ ← ↓
0세대: 0
1세대: 0 1
2세대: 0 1 2 1
3세대: 0 1 2 1 2 3 2 1
*/

//규칙성에 따라 드래곤커브가 움직일 방향을 설정
//n세대: (n-1세대) concat reverse((n-1세대 각 방향+1)%4)
vector<int> generations(int g, vector<int>& dir){
    for(int gen = 0; gen < g; ++gen) {
        int size = dir.size();
        for(int i = size - 1; i >= 0; --i) {
            dir.push_back((dir[i] + 1) % 4);
        }
    }
    return dir;
}

int check(vector<vector<int>>& board){
    int ans = 0;
    for(int i = 0; i < SIZE-1; ++i){
        for(int j = 0; j < SIZE-1; ++j){
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                ans++;
            } //사각형 만들어지는 조건 확인
        }
    }
    return ans;
}

void dragonCurve(int x, int y, vector<int>& dir, vector<vector<int>>& board){
    int dx[4] = {1, 0, -1, 0}; //→ ↑ ← ↓
    int dy[4] = {0, -1, 0, 1};

    board[x][y] = 1;

    for(int d : dir){ //dir에 저장된 방향대로 1씩 늘리기
        x += dx[d];
        y += dy[d];
        board[x][y] = 1;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    for(int i = 0; i < n; ++i){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> dir = {d};
        dir = generations(g, dir);
        dragonCurve(x, y, dir, board);
    }

    cout << check(board) << endl;

    return 0;
}
