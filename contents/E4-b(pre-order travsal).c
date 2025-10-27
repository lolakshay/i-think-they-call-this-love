#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOPS 10

typedef struct Node {
    char name [50];
    int childCount;
    struct Node* children[MAX_STOPS];
} Node;

Node* createNode(char* name) {
   Node* node = (Node*)malloc(sizeof(Node));
   strcpy(node->name, name);
   node->childCount = 0; // Fixed: $ = changed to =
   return node;
}

void addStop (Node* route, Node* stop) {
   if (route->childCount < MAX_STOPS)
       route->children[route->childCount++] = stop;
}

void preorderTraversal (Node* root) {
   if (!root) return;

   printf("%s\n", root->name);
   for (int i=0; i < root->childCount; i++) // Fixed: $i=0; changed to i=0;
       preorderTraversal (root->children[i]);
}

int main() {
   Node* route1 = createNode("Route A");
   addStop(route1, createNode("Stop A1"));
   addStop(route1, createNode("Stop A2"));

   Node* route2 = createNode("Route B");
   addStop(route2, createNode("Stop B1")); // Fixed: Added semicolon
   addStop(route2, createNode("Stop B2"));
   addStop(route2, createNode("Stop B3"));

   printf("Bus Routes and Stops:\n");
   preorderTraversal(route1);
   preorderTraversal(route2);
   return 0;
}