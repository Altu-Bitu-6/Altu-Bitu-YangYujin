#include <iostream>
#include <vector>

using namespace std;

int getSequence(int n, int k, vector<int>& a){
    vector<int> v(100001, 0);
    int stt=0,end=0;
    int length=0;
    
    /*
    [a0][a1][a2][a3][a4]...
    †
    stt,end
    */
    
    
    while(end<n){
        if(v[a[end]]<k){
            v[a[end]]++;
            end++;
        }
        else{
            v[a[stt]]--;
            stt++;
        }
        
        length=max(length, end-stt);
    }
    
    return length;

}

int main()
{
    int n,k;
    
    cin>>n>>k;
    vector<int> a(200000,0);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    cout<<getSequence(n,k,a);

    return 0;
}
