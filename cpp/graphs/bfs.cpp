#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<ll>> arr;
using state = pair<ll, ll>;

#define F first
#define S second

vector<vector<ll>> vis;
vector<vector<ll>> dis;

// to check node is valid or not
bool is_valid(ll x, ll y){
    if((x>=0 && x<n && y>=0 && y<m) && arr[x][y] == 0) return 1;
    else return 0;
}

vector<state> neighbours(state node){
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    ll x,y;
    vector<state> neighs;
    for(int k=0; k<4; k++){
        x = node.F + dx[k];
        y = node.S + dy[k]; 
        if(is_valid(x, y)){
            neighs.push_back({x, y});
        }
    }
    return neighs;
}


void bfs (state sc_node){
    queue<state> q;
    q.push(sc_node);
    vis[sc_node.F][sc_node.S] = 1;
    dis[sc_node.F][sc_node.S] = 0;

    ll size = 1; //as one 0 enters
    while(!q.empty()){
        state node = q.front();
        q.pop();
        // vector<state> neighs = neighbours(node);
        for(auto v: neighbours(node)){
            // cout << neighs.size();
            if(vis[v.F][v.S] == 0){
                vis[v.F][v.S] = 1,size++;
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                q.push(v);

            }
        }


    }

// Once more bfs to replace the 0s of the arr with the size
    // vis array marked 2 for those whose size is mentioned already
    q.push(sc_node);
    vis[sc_node.F][sc_node.S] = 2;
    if (size>1) arr[sc_node.F][sc_node.S] = size;
    while(!q.empty()){
        state node = q.front();
        q.pop();

        for(auto v: neighbours(node)){
            if(vis[v.F][v.S] == 1){
                vis[v.F][v.S] = 2, arr[v.F][v.S] = size;
                q.push(v);
            }
        }

    }

}

int main(){
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        arr.resize(n);
        for(ll i=0; i<n; i++){
            arr[i].resize(m);
            for(ll j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }
        vis.assign(n, vector<ll>(m,0));
        dis.assign(n, vector<ll>(m,1e7));

        state st = {0, 0};
        for(int i =0; i<n; i++){
            for (int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0 && is_valid(i, j)) bfs({i, j});
            }
        }


        for(int i =0; i<n; i++){
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;

        }
    }


    return 0;
}