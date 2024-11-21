#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void createGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // For undirected graph
}

void BFS(int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int vertices = 6;
    createGraph(vertices);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printf("BFS traversal: ");
    BFS(0);
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
