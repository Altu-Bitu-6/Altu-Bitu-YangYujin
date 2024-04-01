#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcStairs(int n, vector<int>& score){
    vector<int> dp(n);
    
    dp[0]=score[0];
    dp[1] = max(score[0]+score[1], score[1]);
    dp[2] = max(score[0]+score[2], score[1]+score[2]);
    
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }
    
    return dp[n-1];
    
}

int main()
{
    int n;
    
    cin>>n;
    vector<int> score(n);

    
    for(int i=0; i<n; i++){
        cin>>score[i];        
    }
    
    cout<<calcStairs(n, score);

    return 0;
}
