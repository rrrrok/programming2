#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int N;

/*
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 
각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

각 로프들에 대한 정보가 주어졌을 때, 이 로프들로 들어올릴 수 있는
물체의 최대 중량 구해내야 함.

+모든 로프 사용할 필요 X
*/
bool cmp(const int & a, const int & b){
    return a>b;
}
int main(){
    cin >> N;
    int tmp;
    int max=0;
    for(int i=0 ; i<N; i++){//arr init
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end(),cmp);// arr sort 내림차순
/*
    만약 내림차순 크기순으로 정렬해둔다면,
    다음에 들어올 놈을 포함했을 때 결과가 좋아지면 넣고 아니면 다음
*/ 
    max = arr[0];

    for(int i=1; i<N; i++){
        //새로운 거 추가했을 때, 걔를 포함했을 때 전체가 더 커지는지 확인
        if(arr[i]*(i+1)>max){
            max = arr[i]*(i+1);
        }
    }

    cout << max;

    return 0;
}