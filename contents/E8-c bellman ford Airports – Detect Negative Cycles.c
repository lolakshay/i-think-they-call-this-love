#include<stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V], i, j;

    for(i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for(i = 1; i <= V - 1; i++) {
        for(j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative cycle
    for(j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("\nGraph contains negative weight cycle!\n");
            return;
        }
    }

    printf("\nShortest distances from source%d:\n", src);
    for(i = 0; i < V; i++)
        printf("To%d:%d\n", i, dist[i]);
}

int main() {
    int V, E, i, src;

    printf("Enter number of airports(vertices):");
    scanf("%d", &V);
    printf("Enter number of flight routes(edges):");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges(u v cost):\n");
    for(i = 0; i < E; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("Enter source airport:");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);
    return 0;
}