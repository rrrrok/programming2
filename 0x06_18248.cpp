#include <bits/stdc++.h>

using namespace std;
queue<int> Q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while(num--){
        string cmd;
        cin >> cmd;

        if(cmd=="push"){
            int num;
            cin >> num;
            Q.push(num);
        }else if (cmd =="pop"){
            if(!Q.empty()){
                int num = Q.front();
                Q.pop();
                cout << num<<'\n';
            }else{
                cout << -1 <<'\n';
            }
        }else if (cmd =="size"){
            int num = Q.size();
            cout << num<<'\n';
        }else if (cmd =="empty"){
            if(!Q.empty()){
                cout << 0<<'\n';
            }else{
                cout << 1<<'\n';
            }
        }else if (cmd =="front"){
            if(!Q.empty()){
                int num = Q.front();
                cout << num<<'\n';
            }else{
                cout << -1<<'\n';
            }
        }else{ //back
            if(!Q.empty()){
                int num = Q.back();
                cout << num<<'\n';
            }else{
                cout << -1<<'\n';
            }
        }


    }

    return 0;
}