#include <iostream>
#include <vector>

using namespace std;

int main() {
    int wheel_num, wheel_cnt; // 바퀴 칸 수, 바퀴 돌리는 횟수
    cin >> wheel_num >> wheel_cnt;

    vector<char> wheel(wheel_num, '?'); // 바퀴 칸 배열 (?로 초기화)
    vector<bool> letter_used(26, false); // 알파벳 사용 여부 판단
    int current_pos = 0; // 현재 화살표가 가리키는 위치

    int num;
    char alp;

    while (wheel_cnt--) {
        cin >> num >> alp; // 몇 칸 돌리는지, 바퀴가 멈췄을 때 화살표가 가리키는 문자
        num %= wheel_num;
        current_pos -= num; // 시계방향으로 회전
        if (current_pos < 0) {
            current_pos += wheel_num; // 음수 방지
        }

        // 행운의 바퀴가 없는 경우
        // 이미 다른 문자가 존재하거나 해당 문자가 다른 곳에서 사용된 경우
        if ((wheel[current_pos] != '?' && wheel[current_pos] != alp) || (letter_used[alp - 'A'] && wheel[current_pos] != alp)) {
            cout << "!";
            return 0; // 바로 종료
        }

        // 현재 위치에 문자 배치
        wheel[current_pos] = alp;
        letter_used[alp - 'A'] = true;
    }

    // 최종 바퀴 상태 시계 방향으로 출력
    for (int i = 0; i < wheel_num; i++) {
        cout << wheel[(current_pos + i) % wheel_num];
    }

    return 0;
}
