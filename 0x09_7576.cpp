#include <bits/stdc++.h>

using namespace std;

int board[1000][1000];
int dist[1000][1000];
// dist -1이면 방문X, 0 이상이면 방문o

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;

    int m,n;
    cin >> m >> n;

    for(int i=0;i<n;i++){
        fill(dist[i],dist[i]+m,-1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1) {
                Q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if((nx <0)||(nx>=n)||(ny<0)||(ny>=m)) continue;
            if(dist[nx][ny]>=0 || board[nx][ny] <0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j] == -1 && board[i][j] !=-1){
                cout << -1;
                return 0;
            }
            answer = max(answer,dist[i][j]);
        }
    }
    cout << answer;

    return 0;
}