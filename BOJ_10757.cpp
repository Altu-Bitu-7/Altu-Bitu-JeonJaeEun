#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int toNum(char ch){
    return ch - '0';
}

// 큰 수 저장할 문자열 배열
char A[10005], B[10005];
// 숫자로 변환된 역순 배열
int Ain[10005], Bin[10005];
// 두 수를 더한 결과 저장
int S[10005];

int main(){
    cin >> A >> B;

    int a_len = strlen(A);
    int b_len = strlen(B);
    int cnt = 0;

    //숫자로 변경
    for(int i = a_len - 1; i >= 0; i--)
        Ain[cnt++] = toNum(A[i]);
    cnt = 0;
    for(int i = b_len - 1; i >= 0; i--)
        Bin[cnt++] = toNum(B[i]);

    int sum, num;
    for(int i = 0; i < max(a_len, b_len); i++){
        sum = Ain[i] + Bin[i];
        // 이전 자리에서 올려준 값 + 현재 자리
        num = S[i] + sum;

        //더한 값이 10보다 크면
        if(num >= 10){
            S[i] = num - 10;
            S[i+1] += 1;
        }

        //더한 값이 10보다 작으면
        if(num < 10)
            S[i] = num;
    }

    int over = 0;
    // 최상위 자리에서 자리 올림 X
    if(S[max(a_len, b_len)] == 0){
        over = 1;
    }

    // 역순 출력
    for(int i = max(a_len, b_len) - over; i >= 0; i--){
        cout << S[i];
    }
    cout << '\n';
}