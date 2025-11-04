#include <bits/stdc++.h>
#define start first 
#define end second

using namespace std;

// .second (종료 시간)를 기준으로 오름차순 정렬합니다.
// 만약 종료 시간이 같다면, .first (시작 시간)를 기준으로 오름차순 정렬합니다.
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
 
pair<int, int> meetings[100000]; // <start, end>

int main() {
    int n;
    // ifstream cin("input.txt");

    cin >> n;

    int start, end;
    for(int i=0; i<n; i++) {
        cin >> start >> end;
        meetings[i] = {start, end};
    }

    sort(meetings, meetings+n, compare);

    int cnt = 0;
    pair<int, int> last;
    for(int i=0; i<n; i++) {
        auto [start, end] = meetings[i];

        if (i > 0 && meetings[i].start < last.end) continue;
        last = {start, end};
        // cout << "(" << start << ", " << end << ")" << endl;

        cnt++;
    }

    cout << cnt;

}