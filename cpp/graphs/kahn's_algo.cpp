#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<vector<ll>> g;
vector<ll> topo;
vector<ll> indeg;

void kahn_lexicographic()
{
    priority_queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(-i);
    }

    while (!q.empty())
    {
        ll cur = -q.top();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(-v);
        }
    }
}

int main()
{
    cin >> n >> m;
    ll a, b;
    indeg.assign(n + 1, 0);
    g.resize(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    kahn_lexicographic();
    // reverse(topo.begin(), topo.end());
    if (topo.size() != n)
        cout << -1;
    else
    {
        for (ll i = 0; i < n; i++)
        {
            cout << topo[i] << " ";
        }
    }

    return 0;
}