#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
struct Node { 
    char name[50]; 
    struct Node* next; 
}; 
 
struct Node* front = NULL; 
struct Node* rear = NULL; 
 
void enqueue(char name[]) { 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    strcpy(temp->name, name); 
    temp->next = NULL; 
    if (rear == NULL) { 
        front = rear = temp; 
    } else { 
        rear->next = temp; 
        rear = temp; 
    } 
    printf("%s added to reservation list.\n", name); 
} 
 
void dequeue() { 
    if (front == NULL) { 
        printf("No reservations in the list.\n"); 
        return; 
    } 
    struct Node* temp = front; 
    printf("Book issued to: %s\n", front->name); 
    front = front->next; 
    if (front == NULL) rear = NULL; 
    free(temp); 
} 
 
void display() { 
 
    if (front == NULL) { 
        printf("No reservations yet.\n"); 
        return; 
    } 
    struct Node* temp = front; 
    printf("Reservation List:\n"); 
    int i = 1; 
    while (temp != NULL) { 
        printf("%d. %s\n", i++, temp->name); 
        temp = temp->next; 
    } 
} 
 
void cancel(char name[]) { 
    struct Node *temp = front, *prev = NULL; 
    while (temp != NULL && strcmp(temp->name, name) != 0) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("No such reservation found.\n"); 
        return; 
    } 
    if (temp == front) { 
        front = front->next; 
        if (front == NULL) rear = NULL;  
    } else { 
        prev->next = temp->next; 
        if (temp == rear) rear = prev; 
    } 
    free(temp); 
    printf("Reservation for %s cancelled.\n", name); 
} 
 
int main() { 
    int choice; 
    char name[50]; 
    while (1) { 
        printf("\n1. Add Reservation\n2. Issue Book\n3. Display Reservations\n4. 
Cancel Reservation\n5. Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
        getchar(); // clear buffer 
        switch (choice) { 
            case 1: 
                printf("Enter student name: "); 
                gets(name); 
                enqueue(name); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                printf("Enter name to cancel: "); 
                gets(name); 
                cancel(name); 
                break; 
            case 5: 
                return 0; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
}