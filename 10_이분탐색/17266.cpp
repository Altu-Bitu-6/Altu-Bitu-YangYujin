#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(int mid, vector<int>& location, int n){
    if(location[0]>mid || n-location[location.size()-1]>mid){
        return false;
    }
    for(int i=0; i<location.size()-1; i++){
        if((location[i+1]-location[i])>mid*2){
            return false;
        }
    }
    return true;
}

int binarySearch(int n, vector<int>& location){
    int left = 1;
    int right = n;
    int mid;
    int height=-1;
    
    while(left<=right){
        mid = (left+right)/2;
        
        if(is_possible(mid, location, n)){
            height=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }

    }
    return height;
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,m; //굴다리의 길이, 가로등 개수
    
    cin>>n>>m;
    vector<int> location(m);
    
    for(int i=0; i<m; i++){
        cin>>location[i];
    }
    
    cout<<binarySearch(n,location);
    
    
    return 0;
}
