#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    cin >> tmp;

    list<char> L;

    for(char e : tmp){
        L.push_back(e);
    }

    list<char>::iterator it = L.end();
    
    int cnt=0;
    cin >> cnt;

    while(cnt--){
        char first;
        cin >> first;

        if (first == 'P'){
            char second;
            cin >> second;
            L.insert(it,second);
        }else if (first == 'L'){
            if(it != L.begin())
                it--;
        }else if (first == 'B'){
            if(it != L.begin()){
                it--;
                it = L.erase(it);
            }    
        }else{
            if(it != L.end())
                it++;
        }
    }
    for (char e : L){
        cout << e;
    }
    return 0;
}