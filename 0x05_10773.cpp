#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, result=0;
    cin >> num;
    stack<int> st;
    while(num--){
        int tmp;
        cin >> tmp;
        if(tmp==0){
            st.pop();
        }else{
            st.push(tmp);
        }

    }

    
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout <<result;

    return 0;
}