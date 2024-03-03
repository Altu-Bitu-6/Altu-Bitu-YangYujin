#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void goldbach(vector<bool>& is_prime, int ans, pair<int, int>& result) {
    for (int i = 0; i<ans; i++) {

        if (is_prime[i] && is_prime[ans - i]) {
            result.first = i;
            result.second = ans-i;

            break;
        }
    }


}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans;


    vector<bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(is_prime.size()); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }


    while (true) {
        cin >> ans;

        if (ans == 0) {
            break;
        }

        pair<int, int> result;
        
        goldbach(is_prime, ans, result);

        cout << ans << " = " << result.first << " + " << result.second<<'\n';

        

    }

    return 0;
}
