#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct Node {
    char name[50];
    int isFile; // 0 for folder, 1 for file
    int childCount;
    struct Node* children[MAX_CHILDREN];
} Node;

Node* createNode(char* name, int isFile) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->isFile = isFile;
    node->childCount = 0; // Fixed: $ = changed to =
    return node;
}

void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    }
}

void inorderStyleTraversal (Node* root) {
    if (!root) return;

    int mid = root->childCount / 2;
    for (int i=0; i < mid; i++) // Fixed: $i=0; changed to i=0;
        inorderStyleTraversal (root->children[i]);

    printf("%s [%s]\n", root->name, root->isFile? "File": "Folder");

    for (int i = mid; i < root->childCount; i++) // Fixed: i = mid
        inorderStyleTraversal (root->children[i]);
}

int main() {
    Node* root = createNode("Root", 0);
    Node* folder1 = createNode("Documents", 0);
    Node* file1 = createNode("resume.pdf", 1);
    Node* file2 = createNode("report.docx", 1);
    Node* folder2 = createNode("Pictures", 0);
    Node* file3 = createNode("image.jpg", 1);

    addChild(root, folder1);
    addChild(folder1, file1);
    addChild(folder1, file2);
    addChild(root, folder2);
    addChild(folder2, file3);

    printf("Inorder-style Traversal:\n");
    inorderStyleTraversal (root);
    return 0;
}