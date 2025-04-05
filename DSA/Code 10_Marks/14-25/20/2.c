#include <stdio.h>

#define MAX 100

void acceptGraph(int adj[MAX][MAX], int vertices, int edges)
{
    int i, src, dest;
    for (i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
    }
}

void displayAdjMatrix(int adj[MAX][MAX], int vertices)
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void printIndegree(int adj[MAX][MAX], int vertices)
{
    int i, j, indegree;
    printf("\nIndegree of each vertex:\n");
    for (j = 0; j < vertices; j++)
    {
        indegree = 0;
        for (i = 0; i < vertices; i++)
        {
            if (adj[i][j] == 1)
            {
                indegree++;
            }
        }
        printf("Vertex %d: %d\n", j, indegree);
    }
}

int main()
{
    int vertices, edges, adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    acceptGraph(adj, vertices, edges);
    displayAdjMatrix(adj, vertices);
    printIndegree(adj, vertices);

    return 0;
}
