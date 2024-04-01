#include <iostream>
#include <vector>
#include <string>

using namespace std;
//dir=1: 시계방향, dir=-1: 반시계방향

void setGear(vector<string>& gear, int num, int dir, int t, vector<int>& index) {
    
    index[num - 1] = dir;
    for (int i = num; i < t; i++) { //오른쪽 톱니바퀴들과 극 확인
        if (gear[i-1][2] != gear[i][6]) { //극이 다르다면 index 배열에 방향 저장
            index[i] = index[i-1]*-1;
        }
        else { //극이 같다면 그 이후로는 더이상 회전하지 않으므로 break
            break;
        }
    }

    for (int i = num-2; i >= 0; i--) { //외쪽 톱니바퀴들과 극 확인
        if (gear[i+1][6] != gear[i][2]) {
            index[i] = index[i+1] * -1; 
        }
        else {
            break; 
        }
    }
}

void rotate(vector<string>& gear, vector<int>& index) {
    for (int i = 0; i < gear.size(); i++) {
        if (index[i] == 0) {
            continue; // 회전하지 않는 경우
        }

        string tmp = gear[i];
        if (index[i] == 1) { // 시계 방향 회전
            gear[i] = tmp[7] + tmp.substr(0, 7);
        }
        else if (index[i] == -1) {
            gear[i] = tmp.substr(1, 8) + tmp[0];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, k, cnt=0;

    cin >> t; //톱니바퀴 수
    vector<string> gear(t);

    for (int i = 0; i < t; i++) {
        cin >> gear[i];
    }

    cin >> k; //회전 횟수
    for (int i = 0; i < k; i++) {
        vector<int> index(t, 0);

        int num, dir;
        cin >> num >> dir;
        setGear(gear, num, dir, t, index);
        rotate(gear, index);
    }


    for (int i = 0; i < t; i++) {
        if (gear[i][0] == '1') {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
