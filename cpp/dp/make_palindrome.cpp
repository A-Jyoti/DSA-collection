// Given a string 
// s
// s, find the minimum number of characters that need to be inserted into the string to make it a palindrome.

#include <bits/stdc++.h>
using namespace std;

string s;
int dp[1010][1010];
int rec (int l, int r) {
    //pruning
    if(l >= r)
        return 0;
    //basecase

    //cache check
    if(dp[l][r] != -1)
        return dp[l][r];
    //transition
    int ans = 0;
    if(s[l] == s[r]) ans += rec(l+1, r-1);
    else ans += min(1 + rec(l+1, r), 1 + rec(l, r-1));
    //save and return
    return dp[l][r] = ans;
}

void solve() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    cout << rec(0, n-1) << endl;
}
int main(){
    solve();
    return 0;
}
