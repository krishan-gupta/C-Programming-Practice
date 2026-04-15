#include <stdio.h>

// 1. Set the number of vertices for the sample graph
int n = 5;

// 2. Initialize the visited array to 0 directly upon creation
int visited[10] = {0};

int adj[10][10] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}};

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
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
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    printf("DFS Traversal: ");
    DFS(0);

    // Reset the visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");
    BFS(0);
    printf("\n");

    return 0;
}