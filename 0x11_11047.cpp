#include <iostream>

using namespace std;
int N,K;
int sum;
int A[10];

int main(){
    cin >> N >> K;

    for(int i=0;i<N;i++){// arr init
        cin >> A[i];
    }

    //큰 돈부터 꽉꽉 채워나가면 됨.
    for(int i=N-1;i>=0;i--){
        while(K-A[i] >=0){
            K-=A[i];
            sum++;
        }
        if(K==0) break;
    }

    cout << sum;

    return 0;
}