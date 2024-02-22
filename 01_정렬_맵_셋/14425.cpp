#include <iostream>
#include <set>

using namespace std;

int main(){
    int n,m, count=0;
    cin>>n>>m;
    set<string> s;

    string str;

    for(int i=0; i<n; i++){
        cin>>str;
        s.insert(str);
    }

    for(int i=0; i<m; i++){
        cin>>str;
        auto itr=s.find(str);
        if(itr!=s.end()){
            count++;
        }

    }

    cout<<count;

    return 0;
}
