#include <iostream>
#include <stack>
using namespace std;
#define MAX_V 100
#define MAX_E 100
void dfs(int node, bool graph[MAX_V][MAX_E], int adjList[MAX_V], bool visited[MAX_V], int V)
{
    visited[node] = true;
    for (int i = 0; i < adjList[node]; i++)
    {
        int neighbor = graph[node][i];
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, adjList, visited, V);
        }
    }
}
bool isStronglyConnected(bool graph[MAX_V][MAX_E], int adjList[MAX_V], int V)
{
    bool visited[MAX_V];
    fill(visited, visited + V, false);
    dfs(0, graph, adjList, visited, V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }
    bool reversedGraph[MAX_V][MAX_E];
    int reversedAdjList[MAX_V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adjList[i]; j++)
        {
            int u = graph[i][j];
            reversedGraph[u][reversedAdjList[u]++] = i;
        }
    }
    fill(visited, visited + V, false);
    dfs(0, reversedGraph, reversedAdjList, visited, V);
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
    int adjList[MAX_V] = {0};
    bool graph[MAX_V][MAX_E] = {0};
    graph[0][adjList[0]++] = 1;
    graph[1][adjList[1]++] = 2;
    graph[2][adjList[2]++] = 3;
    graph[3][adjList[3]++] = 0;
    if (isStronglyConnected(graph, adjList, V))
    {
        cout << "The graph is strongly connected." << endl;
    }
    else
    {
        cout << "The graph is not strongly connected." << endl;
    }

    return 0;
}