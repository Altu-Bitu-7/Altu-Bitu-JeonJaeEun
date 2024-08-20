#include <iostream>
#include <set>

using namespace std;

int main(){

    int n, m;
    cin>> n>> m;

    set<string> s;
    string input_str;

    for(int i = 0; i < n; i++){
        cin >> input_str;
        s.insert(input_str);
    }

    string test_str;
    int cnt  = 0;

    for(int i = 0; i < m; i++){
        cin >> test_str;
        //test_str이 집합 s에 1개 존재하면 포함되어 있다.
        if(s.count(test_str) == 1){
            cnt++;
        }
    }

    cout << cnt;
}