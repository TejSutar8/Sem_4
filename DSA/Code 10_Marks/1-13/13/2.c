#include <stdio.h>

int main()
{
    int n, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjMatrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}