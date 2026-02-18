#include <iostream>

using namespace std;
int arr[20];
int used[20];
int cnt;
int s;
int n;

void func(int k, int total){
    if(k==n){ // 2^n개를 모두 확인하는 방법 중간에 끊지 않음
        if(total == s){
            cnt ++;
        }
        return;
    }

    // for문으로 다시 다 보는게 아니라 다음 요소들만 확인하는 방식
    func(k+1,total);
    func(k+1,total+arr[k]);
}

int main(){
    cin >> n >> s;

    for(int i=0;i<n;i++){ // arr assignment
        cin >> arr[i];
    }

    func(0,0);
    if(s==0) cnt--;
    cout << cnt;

    return 0;
}