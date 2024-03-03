#include <iostream>
#include <vector>
#include <set>

using namespace std;

void check(vector<int>& s, vector<char>& ch, int k, vector<char>& result, bool& is_true, int& index, int n) {
    set<char> alp;
    for (int i = 0; i < k; i++) {
        auto itr = alp.find(ch[i]);

        index = (index + s[i]) % n;
        if (result[index] == '?' && itr != alp.end()) {
            is_true = false;
            break;
        }

        else if (result[index]=='?' || result[index]==ch[i]) {
            result[index] = ch[i];
            alp.insert(ch[i]);

        }

        else if (result[index] != ch[i]) {
            is_true = false;
            break;
        }

    }
}


int main() {
    bool is_true=true;
    int n, k;
    int index = 0;

    cin >> n >> k;

    vector<int> s(k);
    vector<char> ch(k);
    vector<char> result(n, '?');

    

    for (int i = 0; i < k; i++) {
        cin >> s[i] >> ch[i];
    }

    check(s, ch, k, result, is_true, index, n);

    if (!is_true) {
        cout << "!";
    }

    else {
        int count = 0;
        while (count<n) {
            cout << result[index];
            index = (index + n - 1) % n;
            count++;
        }
    }

    
    return 0;
}
