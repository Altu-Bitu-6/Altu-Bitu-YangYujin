#include <iostream>
#include <queue>

using namespace std;

void pushToQueue(int n, priority_queue<int, vector<int>, greater<int>>& pq) {
    int num;
    for (int i = 0; i < n * n; i++) {
        cin >> num;
        pq.push(num);
        if (pq.size() > n) {
            pq.pop();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    pushToQueue(n, pq);

    cout << pq.top();

    return 0;
}

    
