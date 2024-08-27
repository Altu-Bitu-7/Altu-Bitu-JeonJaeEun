#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";

    while (q.size() > 1) {
        // k-1번 큐의 앞 요소를 뒤로 이동
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop(); 
        }
        cout << q.front() << ", "; //제거할 요소 출력
        q.pop();
    }

    cout << q.front() << ">\n";
}
