#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> charToInt(string str) {
    vector<int> v(str.length());

    for (int i = 0; i < str.length(); i++) {
        v[i] = str[str.length() - i-1] - '0';
    }

    return v;
}

vector<int> vAdder(vector<int> v1, vector<int> v2) {
    int carry = 0; //올림수

    int size = max(v1.size(), v2.size());
    vector<int> result(size+1); // 올림수를 고려해 '두 수(벡터) 중 자릿수가 더 큰 것+1'의 크기로 선언

    for (int i = 0; i < result.size(); i++) {
        if (i < v1.size()) carry += v1[i];
        if (i < v2.size()) carry += v2[i];

        result[i] = carry % 10; 
        carry /= 10;
    }

    return result;
}

int main() {
    const int MAX_SIZE = 10000;

    vector<int> v1(MAX_SIZE);
    vector<int> v2(MAX_SIZE);
    string str1, str2;

    cin >> str1 >> str2;


    v1 = charToInt(str1);
    v2 = charToInt(str2);


    vector<int> v3 = vAdder(v1, v2);

    int i = v3.size() - 1;

    while (i > 0 && v3[i] == 0) i--;
    for (; i >= 0; i--) {
        cout << v3[i];
    }

    return 0;
}
