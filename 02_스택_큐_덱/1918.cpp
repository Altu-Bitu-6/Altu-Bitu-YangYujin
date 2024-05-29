#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int weight(char c){
    switch(c){
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

vector<char> strToChar(string& str){
    vector<char> v;

    for(int i=0; i<str.length(); i++){
        v.push_back(str[i]);
    }
    
    
    return v;
}

vector<char> postfix(vector<char>& vchar){
    stack<char> st;
    vector<char> result;
    for(int i=0; i<vchar.size(); i++){
        switch(vchar[i]){
            case '+':
            case '-':
            case '*':
            case '/':
                while(!st.empty()&&weight(vchar[i])<=weight(st.top())){
                    result.push_back(st.top());
                    st.pop();
                }
                st.push(vchar[i]);
                break;
            
            case '(':
                st.push('(');
                break;
            case ')':
                while(st.top()!='('){
                    result.push_back(st.top());
                    st.pop();
                }
                st.pop();
                break;
            
            
                
            default:
                result.push_back(vchar[i]);
                break;
        }
        
    }
    
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
    
}

int main() {
    string str;
    cin>>str;
    
    vector<char> vchar = strToChar(str);
    vector<char> result = postfix(vchar);
    
    for(auto i : result){
        cout<<i;
    }

    return 0;
}
