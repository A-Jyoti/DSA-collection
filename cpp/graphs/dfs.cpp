#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector <vector<int>> g;

//DFS
vector<int> visited;
void dfs(int node, int label){
    visited[node] = label;
    for(auto v: g[node]){
        if(visited[v] != label){
            dfs(v, label);
        }
    }
}

int main(){
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);//directed graph
        g[b].push_back(a);//undirected graph
    }
    visited.resize(n + 1, 0);
    int label = 1;
    for (int i = 1; i <= n; i++){
        if(visited[i] ==0){
            dfs(i, label);
            label++;
        }
    }
    // for (int i = 1; i<=n; i++){
    //     cout << i << " : " << visited[i] << endl;
    // }

    //now counting of no. of nodes per component
    map <int, int> mp;
    for(int i =1; i<=n; i++){
        mp[visited[i]]++;
    }
    int steps = 0, sum = 0, sqsum = 0;
    for(int i =1; i<label; i++){
        sum += mp[i];
        sqsum += mp[i] * mp[i]; 
    }
    steps = ((sum*sum)-sqsum)/2;
    cout << steps;

}
