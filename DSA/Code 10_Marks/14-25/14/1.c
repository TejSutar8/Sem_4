#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void displayAdjList(int vertices)
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++)
    {
        struct Node *temp = adjList[i];
        printf("Vertex %d:", i);
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    displayAdjList(vertices);

    return 0;
}
