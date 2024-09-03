#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    string str;

    while(1){
        getline(cin, str);

        if(str == ".")
            break;

        stack<char> balance;
        bool flag = false;

        for(int i = 0; i < str.length(); i++){
            // ( , [ push
            if(str[i]=='(' || str[i] == '['){
                balance.push(str[i]);
            }
            // ) 가 들어온 경우
            else if(str[i] == ')'){
                // stack이 비어있지 않고, top = ( 이면 pop
                if(!balance.empty() && balance.top() == '('){
                    balance.pop();
                }
                else{
                    flag = true;
                    break;
                }
            }

            else if(str[i] == ']'){
                if(!balance.empty() && balance.top() == '['){
                    balance.pop();
                }
                else{
                    flag = true;
                    break;
                }
            }
        }

        if(balance.empty() && flag == false){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }
}