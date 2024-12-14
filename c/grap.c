#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

// Function prototypes
void createGraph(int n);
void addEdge(int start, int end);
void printGraph(int n);
void DFS(int start, int n);
void BFS(int start, int n);

// Global variables
int graph[MAX][MAX];
bool visited[MAX];

int main() {
    int n, start;
    
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    createGraph(n);
    
    printf("\nEnter the number of edges: ");
    int e;
    scanf("%d", &e);
    
    printf("\nEnter the edges (start end):\n");
    for (int i = 0; i < e; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }
    
    printf("\nThe adjacency matrix of the graph is:\n");
    printGraph(n);
    
    printf("\nEnter the starting city for DFS: ");
    scanf("%d", &start);
    printf("DFS traversal from node %d: ", start);
    DFS(start, n);
    printf("\n");
    
    printf("\nEnter the starting city for BFS: ");
    scanf("%d", &start);
    printf("BFS traversal from node %d: ", start);
    BFS(start, n);
    printf("\n");
    
    return 0;
}

// Function to create a graph of N cities using adjacency matrix
void createGraph(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge between two cities in the graph
void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // Assuming undirected graph
}

// Function to print the adjacency matrix of the graph
void printGraph(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Depth First Search traversal
void DFS(int start, int n) {
    printf("%d ", start);
    visited[start] = true;
    for (int i = 1; i <= n; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

// Breadth First Search traversal
void BFS(int start, int n) {
    int queue[MAX], front = -1, rear = -1;
    bool visited[MAX] = {false};
    
    queue[++rear] = start;
    visited[start] = true;
    
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for (int i = 1; i <= n; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}
