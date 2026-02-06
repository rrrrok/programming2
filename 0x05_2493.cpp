#include <bits/stdc++.h>
 using namespace std;

stack<pair<int,int>> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    st.push({0,100000001});

    for(int i=1;i<=num;i++){
        int height;
        cin >> height;

        pair<int,int> tmp = {i,height};

        while(st.top().second < height){
            st.pop();
        }
        cout << st.top().first <<" ";
        st.push(tmp);
    }


    return 0;
}