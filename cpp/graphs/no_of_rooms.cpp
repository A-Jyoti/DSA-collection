/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;

void dfs(int n, int m, int nx, int ny, vector<string>& arr, int label){
    vis[nx][ny] = label;

    int dx[] ={0, 1, 0, -1};
    int dy[] ={1, 0, -1, 0};
    vector<pair<int, int>> neighbour;
    for (int k =0; k<4; k++){
        int x = nx + dx[k];
        int y = nx + dy[k];
        if(x>=0 && x< n && y>=0 && y<m && arr[x][y] == '.'){
            neighbour.push_back(make_pair(x, y));
        }
    }

    for(auto v: neighbour){
        if(vis[v.first][v.second] == 0){
            dfs(n, m, v.first, v.second, arr, label);
        }
    }

}

int main(){

    int n, m;
    cin >> n >> m;

    vector<string> arr;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int label=1;

    vis.assign(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 0 && arr[i][j] == '.'){
                dfs(n, m, i, j, arr, label);
                label++;
                
            }
            cout << vis[i][j];
        }
        cout << endl;
    }

    cout << label;

    return 0;
}