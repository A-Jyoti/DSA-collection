#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_cycle;
ll n, m;
vector<vector<ll>> g;
vector<ll> vis;
vector<ll> parent;

void dfs(ll node, ll par){
    vis[node] = 2;
    parent[node] =par;

    for(auto v: g[node]){
        // if(v == parent[node]) continue;//for undirected only
        if(vis[v] == 1){
            dfs(v, node);
        }else if(vis[v] == 2){
            is_cycle = true;
        }
        //for one way
        else if(vis[v] == 3){
            //cross edge
        }
    }

    //for direccted
    vis[node] = 3;

}

int main(){
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> m;
    ll a,b;
    g.resize(n+1);
    for(int i= 1; i<=m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        // g[b].push_back(a);
    }

    vis.assign(n+1, 1);
    parent.assign(n+1,0);

    for(int i =1; i<=n; i++){
        if(vis[i] == 1) dfs(i, parent[i]);
    }

    if(is_cycle == true) cout << "Yes";
    else cout << "No";
    }

    return 0;
}