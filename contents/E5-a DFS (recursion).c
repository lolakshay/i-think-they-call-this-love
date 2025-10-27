#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int visited[MAX], adj[MAX][MAX], n;

void DFS_iterative(int start) {
    int stack[MAX], top = -1;
    stack[++top] = start;

    while(top != -1) {
        int v = stack[top--];
        if(!visited[v]) {
            visited[v] = 1;
            printf("%d ", v);
            // Push all adjacent unvisited nodes (in reverse order for correct DFS sequence)
            for(int i = n - 1; i >= 0; i--) {
                if(adj[v][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    int e, u, v, start;
    printf("Enter number of people(nodes): ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of friendships(edges): ");
    scanf("%d", &e);

    printf("Enter edges(u v):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    printf("Enter starting person: ");
    scanf("%d", &start);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Friends reachable from person %d:\n", start);
    DFS_iterative(start);
    return 0;
}