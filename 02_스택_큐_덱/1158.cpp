#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;

    cin >> n >> k;

    cout << "<";

    for (int i = 1; i < n+1; i++) {
        q.push(i);
    } 


    while (q.size()>1) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }


    cout << q.front() << ">";
    return 0;
}