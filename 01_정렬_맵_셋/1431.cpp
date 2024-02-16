#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> v;


int sumOfNum(string str) {
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i]>='0' && str[i]<='9') {
            sum += str[i] - '0';
        }
    }

    return sum;
}

bool comp(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return str1.length() < str2.length();
    }

    int sum1 = sumOfNum(str1);
    int sum2 = sumOfNum(str2);

    if (sum1 != sum2) {
        return sum1 < sum2;
    }

    else return str1<str2;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
