#include<stdio.h>
#include<stdlib.h>
#define MAX 30

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(struct Edge edges[], int n, int e) {
    int i, j, total = 0, count = 0;

    for(i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    for(i = 0; i < e; i++) {
        for(j = 0; j < e - i - 1; j++) {
            if(edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in MST:\n");
    for(i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b) {
            printf("Edge%d:(%d->%d) cost:%d\n", count + 1, edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            union_set(a, b);
            count++;
        }
    }

    printf("\nMinimum Cost=%d\n", total);
}

int main() {
    int n, e, i;
    struct Edge edges[MAX];

    printf("Enter number of departments(vertices):");
    scanf("%d", &n);
    printf("Enter number of connections(edges):");
    scanf("%d", &e);

    printf("Enter edges(u v cost):\n");
    for(i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, n, e);
    return 0;
}