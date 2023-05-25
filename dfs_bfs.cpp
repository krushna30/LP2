#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pll;
typedef vector<int> vi;
typedef vector<long long int> vll;

void dfs(vector<bool> &vis, vector<int> G[], int node)
{
    vis[node] = 1;
    cout << node << " ";

    for (auto &i : G[node])
    {

        if (!vis[i])
        {
            vis[i] = 1;
            dfs(vis, G, i);
        }
    }
}
void bfs(queue<int> &q, vector<bool> &vis, vector<int> G[])
{
    if (q.empty())
        return;
    int node = q.front();
    q.pop();
    cout << node << " ";
    vis[node] = 1;

    for (auto &i : G[node])
    {

        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    bfs(q, vis, G);
}
signed main()
{

    int n;
    cout << "Enter no of nodes of the graph \n";
    cin >> n;

    vector<int> G[n + 1];

    cout << "enter no of edges of the graph :-";
    int ed;
    cin >> ed;

    for (int i = 0; i < ed; i++)
    {
        int u, v;
        cout << "Enter the src , dest  :-\n";
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> ch(n + 1, 0);
    cout << "Enter the starting node:-\n";
    int st;
    cin >> st;
    dfs(ch, G, st);
    cout << endl;

    queue<int> q;
    cout << "Enter the starting node for bfs:-\n";
    vector<bool> ch2(n + 1, 0);
    cin >> st;
    q.push(st);
    bfs(q, ch2, G);
}