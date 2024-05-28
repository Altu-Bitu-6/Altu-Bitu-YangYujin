#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int>& v, int n, int d, int k, int c) {
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        vector<int> chk(d + 1, 0);
        int count = 0;  // 먹은 초밥의 종류 수
        for (int j = i; j < i + k; j++) {
            if (chk[v[j % n]] == 0) {
                count++;  // 새로운 초밥 종류
            }
            chk[v[j % n]]++;
        }
        if(chk[c] == 0) {
            count++;  // 쿠폰 초밥 추가
        }
        result = max(result, count);
    }
    
    return result;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << getMax(v, n, d, k, c);
    
    return 0;
}
