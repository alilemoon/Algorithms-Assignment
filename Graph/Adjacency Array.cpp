#include <iostream>
#include <stack>
using namespace std;
#define MAX_V 100
#define MAX_E 100
void dfs(int node, int graph[MAX_V][MAX_V], bool visited[MAX_V], int V)
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
bool isStronglyConnected(int graph[MAX_V][MAX_V], int V)
{
    bool visited[MAX_V];
    fill(visited, visited + V, false);
    dfs(0, graph, visited, V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }
    int reversedGraph[MAX_V][MAX_V] = {0};
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
    int graph[MAX_V][MAX_V] = {0};
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][0] = 1;
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