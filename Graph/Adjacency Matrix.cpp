#include <iostream>
#include <stack>
using namespace std;
#define MAX_V 100
void dfs(int node, bool graph[MAX_V][MAX_V], bool visited[MAX_V], int V)
{
    visited[node] = true;
    for (int i = 0; i < V; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            dfs(i, graph, visited, V);
        }
    }
}
bool isStronglyConnected(bool graph[MAX_V][MAX_V], int V)
{
    bool visited[MAX_V];
    fill(visited, visited + V, false);
    dfs(0, graph, visited, V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }
    bool reversedGraph[MAX_V][MAX_V] = {false};
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            reversedGraph[j][i] = graph[i][j];
        }
    }
    fill(visited, visited + V, false);
    dfs(0, reversedGraph, visited, V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}
int main()
{
    int V = 4;
    bool graph[MAX_V][MAX_V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};

    if (isStronglyConnected(graph, V))
    {
        cout << "The graph is strongly connected." << endl;
    }
    else
    {
        cout << "The graph is not strongly connected." << endl;
    }
    return 0;
}