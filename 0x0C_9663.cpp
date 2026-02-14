#include <bits/stdc++.h>

using namespace std;

int board[14][14]; //모든 칸이 0으로 저장
int n;
int cnt;
int used[14]; // 사용된 열 저장하는 변수

void func(int k){
    if(k==n) { // k가 n행에 도달했으면 cnt++;
        cnt++;
        return;
    }

    for(int i=0;i<n;i++){ // i번째 열을 다루기 위한 변수.-
        if(!used[i]){ //사용하지 않은 열
            bool able = true;
            
            // 대각선 체크
            // j는 현재 행(k)에서 위쪽으로 떨어진 거리
            for(int j = 1; j <= k; j++){
                
                // 왼쪽 위 대각선 확인
                if(i - j >= 0){
                    if(board[k-j][i-j] == 1){ // 퀸이 있으면
                        able = false;
                        break; // 더 볼 필요 없음
                    }
                }
                
                // 오른쪽 위 대각선 확인
                if(i + j < n){
                    if(board[k-j][i+j] == 1){ // 퀸이 있으면
                        able = false;
                        break; // 더 볼 필요 없음
                    }
                }
            }
            if(able){
                board[k][i] = 1;
                used[i] = 1;
                func(k+1);
                board[k][i] = 0;
                used[i] = 0;
            }
        }
    }
}


int main(){
    cin >> n;

    func(0);

    cout << cnt;
    return 0;
}
