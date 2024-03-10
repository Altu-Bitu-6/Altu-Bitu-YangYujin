#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add(int& s, int n) {
    s |= (1 << n);
}

void remove(int& s, int n) {
    s &= ~(1 << n);

}

int check(int& s, int n) {
    if (s & (1 << n)) {
        return 1;
    }
    else {
        return 0;
    }
}

void toggle(int& s, int n) {
    if (s & (1 << n)) {
        remove(s, n);
    }
    else {
        add(s, n);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s = 0; // 0000 0000 0000 0000 0000 0000 0000 0000
    string str;
    int n;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> str;

        if (str == "add") {
            cin >> n;
            add(s, n);
        }
        else if (str == "remove") {
            cin >> n;
            remove(s, n);

        }
        else if (str == "check") {
            cin >> n;
            cout << check(s, n) << '\n';

        }
        else if (str == "toggle") {
            cin >> n;
            toggle(s, n);

        }
        else if (str == "all") {
            s |= (1 << 21) - 1; 
        }
        else {
            s &= ~s;
        }

    }
    return 0;

}

    
