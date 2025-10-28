#include <bits/stdc++.h>
using namespace std;

void hanoitop(int from, int temp, int to, int count) {

    if(count==1){
        cout << from <<" "<<to<<'\n';
        return;
    }
    // 마지막 판을 제외한 모든 판을 보조 탑으로 이동
    hanoitop(from, to, temp, count-1);
    
    cout << from<<" "<<to<<'\n';

    hanoitop(temp,from,to,count-1);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ifstream cin("input.txt");
    int count;
    cin >> count;
    
    cout << (1LL<<count)-1LL << '\n';

    hanoitop(1, 2, 3, count);
}