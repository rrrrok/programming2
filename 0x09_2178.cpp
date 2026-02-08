#include <bits/stdc++.h>

using namespace std;
int board[100][100];
int vis[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


int main(){
    int n,m;
    cin >> n;
    cin >> m;

    //board initilization
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line; // "110110" 형태의 문자열 한 줄을 읽음
        for (int j = 0; j < m; j++) {
            board[i][j] = line[j] - '0'; // 문자를 숫자로 변환 ('1' -> 1)
        }
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0]=1;
    
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if( (nx<0)||(nx>=n)||(ny<0)||(ny>=m)) continue; //범위이탈
            if(!board[nx][ny]||vis[nx][ny]) continue; //길이 아니거나 방문한적있거나

            vis[nx][ny] = 1;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    
    cout << board[n-1][m-1];

    return 0;
}