#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<pair<int, int>> *G;

public:
    Graph(int V)
    {
        v = V;
        G = new vector<pair<int, int>>[v + 1];
        // cout<<v<<endl;
    }

    void addedge(int u, int v, int w)
    {
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    };

    vector<int> dijkstra(int src)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(v + 1, INT_MAX);

        q.push({0, src});
        dist[src] = 0;
        while (!q.empty())
        {
            int u = q.top().second;

            q.pop();

            for (auto &i : G[u])
            {
                int v = i.first;
                int wt = i.second;

                if (dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    q.push({dist[v], v});
                }
            }
        }

        return dist;
    };
};

int main()
{
    cout << "Enter the no of vertices :\n";
    int v, ed;
    cin >> v;
    Graph obj(v);
    cout << "Enter the no of edges :-";
    cin >> ed;
    for (int i = 0; i < ed; i++)
    {
        int src, dest, wt;
        cout << "Enter src , dest and weight  :";
        cin >> src >> dest >> wt;
        obj.addedge(src, dest, wt);
    }
    cout << "Enter start vertex :- ";
    int start;
    cin >> start;
    vector<int> dist = obj.dijkstra(start);
    int j = 0;
    cout << "vertex     Distance" << endl;
    for (auto &i : dist)
    {
        cout << j << setw(12) << i << endl;
        j++;
    }

    return 0;
}
