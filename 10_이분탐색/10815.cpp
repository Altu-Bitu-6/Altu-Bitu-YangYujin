#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int key, int n, vector<int>& card){
    int left = 0;
    int right = n-1;
    int mid;
    
    while(left<=right){
        mid = (left+right)/2;
        
        if(card[mid]==key){
            return 1;
        }
        else if(card[mid]>key){
            right = mid-1;
        }
        else{
            left = mid+1;
        }

    }
    
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    int n, m;
    
    cin>>n;
    vector<int> card(n);

    for(int i=0; i<n; i++){
        cin>>card[i];
    }
    
    sort(card.begin(), card.end());
    cin>>m;
    vector<int> find(m);

    for(int i=0; i<m; i++){
        cin>>find[i];
    }
    
    for(int i=0; i<m; i++){
        cout<<binarySearch(find[i],n,card)<<' ';
    }
    

    return 0;
}
