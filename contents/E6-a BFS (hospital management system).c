#include<stdio.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    if(front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

void bfs(int adj[MAX][MAX], int n, int start) {
    int i, current;
    for(i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("Order of customers served(BFS):");
    while((current = dequeue()) != -1) {
        printf("Customer-%d", current);
        for(i = 0; i < n; i++) {
            if(adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, start;
    int adj[MAX][MAX];

    printf("Enter number of customers:");
    scanf("%d", &n);

    printf("Enter adjacency matrix(connections between customers):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("Enter the first customer(0 to %d):", n - 1);
    scanf("%d", &start);

    bfs(adj, n, start);
    return 0;
}