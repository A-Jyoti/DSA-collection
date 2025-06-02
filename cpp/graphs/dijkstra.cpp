#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define mp make_pair

ll n, m;
vector<vector<pll>> g;
vector<ll> dis;
vector<ll> vis;

void dijkstra(ll sc_node){
    dis[sc_node] = 0;
    priority_queue<pll> pq;
    pq.push(mp(-0, sc_node));

    while(!pq.empty()){
        pll cur = pq.top();
        ll cur_w = -cur.first;
        ll cur_n = cur.second;
        pq.pop();
        if(vis[cur_n] == 1) continue;
        vis[cur_n] =1;
        for(auto v: g[cur_n]){
            ll neigh = v.second;
            ll weight = v.first;
            
            if(dis[neigh] > dis[cur_n] + weight){
                dis[neigh] = dis[cur_n] + weight;
                pq.push(mp(-dis[neigh], neigh));
            }
        }
    }

}

int main(){
    cin >> n >> m;
    g.resize(n+1);
    dis.assign(n+1, 1e9);
    vis.assign(n+1, 0);
    for(ll i = 1; i<=m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(mp(c, b));
    }
    dijkstra(1);
    for(ll i =1; i<=n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}