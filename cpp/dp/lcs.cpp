#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;
int dp[1010][1010];

int rec(int x, int y){
    //pruning
    //base case
    if(x == n || y == m)
        return 0;
    //cache check
    if(dp[x][y] != -1)
        return dp[x][y];
    //compute
    int ans = 0;
    ans = max(ans,rec(x, y+1));
    ans = max(ans,rec(x+1, y));
    if(s1[x] == s2[y])
        ans = max(ans, 1 + rec(x+1, y+1)); 
    //save and return
    return dp[x][y] = ans;
}

void solve(){
    cin >> s1 >> s2;
    n = s1.size(); m = s2.size();
    memset(dp, -1, sizeof(dp));
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++) cout << rec(i, j) <<endl;
    // }
    cout << rec(0,0)<< endl;
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}