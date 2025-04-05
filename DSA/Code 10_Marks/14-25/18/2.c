#include <stdio.h>
#define MAX 100

int adjMatrix[MAX][MAX];

void createAdjMatrix(int vertices, int edges)
{
    int src, dest;
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
    }
}

void displayAdjMatrix(int vertices)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printIndegree(int vertices)
{
    printf("\nIndegree of each vertex:\n");
    for (int j = 0; j < vertices; j++)
    {
        int indegree = 0;
        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[i][j] == 1)
            {
                indegree++;
            }
        }
        printf("Vertex %d: %d\n", j, indegree);
    }
}

int main()
{
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    createAdjMatrix(vertices, edges);
    displayAdjMatrix(vertices);
    printIndegree(vertices);

    return 0;
}