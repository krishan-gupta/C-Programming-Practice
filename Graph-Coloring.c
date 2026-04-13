#include <stdio.h>

#define MAX 100

// Check if safe
int isSafe(int v, int graph[MAX][MAX], int color[], int c, int V)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

// Backtracking
int solve(int v, int graph[MAX][MAX], int m, int color[], int V)
{

    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++)
    {

        if (isSafe(v, graph, color, c, V))
        {

            color[v] = c;

            if (solve(v + 1, graph, m, color, V))
                return 1;

            color[v] = 0; // backtrack
        }
    }

    return 0;
}

// Print solution
void printSolution(int color[], int V)
{
    printf("Vertex Colors:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

int main()
{
    int V = 4;
    int m = 3;

    int graph[MAX][MAX] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};

    int color[MAX] = {0};

    if (solve(0, graph, m, color, V))
        printSolution(color, V);
    else
        printf("No solution exists");

    return 0;
}