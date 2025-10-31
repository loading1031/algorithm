#include <bits/stdc++.h>
using namespace std;

int n[20];
int N, S;
int cnt = 0;        // 조건에 맞는 부분 수열 수

void sum(int k, int result, bool isAdd)
{
    if (k == N)
    {
        if(result == S) {
            cnt++;
        }
        return;
    }

    sum(k+1, result+n[k], true);
    sum(k+1, result, false); 
}

int main()
{
    // ifstream cin("input.txt");

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    sum(0, 0, false);

    if(!S && cnt > 0) {
        cout << cnt-1;
        return 0;
    }
    cout << cnt;
}