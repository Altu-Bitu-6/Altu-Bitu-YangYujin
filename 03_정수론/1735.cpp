#include <iostream>
#include <vector>

using namespace std;

void adder(pair<int, int>& a, pair<int, int>& b, pair<int, int>& result) {
    result.second = a.second * b.second;
    result.first = a.first * b.second + a.second * b.first;
}

int gcdIter(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

void abbr(pair<int, int>& result) {
    int gcd =  gcdIter(result.first, result.second);

    result.first /= gcd;
    result.second /= gcd;
}

int main() {
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> result;


    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    adder(a, b, result);
    abbr(result);

    cout << result.first << " " << result.second;
    
    return 0;
}
