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
            }
        }
    }
    return ans;
}

void dragonCurve(int x, int y, vector<int>& dir, vector<vector<int>>& board){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    board[y][x] = 1;

    for(int d : dir){
        x += dx[d];
        y += dy[d];
        board[y][x] = 1;
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
