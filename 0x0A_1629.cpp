#include <iostream>

using namespace std;

long long func(int A, int B, int C){
    if(B==1){
        return A%C;
    }
    long long val = func(A,B/2,C);
    val = val * val % C;
    if(B%2 == 0 ) return val;
    return val * A % C;
}

int main(){
    int A,B,C;
    cin >> A >> B >> C;

    cout << func(A,B,C);

    return 0;
}

