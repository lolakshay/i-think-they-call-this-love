#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct Node {
    char name [50];
    int marks;
    int isSubject;
    int childCount;
    struct Node* children[MAX_CHILDREN];
} Node;

Node* createNode(char* name, int isSubject, int marks) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->isSubject = isSubject;
    node->marks = marks;
    node->childCount = 0; // Fixed: $ = changed to =
    return node;
}

void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX_CHILDREN)
        parent->children[parent->childCount++] = child;
}

void postorderTraversal (Node* node) {
    if (!node) return;

    for (int i=0; i < node->childCount; i++) // Fixed: $i=0; changed to i=0;
        postorderTraversal (node->children[i]);

    if (node->isSubject)
        printf(" Subject: %s - Marks: %d\n", node->name, node->marks);
    else if (node->childCount > 0)
        printf("Student: %s Report Completed.\n", node->name);
    else
        printf("Class: %s All Reports Completed.\n", node->name);
}

int main() {
    Node* classNode = createNode("Class 10", 0, 0);

    Node* student1 = createNode("Student A", 0, 0);
    addChild(student1, createNode("Math", 1, 85));
    addChild(student1, createNode("Science", 1, 90));

    Node* student2 = createNode("Student B", 0, 0);
    addChild(student2, createNode("Math", 1, 78));
    addChild(student2, createNode("Science", 1, 88));

    addChild(classNode, student1);
    addChild(classNode, student2);

    printf("Report Card:\n");
    postorderTraversal (classNode);
    return 0;
}