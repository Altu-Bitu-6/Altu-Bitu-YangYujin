#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int x, int y) {
        return x > y;
    }
};



void pushToQueue(int n, priority_queue<int, vector<int>, cmp>& pq) {
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
    priority_queue<int, vector<int>, cmp> pq;

    cin >> n;

    pushToQueue(n, pq);

    cout << pq.top();

    return 0;
}

    
