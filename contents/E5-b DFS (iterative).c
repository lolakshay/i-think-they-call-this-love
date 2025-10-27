#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int visited[MAX], adj[MAX][MAX], n;

void DFS(int v, int failed) {
    if(v == failed) return; // Skip the failed station
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i] && i != failed) {
            DFS(i, failed);
        }
    }
}

int main() {
    int e, u, v, source, failed;
    printf("Enter number of stations(nodes): ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of transmission lines(edges): ");
    scanf("%d", &e);

    printf("Enter edges(u v):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    printf("Enter source station: ");
    scanf("%d", &source);
    printf("Enter failed station: ");
    scanf("%d", &failed);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Stations connected to source %d (excluding failed station %d):\n", source, failed);
    DFS(source, failed);
    return 0;
}