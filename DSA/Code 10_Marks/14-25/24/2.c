#include <stdio.h>
#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;
int n;

void initVisited()
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

void createAdjMatrix()
{
    int edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    
    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = element;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    int element = queue[front];
    front++;
    return element;
}

void BFS(int start)
{
    initVisited();
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal Order: ");
    while (front <= rear)
    {
        int current = dequeue();
        printf("%d ", current);

        for (int j = 0; j < n; j++)
        {
            if (adj[current][j] == 1 && !visited[j])
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    createAdjMatrix();
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    BFS(startVertex);
    return 0;
}
