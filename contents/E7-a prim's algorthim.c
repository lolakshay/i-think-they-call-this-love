#include<stdio.h>
#define INF 9999
#define MAX 10

void prims(int G[MAX][MAX], int n) {
    int selected[MAX];
    int no_of_edges = 0, i, j, x, y, min, total = 0;

    for(i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1; // Start from the first node

    printf("\nEdges in MST:\n");
    while(no_of_edges < n - 1) {
        min = INF;
        x = 0;
        y = 0;

        for(i = 0; i < n; i++) {
            if(selected[i]) {
                for(j = 0; j < n; j++) {
                    if(!selected[j] && G[i][j]) {
                        if(min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("Edge%d:(%d->%d) cost:%d\n", no_of_edges + 1, x, y, G[x][y]);
        total += G[x][y];
        selected[y] = 1;
        no_of_edges++;
    }

    printf("\nMinimum Cost=%d\n", total);
}

int main() {
    int G[MAX][MAX], i, j, n;

    printf("Enter number of houses(vertices):");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    prims(G, n);
    return 0;
}