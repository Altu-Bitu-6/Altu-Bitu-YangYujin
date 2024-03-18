#include <iostream>
#include <queue>

using namespace std;

void gift(int a, priority_queue<int>& pq) {
	int value;
	for (int i = 0; i < a; i++) {
		cin >> value;
		pq.push(value);
	}
}

int main() {
	priority_queue<int> pq;
	int n, a;

	cin >> n;

	while (n--) {
		cin >> a;

		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}

		}
		else {
			gift(a, pq);
		}
	}

	return 0;
}