#include <bits/stdc++.h>

using namespace std;

int board[8][8];
vector<pair<int,int>> cctv; //cctv 위치 좌표를 저장하고 있는 list
int n,m;
int result=100;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void func(int k){
    if(k==cctv.size()){ // 모든 cctv에 대해서 처리했으면 사각지대 면적 카운팅하고 return;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0) cnt++;
            }
        }
        if(cnt < result) result = cnt;
        return;
    }

    pair<int,int> cur = cctv[k];
    int cur_type = board[cur.first][cur.second];

    // 현재 상태의 board를 백업할 임시 변수 선언
    int backup_board[8][8];

    if(cur_type == 1){
        for(int dir=0; dir<4;dir++){
            // board backup
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    backup_board[i][j] = board[i][j];

            int nx = cur.first;
            int ny = cur.second;

            while(true){
                nx += dx[dir];
                ny += dy[dir];

                // 범위 벗어나거나, 벽(6) 만나면 중단
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if(board[nx][ny] == 6) break;

                if(board[nx][ny] == 0) board[nx][ny] = -1;
                
            }
            func(k+1);
            // board 원상복구 = 백업본으로 덮어쓰기
            for(int i=0; i<n; i++)  
                for(int j=0; j<m; j++)
                    board[i][j] = backup_board[i][j];
            }
    }else if(cur_type ==2){
        for(int dir=0;dir<2;dir++){
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    backup_board[i][j] = board[i][j];

            for(int i=0;i<2;i++){
                int d = i+2*dir;
                int nx = cur.first;
                int ny = cur.second;

                while(true) {
                    nx += dx[d];
                    ny += dy[d];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) break; 
                    if(board[nx][ny] == 6) break; 
                    if(board[nx][ny] == 0) board[nx][ny] = -1;
                }
            }

            func(k + 1);

            // 원상복구
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    board[i][j] = backup_board[i][j];
        }
    }// Type 3: 직각 (ㄴ 모양)
    else if(cur_type == 3){
        // 현재 dx,dy 순서(남,북,동,서)에 맞춰 직각 쌍을 정의
        // {북,동}, {동,남}, {남,서}, {서,북}
        int pairs[4][2] = {{1, 2}, {2, 0}, {0, 3}, {3, 1}};

        for(int dir=0; dir<4; dir++){
            // 백업
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    backup_board[i][j] = board[i][j];

            // 두 방향에 대해 빔 발사
            for(int i=0; i<2; i++){
                int d = pairs[dir][i];
                int nx = cur.first;
                int ny = cur.second;
                while(true){
                    nx += dx[d];
                    ny += dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                    if(board[nx][ny] == 6) break;
                    if(board[nx][ny] == 0) board[nx][ny] = -1;
                }
            }
            func(k+1);
            // 복구
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    board[i][j] = backup_board[i][j];
        }
    }
    // Type 4: 세 방향 (ㅗ 모양)
    else if(cur_type == 4){
        // {남,북,서}, {북,동,서}, {남,동,서}, {남,북,동} ... 
        // 0:남, 1:북, 2:동, 3:서
        int triplets[4][3] = {{0, 1, 3}, {1, 2, 3}, {0, 2, 3}, {0, 1, 2}};

        for(int dir=0; dir<4; dir++){
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    backup_board[i][j] = board[i][j];

            for(int i=0; i<3; i++){
                int d = triplets[dir][i];
                int nx = cur.first;
                int ny = cur.second;
                while(true){
                    nx += dx[d];
                    ny += dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                    if(board[nx][ny] == 6) break;
                    if(board[nx][ny] == 0) board[nx][ny] = -1;
                }
            }
            func(k+1);
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    board[i][j] = backup_board[i][j];
        }
    }
    // Type 5: 전 방향 (+)
    else{ // cur_type == 5
        // 5번은 회전할 필요 없이 한 번만 실행하면 됨
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                backup_board[i][j] = board[i][j];
        
        // 4방향 모두 발사
        for(int dir=0; dir<4; dir++){
            int nx = cur.first;
            int ny = cur.second;
            while(true){
                nx += dx[dir];
                ny += dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
                if(board[nx][ny] == 6) break;
                if(board[nx][ny] == 0) board[nx][ny] = -1;
            }
        }
        func(k+1);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                board[i][j] = backup_board[i][j];
    }

    
}

int main(){
    cin >> n>> m;

    for(int i=0;i<n;i++){ // board assignment
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] !=0 && board[i][j] != 6){
                cctv.push_back({i,j});
            }
        }
    }

    func(0);

    cout << result;

    return 0;
}
