#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string,string> M;
vector<string> result;

bool cmp(string a1, string a2){
    return a1>a2;
}
int main(){
    int n;
    cin >> n;
    string name, cond;

    while(n--){
        cin >> name >> cond;
        if(cond=="enter"){
            M[name] = cond;
        }else{ // cond=="leave"
            M.erase(name);
        }
    }
    for(auto e:M){
        result.push_back(e.first);
    }

    sort(result.begin(), result.end(),cmp);

    for(auto e:result){
        cout << e << '\n';
    }
    return 0;
}