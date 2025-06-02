#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
#define mp make_pair
using ii = pair<ll, int>;
vector<vector<ii>> g;
//we are having forwardbranches as weight 0 and reverse branch as weight 1

vector<ll> dis;
void bfs01(ll sc_node){
    for(ll i =1; i<=n; i++){
        dis[i] = 1e9;
    }

    dis[sc_node] = 0;
    deque<ll> dq;
    dq.push_back(sc_node);

    while(!dq.empty()){
        ll cur_node = dq.front();
        dq.pop_front();
        for(auto v : g[cur_node]){
            ll neigh = v.first;
            int weight = v.second;
            if(dis[neigh] > dis[cur_node] + weight){
                dis[neigh] = dis[cur_node] + weight;
                if(weight == 1){
                    dq.push_back(neigh);
                }else {
                    dq.push_front(neigh);
                }
            }
        }
    }

}


int main(){
    int t;
    cin >> t;
    while(t--){
    cin >> n >> m;
    g.resize(n+1);
    dis.resize(n+1);
    for (ll i=0; i<m; i++){
        
        ll a, b;
        cin >> a >>b;
        if(a == b) continue;
        g[a].push_back(mp(b, 0));
        g[b].push_back(mp(a, 1));
    }
    bfs01(1);
    cout << ((dis[n] == 1e9) ? -1:dis[n]) << endl;
    }

}

