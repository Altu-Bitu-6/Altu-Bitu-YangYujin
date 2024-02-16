#include <iostream>
#include <cmath>

using namespace std;

int bmChange(int t, int bm, int weight_pm) {
    if (abs(weight_pm) > t) {
        bm += floor((double)weight_pm / 2);
        return bm;
    }
    else return bm;
}

void diet1(int w0, int d, int weight_pm, int i0) {
    int final_w = w0 + (d * weight_pm);

    if (final_w <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << final_w << " " << i0 << '\n';
    }
}

void diet2(int w0, int d, int i, int bm, int a, int t) {
    bool w_zero = true;
    bool bm_zero = true;
    int final_w = w0;
    int bm0 = bm;

    for (int j = 0; j < d; j++) {
        int weight_pm = i - (bm + a);
        final_w += weight_pm;
        if (final_w <= 0) w_zero = false;

        bm = bmChange(t, bm, weight_pm);
        if (bm <= 0) bm_zero = false;
    }

    if (w_zero && bm_zero && bm0 <= bm) {
        cout << final_w << " " << bm << " " << "NO";
    }
    else if (w_zero && bm_zero && bm0 > bm) {
        cout << final_w << " " << bm << " " << "YOYO";
    }
    else {
        cout << "Danger Diet";
    }
}

int main() {
    int w0, i0, t; //다이어트 전 체중, 다이어트 전 일일 에너지 섭취량(=기초대사량), 기초대사량 변화 역치
    int d, i, a; //다이어트 기간, 다이어트 중 일일 에너지 섭취량, 다이어트 중 일일 활동대사량

    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    int bm = i0;
    int weight_pm = i - (bm + a);

    diet1(w0, d, weight_pm, i0);
    diet2(w0, d, i, bm, a, t);

    return 0;
}
