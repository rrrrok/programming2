#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,M;

vector<int> A;
vector<int> B;
void func(vector<int> A, int tmp){
    int left =0;
    int right = N-1;
    while(left<=right){
        int mid = left + (right-left)/2;

        if(A[mid]==tmp){
            cout << '1' << '\n';
            return;
        }else if(A[mid]<tmp){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    cout << '0' << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num_tmp;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num_tmp;
        A.push_back(num_tmp);
    }
    sort(A.begin(),A.end()); // 오름차순 정렬

    cin >> M;

    for(int i=0;i<M;i++){
        cin >> num_tmp;
        B.push_back(num_tmp);
    }

    //여기부터 M에 있는 숫자를 하나씩 검증하면 됨 
    //N에 가져가서 이분탐색으로 찾기

    for(int i=0 ;i<M;i++){
        func(A,B[i]);
    }

    return 0;
}