#include <bits/stdc++.h>

using namespace std;

int board[100001];
// dist -1이면 방문X, 0 이상이면 방문o

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;

    int N,K;
    cin >> N >> K;


    fill(board,board+100002,-1);

    Q.push(N);
    board[N] = 0;
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        if(cur == K){
            cout << board[K];
            return 0;
        }

        // +1
        int nx = cur+1;
        if((nx>=0) && (nx < 100001) && (board[nx] < 0)){
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }

        // -1
        nx = cur-1;
        if((nx>=0) && (nx < 100001) && (board[nx] < 0)){
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }

        // *2
        nx = cur*2;
        if((nx>=0) && (nx < 100001) && (board[nx] < 0)){
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }
    }

    return 0;
}