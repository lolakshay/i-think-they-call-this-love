#include<stdio.h>
#define INF 9999
#define MAX 10

void floydWarshall(int G[MAX][MAX], int n) {
    int dist[MAX][MAX], i, j, k;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            dist[i][j] = (G[i][j] == 0 && i != j) ? INF : G[i][j];

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("\nShortest distances between all pairs:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF");
            else
                printf("%3d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int G[MAX][MAX], n, i, j;

    printf("Enter number of attractions(vertices):");
    scanf("%d", &n);

    printf("Enter adjacency matrix(0 if no direct road):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    floydWarshall(G, n);
    return 0;
}