#include <bits/stdc++.h>
using namespace std;

long z(int N, int r, int c)
{
    // 2x2만 남은 경우
    if (N == 1)
    {
        // cout << "출력 테스트:" << r << c << endl;
        if (r == 0 && c == 0)
        {
            // cout << 0;
            return 0;
        }
        if (r == 0 && c == 1)
        {
            // cout << 2;
            return 1;
        }
        if (r == 1 && c == 0)
        {
            // cout << 2;
            return 2;
        }
        // cout << 3;
        return 3;
    }
    // 구하고자 하는 (r,c)가 위치한 사분면만 재귀한다
    // 이를 위해, 각 중간점(p)과 비교한다.
    long p = pow(2, (N - 1));

    if (r < p && c < p)
    {
        return z(N - 1, r, c);
    }

    else if (r < p && p <= c)
    {
        // cout << p << "*" << p << " +(1) ";
        return p * p + z(N - 1, r, c - p);
    }
    else if (p <= r && c < p)
    {
        // cout << 2 << "*" << p << "*" << p << " +(2) ";
        return 2 * p * p + z(N - 1, r - p, c);
    }
    else
    {
        // cout << 3 << "*" << p << "*" << p << " +(3) ";
        return 3 * p * p + z(N - 1, r - p, c - p);
    }
}

int main()
{
    // ifstream cin("input.txt");
    int N, r, c;
    cin >> N >> r >> c;
    cout << z(N, r, c);
}