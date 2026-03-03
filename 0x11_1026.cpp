#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;

bool cmp1(const int & a, const int & b){
    return a<b; //오름차순
}
bool cmp2(const int & a, const int & b){
    return a>b; //내림차순
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp;
    int sum=0;

    for(int i=0; i<N;i++){
        cin >> tmp;
        A.push_back(tmp);
    }

    for(int i=0; i<N;i++){
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end(), cmp1); //A 오름차순
    sort(B.begin(), B.end(), cmp2); //B 내림차순

    for(int i=0; i<N;i++){
        sum += A[i]*B[i];
    }

    cout << sum;

    return 0;
}