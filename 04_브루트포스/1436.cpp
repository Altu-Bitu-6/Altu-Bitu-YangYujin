#include <iostream>
#include <vector>
#include <string>

using namespace std;


string movieTitle(int n) {
    int num = 666;
    int cnt=0;
    string str;
    
    while (true) {
        str = to_string(num); //num을 문자열로 변환해 str에 저장
        if (str.find("666") != -1) {
            cnt++;
        }
        if (cnt == n) {
            return str;
            break;
        }
        num++;
    }
}



int main() {
    int n;
    cin >> n;

    cout << movieTitle(n);


    return 0;
}
