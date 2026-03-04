#include <iostream>

using namespace std;

int main(){
    int n,k;

    cin >> n>>k;

    int c_pac=1;
    int k_pac=1;
    int c_k_pac=1;

    for(int i=1;i<=n;i++) {c_pac *= i;}
    for(int i=1;i<=k;i++) {k_pac *= i;}
    for(int i=1;i<=n-k;i++) {c_k_pac *= i;}

    cout << c_pac / k_pac / c_k_pac;
}