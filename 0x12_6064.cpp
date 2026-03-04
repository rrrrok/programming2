#include <iostream>

using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int func(int M, int N, int x, int y){
    if(x==M) x=0;
    if(y==N) y=0;

    int l = lcm(M,N);

    for(int i=x; i<=l;i+=M){
        if(i==0) continue;
        if(i % N ==y)
            return i;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Num;
    int M, N, x, y;
    cin >> Num;
    while(Num--){
        cin >> M >> N >> x >> y;
        cout << func(M,N,x,y)<<'\n';
    }

}
