#include <iostream>
#include <queue>

using namespace std;

void setQueue(queue<int>& q, int n) { //큐에 1부터 n까지 삽입
    for (int i = 1; i < n + 1; i++) {
        q.push(i);
    }
}

void copy(queue<int>& q, int k) {
    for (int i = 1; i < k; i++) {
            q.push(q.front()); 
            q.pop(); //앞에서부터 k-1개의 원소를 큐 맨 뒤로 복사 후 앞에서는 제거
    }
}

int main() {
    int n, k;
    queue<int> q;

    cin >> n >> k;

    cout << "<";

    setQueue(q, n);


    while (q.size() > 1) {
        copy(q, k);
        cout << q.front() << ", ";
        q.pop(); //맨앞에 남은 (원래 k번째에 있던) 원소를 출력 후 팝
    }


    cout << q.front() << ">";
    return 0;
}