#include <bits/stdc++.h>
using namespace std;

bool vis[15][15];
int n;
int result;

bool is_safe(int r, int c)
{
    // 제자리 및 위에 퀸이 있는지
    for (int i = 0; i < r; i++)
        if (vis[i][c])
            return false;

    // 좌상향 대각선에 퀸이 있는지
    for (int i = r - 1, ii = c - 1; i >= 0 && ii >= 0; i--, ii--)
    {
        if (vis[i][ii])
        {
            return false;
        }
    }
    // 우상향 대각선에 퀸이 있는지
    for (int i = r - 1, ii = c + 1; i >= 0 && ii < n; i--, ii++)
    {
        if (vis[i][ii])
        {
            return false;
        }
    }

    return true;
}

void queen(int k)
{
    if (k == n)
    {
        result++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!is_safe(k, i))
            continue;
        vis[k][i] = true;
        queen(k + 1);
        vis[k][i] = false;
    }
}

int main()
{
    // ifstream cin("input.txt");
    cin >> n;

    queen(0);
    cout << result;
}