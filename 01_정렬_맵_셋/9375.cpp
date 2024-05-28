#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getCase(map<string, int>& m){
    int ans=1;
    for(auto i:m){
        ans *= (i.second+1);
    }
    return ans-1;
}


int main() {
    
    int n;
    int var;
    string name, type;
    

    cin>>n;
    
    while(n--){
        map<string, int> m;

        cin>>var;
        vector<int> v(var);
        for(int i=0; i<var; i++){
            cin>>name>>type;
            if(m.find(type)!=m.end()){
                m[type]++;
            }
            else{
                m.insert(make_pair(type, 1));
            }
        }
        cout<<getCase(m)<<'\n';

    }
    

    return 0;
}
