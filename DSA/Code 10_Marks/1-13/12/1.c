#include <stdio.h>

void DFS(int adjMatrix[20][20], int visited[20], int vertex, int n)
{
    printf("%d ", vertex + 1);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[vertex][i] == 1 && !visited[i])
        {
            DFS(adjMatrix, visited, i, n);
        }
    }
}

int main()
{
    int adjMatrix[20][20], visited[20] = {0}, n, startVertex;
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

    printf("Enter starting vertex (1 to %d): ", n);
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(adjMatrix, visited, startVertex - 1, n);

    return 0;
}
