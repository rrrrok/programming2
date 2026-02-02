#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    list<int> L;
    for (int i=1;i<=N;i++){
        L.push_back(i);
    }

    list<int>::iterator iter = L.begin();

    cout <<'<';
    while(1){
        for (int i=0; i<K-1;i++){
            iter++;
            if(iter ==L.end()){
                iter = L.begin();
            }
        }
        cout << *iter;
        iter = L.erase(iter);

        if(iter == L.end()){
            iter = L.begin();
        }
        if(!L.empty()){
            cout <<", ";
        }

        if(L.empty()){
            break;
        }
    }
    cout <<'>';

    return 0;
}