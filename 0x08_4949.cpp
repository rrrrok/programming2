#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string tmp;
        getline(cin,tmp);

        if(tmp == "."){
            return 0; //종료 조건
        }

        stack<char> parenthesis;
        bool isValid = true;

        for(char c : tmp){
            if(c=='[' || c=='('){
                parenthesis.push(c);
            }else if(c==')'){
                if(parenthesis.empty()||parenthesis.top() !='('){
                    isValid = false;
                    break;
                }
                parenthesis.pop();
            }else if(c==']'){
                if(parenthesis.empty()||parenthesis.top() !='['){
                    isValid = false;
                    break;
                }
                parenthesis.pop();
            }

        }
        if (isValid && parenthesis.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

