#include <bits/stdc++.h>

using namespace std;

int board[500][500];
int vis[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    cin >> m;
    int sum=0;
    int max_result=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    
    for(int r=0;r<n;r++){
        for(int s=0;s<m;s++){
            queue<pair<int,int>> Q;

            if(!vis[r][s] && board[r][s]){
                Q.push({r,s});
                vis[r][s] = 1;
                sum++;
            }
            
            int area = 0;

            while(!Q.empty()){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                area++;
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if( (nx<0) || (nx>=n) || (ny<0) || (ny>=m)) continue;
                    if( !board[nx][ny] || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
                
            }
            if(area>max_result) max_result = area;
        }
    }

    cout <<sum << '\n';
    cout <<max_result;

    return 0;
}