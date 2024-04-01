#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pall(vector<int>& v) {
    int odd_i=-1;
    string result;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 1) {
            if (odd_i == -1) {
                odd_i = i;
            }
            else {
                return "I'm Sorry Hansoo";
            }            
        }

        for (int j = 0; j < v[i] / 2; j++) {
            result += i + 'A';
        }
    }

    if (odd_i != -1) {
        result += odd_i + 'A';

    }

    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[i]/2; j++) {
            result += i + 'A';
        }
    }

    return result;
    
    



}

int main() {
    string name;
    vector<int> v(26, 0);
    cin >> name;

    for (int i = 0; i < name.size(); i++) {
        v[name[i] - 'A']++;
    }

    cout << pall(v);

    return 0;
}