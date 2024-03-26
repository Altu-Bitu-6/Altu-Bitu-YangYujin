#include <iostream>
#include <vector>

using namespace std;

long long parEarth(vector<int>& v) {
    long long vel = v.back(); // 주어진 속도 중 가장 마지막 값부터 역순으로 탐색

    for (int i = v.size() - 2; i >= 0; i--) {
        if (vel % v[i] == 0) { //배수인 경우 OK
            continue;
        }
        
        //배수가 아닌 경우
        vel = (vel / v[i] + 1) * v[i];


        
    }

    return vel;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, vel;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> vel;
        v.push_back(vel);
    }

    cout << parEarth(v);

    return 0;
}
