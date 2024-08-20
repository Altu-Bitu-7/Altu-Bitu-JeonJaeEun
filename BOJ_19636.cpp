#include <iostream>
#include <cmath>
using namespace std;

/*
    1. 일일 기초대사량 변화 반영하지 않는 경우
     w += 일일 에너지 섭취량 - (일일 기초대사량 + 활동 대사량)
    
    2. 일일 기초대사량 변화 반영한 경우
     w += 일일 에너지 섭취량 - (일일 기초대사량 + 활동 대사량)
     if, |일일 에너지 섭취량 - 일일 에너지 소비량| > t, 
        일일 기초대사량은 (일일 에너지 섭취량 - 일일 에너지 소비량) / 2 만큼 더해짐
*/

int main(){

    int w, before_l, T; //다이어트 전 체중, 에너지 섭취량(기초대사량), 기초대사량 역치
    cin >> w >> before_l >> T; 

    int day, diet_l, diet_a; //다이어트 기간, 에너지 섭취량, 활동 대사량
    cin >> day >> diet_l >> diet_a;

    // 일일 기초 대사량 변화 반영 X
    int after_w = 0; //다이어트 후 체중

    double tmp = 0;
    for(int i = 0; i < day; i++){
        tmp += (diet_l - (before_l + diet_a));
    }
    after_w = w + tmp;

    if(after_w <= 0){
        cout << "Danger Diet" <<'\n';
    }
    else{
        cout << after_w << " " << before_l << '\n';
    }

    // 일일 기초 대사량 변화 반영 O
    int before_l2 = before_l;
    int after_w2 = 0;

    double tmp2 = 0;
    for(int i = 0; i < day; i++){
        tmp2 += (diet_l - (before_l2 + diet_a));
        if(abs(diet_l - (before_l2 + diet_a)) > T){
            before_l2 += floor((diet_l - (before_l2 + diet_a)) / 2.0);
        }
    }
    after_w2 = w + tmp2;

    string st;
    if(after_w2 <= 0 || before_l2 <= 0){
        cout << "Danger Diet";
    }
    else{
        if(before_l - before_l2 > 0){
            st = "YOYO";
        }
        else{
            st = "NO";
        }
        cout << after_w2 << " " << before_l2 << " " << st;
    }
}