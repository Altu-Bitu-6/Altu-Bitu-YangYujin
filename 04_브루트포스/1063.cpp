#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool posCheck(pair<int, int>& pos) {
    if (pos.first > 8 || pos.first < 1) {
        return false;
    }
    else if (pos.second > 8 || pos.second < 1) {
        return false;
    }
    else {
        return true;
    }
}

void move(pair<int, int>& pos, string cmd) {

    if (cmd == "R") {
        pos.first += 1;
    }
    else if (cmd == "L") {
        pos.first -= 1;

    }
    else if (cmd == "B") {
        pos.second -= 1;
    }
    else if (cmd == "T") {
        pos.second += 1;
    }
    else if (cmd == "RT") {
        pos.first += 1;
        pos.second += 1;
    }
    else if (cmd == "LT") {
        pos.first -= 1;
        pos.second += 1;
    }
    else if (cmd == "RB") {
        pos.first += 1;
        pos.second -= 1;
    }
    else if (cmd == "LB") {
        pos.first -= 1;
        pos.second -= 1;
    }
}



int main() {
    pair<int, int> pos, pos2;
    int n;
    string cmd;
    string king_pos, stone_pos;

    cin >> king_pos >> stone_pos >> n;

    pos.first = int(king_pos.at(0) - 'A' + 1);
    pos.second = int(king_pos.at(1) - '0');
    pos2.first = int(stone_pos.at(0) - 'A' + 1);
    pos2.second = int(stone_pos.at(1) - '0');




    for (int i = 0; i < n; i++) {
        cin >> cmd;

        pair<int, int> tmp = pos;
        pair<int, int> tmp2 = pos2;

        move(pos, cmd);
        if (pos == pos2) {
            move(pos2, cmd);
        }


        if (!posCheck(pos) || !posCheck(pos2)) {
            pos = tmp;
            pos2 = tmp2;
        }

    }

    cout << char(pos.first + 'A' - 1) << pos.second << '\n';
    cout << char(pos2.first + 'A' - 1) << pos2.second << '\n';


    return 0;
}

    
