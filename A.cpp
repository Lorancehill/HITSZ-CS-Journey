#include<bits/stdc++.h>
using namespace std;

int L, n, m;
int a[50005];
bool check(int mid){
    int cnt = 0;
    int last = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] - last < mid){
            cnt++;
        }
        else{
            last = a[i];
        }
    }
    if (L -last < mid){
        cnt++;
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> L >> n >> m;
     int l = 1, r = L;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (l < r){
        int mid = l + (r - l + 1) / 2;
        if (check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}