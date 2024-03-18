#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void strToVec(string str, vector<int>& v) {
    for (int i = 0; i < str.length(); i++) {
        int tmp = str.at(i) - 'A';
        v[tmp] += 1;
    }


}

int similarWord(vector<int>& v, int len, int n) {
    string str;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        vector<int> v_comp(26);
        vector<int> dif;
        cin >> str;

        strToVec(str, v_comp);
        
        for (int j = 0; j < v.size(); j++) {
            if (v[j] != v_comp[j]) {
                dif.push_back(v[j] - v_comp[j]);
            }
        }

        //같은 구성을 갖는 경우
        if (dif.empty()) {
            cnt++;
        }

        //한 문자를 더하거나 뺀 경우
        if (dif.size() == 1 && abs(dif[0]) == 1) {
            cnt++;
        }

        //한 문자가 바뀐 경우
        if (dif.size() == 2 && abs(dif[0]) == 1 && dif[0]+dif[1]==0) {
            cnt++;
        }

    }   
    return cnt;
}

int main() {
    vector<int> v(26);
    int n;
    string str;
    cin >> n;
    
    cin >> str;
    strToVec(str, v);



    cout<<similarWord(v, str.length(), n-1);

    return 0;
}

    
