#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pll;
typedef vector<int> vi;
typedef vector<long long int> vll;

signed main()
{
    int n;
    cout << "ENter the no of nodes :-";
    cin >> n;

    vector<pair<int, int>> G[n + 1];

    cout << "Enter no of edges :-\n";
    int ed;
    cin >> ed;

    for (int i = 0; i < ed; i++)
    {
        int u, v, w;
        cout << "Enter src , dest and weight :-\n";
        cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INT_MAX);

    cout << "Enter the starting vertes :-";
    int st;
    cin >> st;

    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty())
    {

        pair<int, int> p = pq.top();
        int node = p.second;
        pq.pop();
        for (auto &i : G[node])
        {
            int v = i.second;
            int wt = i.first;
            if (dist[v] > dist[node] + wt)
            {
                dist[v] = dist[node] + wt;
                pq.push({dist[v], v});
            }
            // 1 2 2 1 3 1 2 4 4 2 5 1 3 5 5 4 6 1 5 6 6
        }
    }

    cout << "Distance is :-\n";
    for (auto &i : dist)
    {
        cout << i << " ";
    }

    cout << endl;
}