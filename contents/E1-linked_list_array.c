#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// 2. Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// 3. Delete from given position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = temp->next;
        printf("Deleted node at position %d.\n", pos);
        free(temp);
        return;
    }

    // Traverse to the (pos - 1) node
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    // If position is invalid
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // temp is at (pos - 1), temp->next is the node to be deleted
    struct Node* targetNode = temp->next;
    temp->next = targetNode->next; // Unlink the node
    printf("Deleted node at position %d.\n", pos);
    free(targetNode); // Free the unlinked node
}

// 4. Display list
void displayList() {
    struct Node* temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    insertAtBeginning(10);
    displayList();
    insertAtEnd(20);
    displayList();
    insertAtBeginning(5);
    displayList();
    deleteFromPosition(2);
    displayList();
    deleteFromPosition(5); // Invalid
    displayList();
    return 0;
}