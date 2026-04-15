#include <stdio.h>

#define V 4 // vertices
#define E 5 // edges

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent;
};

// find parent
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// union sets
void Union(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    subsets[rootX].parent = rootY;
}

// sort edges by weight
void sortEdges(struct Edge edges[])
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[])
{
    struct Subset subsets[V];

    for (int i = 0; i < V; i++)
        subsets[i].parent = i;

    sortEdges(edges);

    printf("Edges in MST:\n");

    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(subsets, u);
        int setV = find(subsets, v);

        if (setU != setV)
        {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);

            Union(subsets, setU, setV);

            count++;
        }
    }
}

int main()
{
    struct Edge edges[E] =
        {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}};

    kruskal(edges);

    return 0;
}
