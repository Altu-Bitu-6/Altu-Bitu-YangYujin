#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int matchChar(stack<char>& s, char c) {
    if (s.empty()) {
        return 0;
    }

    else if (c == ')' && s.top() != '(') {
        return 0;
    }

    else if (c == ']' && s.top() != '[') {
        return 0;
    }

    else {
        return 1;
    }
}


int main() {
    char c[101];

    while (true) {
        stack<char> s;
        bool isMatched = true;

        cin.ignore();//개행문자 삭제
        cin.getline(c, 100, '.');

        if (c[0] == NULL) {
            break;
        }

        for (int j = 0; j < strlen(c); j++) {
            if (c[j] == '(' || c[j] == '[') {
                s.push(c[j]); // 괄호의 종류에 따라 다른 값을 푸시
            }
            else if (c[j] == ')' || c[j] == ']') {

                if (!matchChar(s, c[j])) {
                    isMatched = false;
                    break;
                }

                s.pop(); // 괄호의 종류가 맞는 경우에만 팝
            }
        }

        if (!s.empty()) {
            isMatched = false;
        }

        if (isMatched) {
            cout << "yes\n";
        }

        else {
            cout << "no\n";
        }
    }

    return 0;
}
