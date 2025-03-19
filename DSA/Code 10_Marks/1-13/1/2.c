#include <stdio.h>

#define MAX 10

int adj[MAX][MAX]; 
int n; 

void initializeGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        adj[src][dest] = 1;
    } else {
        printf("Invalid edge! Source or destination out of range.\n");
    }
}

void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

void printIndegree() {
    printf("\nIndegree of vertices:\n");
    for (int i = 0; i < n; i++) {
        int indegree = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree++;
            }
        }
        printf("Vertex %d: %d\n", i, indegree);
    }
}

int main() {
    int edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    displayMatrix();
    printIndegree();

    return 0;
}
