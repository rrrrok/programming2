#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){    
    string str;

    cin >> str;
    int c[26] = {0};
    for (int i=0; i<str.size();i++){
        int tmp = str[i] -'a';
        c[tmp]++;
    }
    for (int tmp : c){
        cout << tmp << " ";
    }
}
