#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;

    while(num--){
        string tmp;
        cin >>tmp;
        list<char> L;
        list<char>::iterator iter = L.end();

        for(char c:tmp){
            if(c == '<'){
                if(iter != L.begin()) iter--;
            }
            else if(c=='>'){
                if(iter != L.end()) iter++;
            }else if(c=='-'){
                if(iter != L.begin()) L.erase(--iter);
            }else{
                L.insert(iter,c);
            }
        }
        for(char tmp2:L){
            cout <<tmp2;
        }
        cout <<'\n';
    }
    return 0;
}