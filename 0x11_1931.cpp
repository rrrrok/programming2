#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> arr;

bool cmp(const pair<int,int> a, const pair<int,int> b){
    if(a.second==b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    int sum=0;
    int tmp1, tmp2;
    cin >> N;

    for(int i=0;i<N;i++){// arr init 끝나는 시간이 빠른 순서대로 정렬, 같다면 시작시간이 빠른 순서대로(이건 의미 없어보이긴함)
        cin >> tmp1 >> tmp2;
        arr.push_back({tmp1,tmp2});
    }

    sort(arr.begin(),arr.end(),cmp); // arr sort

    int begin=0, end=0;

    for(int i=0;i<N;i++){ 
        if(arr[i].first >= end){ // 시작 시간이 지금 진행중인 회의의 끝나는 시간보다 크거나 같으면 ㄱㄴ
            begin = arr[i].first;
            end = arr[i].second;
            sum++; // 회의 개수 1증가
        }
    }

    cout << sum;
    
    return 0;
}