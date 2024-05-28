#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 19;
int back_x, back_y;

bool inBoard(int x, int y){
    if(x>=0 && x<SIZE && y>=0 && y<SIZE){
        return true;
    }
    else{
        return false;
    }
}

bool findFive(int x, int y, vector<vector<int>>& set){
    int dx[4] = {1,0,-1,1};
    int dy[4] = {0,1,1,1};
    
    if(set[x][y]==0){
        return false;
    }

    
    for(int i=0; i<4; i++){
        

        int cnt=1;

        int next_x = x+dx[i];
        int next_y = y+dy[i];
        
        while(inBoard(next_x, next_y)&&(set[x][y]==set[next_x][next_y])){
            cnt++;
            next_x+=dx[i];
            next_y+=dy[i];
        }
        
        back_x = x-dx[i];
        back_y = y-dy[i];
        
        while(inBoard(back_x, back_y) && (set[back_x][back_y]==set[x][y])){
            cnt++;
            back_x-=dx[i];
            back_y-=dy[i];
        } 

        back_x+=dx[i];
        back_y+=dy[i];
        

        if(cnt == 5){
            return true;
        }
            

    }
    return false;


}

int main(){
    
    vector<vector<int>> set(SIZE, vector<int>(SIZE,0));
    
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin>>set[i][j];
        }
    }
    
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(findFive(i, j, set)){
                cout<<set[i][j]<<endl;
                cout<<back_x+1<<" "<<back_y+1;
                return 0;
            }
        }
    }
    
    cout<<0<<endl;
    
    return 0;
}