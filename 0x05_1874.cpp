#include <bits/stdc++.h>
using namespace std;

stack<int> st;
list<char> l;
string result = "";

int main(){
    int num;
    cin >> num;
    int cnt=1;
    while(num--){
        int tmp;
        cin >> tmp;
        while(cnt<=tmp){
            st.push(cnt++);
            result += '+';
        }
        if(tmp!=st.top()){
            cout <<"NO\n";
            return 0;
        }
        st.pop();
        result += '-';
    }

    for(auto last : result){
        cout << last <<'\n';
    }

    return 0;
}