#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int pass(vector<pii>& v){
    sort(v.begin(), v.end());
    int cur=v[0].second;
    int cnt=1;
    
    for(int i=1; i<v.size(); i++){
        if(v[i].second<cur){
            cur=v[i].second;
            cnt++;
        }
        else{
            continue;
        }
    }
    
    
    return cnt;
}

int main()
{
    int t;
    int n, test, iv;

    cin>>t;
    
    while(t--){
        cin>>n;
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            cin>>test>>iv;
            v[i]=make_pair(test, iv);
        }
        cout<<pass(v)<<'\n';
    }
    

    return 0;
}
