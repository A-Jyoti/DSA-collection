#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int arr[210][210];
int dp[210][210][410];

int rec (int x, int y, int kleft){//kleft no. of walls are lest to be broken
    //pruning
    if(x < 0 || y < 0)
       return 0;
    if(arr[x][y] == 1 && kleft <=0)
        return 0;
    //base case
    if(x == 0 && y== 0){
        if(arr[0][0] == 1 && kleft == 0)
            return 0;
        else
            return 1;
    }
    //cache check
    if(dp[x][y][kleft] != -1)
        return dp[x][y][kleft];
    //transition
    int ans = 0;
    if(arr[x][y] == 0){
        ans += rec(x-1, y, kleft) + rec(x, y-1, kleft);
    }else{
        ans += rec(x-1, y, kleft-1) + rec(x, y-1, kleft-1);
    }
    //save and return
    return dp[x][y][kleft] = ans;

}
void solve(){
    cin >>n >>m >>k;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    

    cout << rec(n-1, m-1, k) << endl;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}