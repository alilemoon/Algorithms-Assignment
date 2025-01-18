#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define MAX 100
int disc[MAX], low[MAX], parent[MAX], timeCounter;
bool isArticulation[MAX];
bool isBridge[MAX][MAX];
bool visited[MAX];
void DFS(int u, int adj[MAX][MAX], int n)
{
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;
    for (int v = 0; v < n; v++)
    {
        if (adj[u][v])
        {
            if (!visited[v])
            {
                parent[v] = u;
                children++;
                DFS(v, adj, n);
                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                {
                    isArticulation[u] = true;
                }
                if (parent[u] != -1 && low[v] >= disc[u])
                {
                    isArticulation[u] = true;
                }

                if (low[v] > disc[u])
                {
                    isBridge[u][v] = isBridge[v][u] = true;
                }
            }
            else if (v != parent[u])
            {

                low[u] = min(low[u], disc[v]);
            }
        }
    }
}
bool isTwoEdgeConnected(int adj[MAX][MAX], int n)
{

    memset(visited, false, sizeof(visited));
    memset(isArticulation, false, sizeof(isArticulation));
    memset(isBridge, false, sizeof(isBridge));
    timeCounter = 0;
    DFS(0, adj, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] && isBridge[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isTwoVertexConnected(int adj[MAX][MAX], int n)
{
    memset(visited, false, sizeof(visited));
    memset(isArticulation, false, sizeof(isArticulation));
    timeCounter = 0;
    DFS(0, adj, n);
    for (int i = 0; i < n; i++)
    {
        if (isArticulation[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    int adj[MAX][MAX] = {0};
    cout << "Enter edges (u v) as 0-based indices:\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    if (isTwoEdgeConnected(adj, n))
    {
        cout << "The graph is two-edge connected.\n";
    }
    else
    {
        cout << "The graph is NOT two-edge connected.\n";
    }
    if (isTwoVertexConnected(adj, n))
    {
        cout << "The graph is two-vertex connected.\n";
    }
    else
    {
        cout << "The graph is NOT two-vertex connected.\n";
    }
    return 0;
}