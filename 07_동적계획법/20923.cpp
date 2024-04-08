#include <iostream>
#include <deque>

using namespace std;

string game(int m, deque<int>& dodo, deque<int>& suyeon) {
    deque<int> d_ground, s_ground;
    bool d_turn = true;

    while (m--) {
        if (d_turn) { //도도의 차례라면
            d_ground.push_back(dodo.back()); //자신의 그라운드에 카드 내려놓기
            dodo.pop_back();
        }
        else { // 수연의 차례라면
            s_ground.push_back(suyeon.back());
            suyeon.pop_back();
        }

        //덱에 있는 카드 수가 0이 되는 경우
        if (dodo.size()==0) { 
            return "su";
        }
        else if(suyeon.size()==0) {
            return "do";
        }


        if (d_ground.size()!=0 && s_ground.size()!=0 && d_ground.back() + s_ground.back() == 5) { //수연이 종을 침

            while(d_ground.size()) {
                suyeon.push_front(d_ground.front());
                d_ground.pop_front();
            }
            while(s_ground.size()) {
                suyeon.push_front(s_ground.front());
                s_ground.pop_front();
            }
        }

        else if ((d_ground.size()!=0 && d_ground.back() == 5) || (s_ground.size() != 0 && s_ground.back() == 5)) { //도도가 종을 침

            while (s_ground.size()) {
                dodo.push_front(s_ground.front());
                s_ground.pop_front();
            }
            while (d_ground.size()) {
                dodo.push_front(d_ground.front());
                d_ground.pop_front();
            }
        }


        d_turn = !d_turn;
    }

    if (dodo.size() > suyeon.size()) {
        return "do";
    }
    else if (dodo.size() < suyeon.size()) {
        return "su";
    }
    else {
        return "dosu";
    }
}


int main() {
    int n, m; // 카드 개수, 게임 진행 횟수

    cin >> n >> m;
    deque<int> dodo(n);
    deque<int> suyeon(n);

    for (int i = 0; i < n; i++) {
        cin >> dodo[i] >> suyeon[i];
    }

    cout << game(m, dodo, suyeon);


    return 0;
}