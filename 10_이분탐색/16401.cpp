#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과자를 mid 길이로 잘랐을 때 얻을 수 있는 조각의 총 개수를 계산하는 함수
int getNum(int mid, vector<int>& length){
    int cnt = 0;
    for(int i = 0; i < length.size(); i++){
        cnt += length[i] / mid; // 각 과자를 mid 길이로 잘랐을 때 얻을 수 있는 조각의 개수를 더함
    }
    return cnt;
}

// 이진 탐색을 통해 조카 1명에게 줄 수 있는 막대 과자의 최대 길이를 찾는 함수
int binarySearch(int left, int right, int key, vector<int>& length){
    int result = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        int childNum = getNum(mid, length); // 현재 mid 길이로 잘랐을 때 얻을 수 있는 조각의 총 개수
        
        if(childNum >= key){
            result = mid;
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n; // m=조카 수, n=과자 수
    
    cin >> m >> n;
    vector<int> length(n);
    
    for(int i = 0; i < n; i++){
        cin >> length[i];
    }
    
    sort(length.begin(), length.end(), greater<int>());
    
    cout << binarySearch(1, length[0], m, length);
    
    return 0;
}
