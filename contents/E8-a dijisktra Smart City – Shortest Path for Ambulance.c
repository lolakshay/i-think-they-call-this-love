#include<stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
    int count, mindistance, nextnode, i, j;

    // Create cost matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0) ? INF : G[i][j];

    for(i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n - 1) {
        mindistance = INF;
        for(i = 0; i < n; i++)
            if(!visited[i] && distance[i] < mindistance) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for(i = 0; i < n; i++)
            if(!visited[i])
                if(mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    printf("\nShortest distances from source%d:\n", start);
    for(i = 0; i < n; i++) {
        if(i != start) {
            printf("To%d:%d\n", i, distance[i]);
        }
    }
}

int main() {
    int G[MAX][MAX], n, start, i, j;

    printf("Enter number of intersections(vertices):");
    scanf("%d", &n);

    printf("Enter adjacency matrix(0 if no direct road):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter hospital node(source):");
    scanf("%d", &start);

    dijkstra(G, n, start);
    return 0;
}