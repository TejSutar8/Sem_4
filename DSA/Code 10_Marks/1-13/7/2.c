#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int vertex;
    struct node *next;
} NODE;

void create(int a[MAX][MAX], int n)
{
    printf("\n***Enter 1 for Yes & 0 for No**\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
            if (i != j)
            {
                printf("\nIs there edge between v%d & v%d: ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }
    }
}

void recdfs(int a[MAX][MAX], int n, int v, int visited[MAX])
{
    visited[v] = 1;
    printf("v%d\t", v + 1);
    for (int w = 0; w < n; w++)
    {
        if ((a[v][w] == 1) && (visited[w] == 0))
            recdfs(a, n, w, visited);
    }
}

int main()
{
    int a[MAX][MAX], n;
    int visited[MAX] = {0};
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    create(a, n);
    printf("\nThe Depth First Search Traversal is: \n");
    recdfs(a, n, 0, visited);
    return 0;
}
