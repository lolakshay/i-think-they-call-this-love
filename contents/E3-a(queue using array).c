#include <stdio.h> 
#include <string.h> 
#define MAX 5 
char queue[MAX][50]; 
int front = -1, rear = -1 
void enqueue(char name[]) { 
    if (rear == MAX - 1) { 
        printf("Waiting list is full!\n"); 
        return; 
    } 
    if (front == -1) front = 0; 
    rear++; 
    strcpy(queue[rear], name); 
    printf("%s added to the waiting list.\n", name); 
} 
void dequeue() { 
    if (front == -1 || front > rear) { 
        printf("No users in the waiting list.\n"); 
        return; 
    } 
    printf("Ticket allocated to: %s\n", queue[front]); 
 
    front++; 
} 
void display() { 
    if (front == -1 || front > rear) { 
        printf("Waiting list is empty.\n"); 
        return; 
    } 
    printf("Current Waiting List:\n"); 
    for (int i = front; i <= rear; i++) { 
        printf("%d. %s\n", i - front + 1, queue[i]); 
    } 
} 
 
int main() { 
    int choice; 
    char name[50]; 
    while (1) { 
        printf("\n1. Add User\n2. Allocate Ticket\n3. Display Waiting List\n4. 
Exit\nEnter your choice: "); 
        scanf("%d", &choice); 
        getchar(); // clear buffer 
        switch (choice) { 
            case 1: 
                printf("Enter user name: "); 
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
                return 0; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
}