#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool is_used[10];

void print(int k) {
    // cout << "k: "<< k << "\n";
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        // cout << "(k,i): "<< k << ", "<<i<<", "<<is_used[i]<< "\n";
        if(is_used[i]) continue;

        arr[k] = i;
        is_used[i] = true;
        print(k+1);
        is_used[i]=false;
    }
}

int main()
{
    // ifstream cin("input.txt");
    cin >> n >> m;

    print(0);
}