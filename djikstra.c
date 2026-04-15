#include <stdio.h>
#include <limits.h>
#define V 5

int minDistance(int visited[], int dist[])
{
    int min = 9999, minindex;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            minindex = v;
        }
    }
    return minindex;
}

void printdji(int dist[])
{
    for (int i = 0; i < V; i++)
    {
        printf("%d  %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V];
    // initialise
    for (int i = 0; i < V; i++)
    {
        dist[i] = 9999;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(visited, dist);
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (visited[u] != 0 && graph[u][v] && dist[u] != 9999 && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printdji(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}