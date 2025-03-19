#include <stdio.h>

void calculateIndegree(int adjMatrix[20][20], int n)
{
    int indegree[20] = {0};
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            indegree[j] += adjMatrix[i][j];
        }
    }
    printf("Indegree of vertices:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d: %d\n", i + 1, indegree[i]);
    }
}

int main()
{
    int adjMatrix[20][20], n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    calculateIndegree(adjMatrix, n);
    return 0;
}