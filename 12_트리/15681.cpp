#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 100001;

vector<int> edge[SIZE];
int visited[SIZE] = {0};
int dparr[SIZE] = {0};

int dp(int node) {
    visited[node] = 1; // 현재 노드를 방문했다고 표시
    int subtree_size = 1; // 현재 노드 자신을 포함하므로 1로 시작

    for (int neighbor : edge[node]) {
        if (!visited[neighbor]) {
            subtree_size += dp(neighbor); // 서브트리의 크기를 더함
        }
    }

    dparr[node] = subtree_size; // 해당 노드의 서브트리 크기를 저장
    return subtree_size;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dp(r); // 루트 노드부터 시작하여 서브트리 크기 계산

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << dparr[query] << '\n'; // 쿼리 결과 출력
    }

    return 0;
}
