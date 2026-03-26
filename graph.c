#include <stdio.h>

int adj[10][10], visited[10], n;

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[10], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nDFS Traversal: ");
    DFS(0);

    // CRITICAL: Reset visited array for BFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");
    BFS(0);

    return 0;
}