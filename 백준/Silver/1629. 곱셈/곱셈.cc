#include <bits/stdc++.h>
using namespace std;

int multiple(long a, long b, long c) {
    if(b == 0) return 1;
    if(b&1) return ((a%c)*(multiple(a,b-1,c)%c))%c;
    long result = multiple(a, b/2, c)%c;
    return (result*result)%c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ifstream cin("input.txt");
    long a,b,c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << multiple(a,b,c) << endl;
}