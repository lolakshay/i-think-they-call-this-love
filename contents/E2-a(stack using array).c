#include <stdio.h>
#define MAX 100 [cite: 164]

int stack[MAX]; [cite: 165]
int top = -1; [cite: 145, 166]

int isFull() {
    return top == MAX - 1; [cite: 168]
}

int isEmpty() {
    return top == -1; [cite: 171]
}

void push(int x) {
    if (isFull()) { [cite: 174]
        printf("Stack Overflow!\n"); [cite: 175]
    } else {
        stack[++top] = x; [cite: 177]
        printf("%d pushed to stack\n", x); [cite: 179]
    }
}

int pop() {
    if (isEmpty()) { [cite: 183]
        printf("Stack Underflow!\n"); [cite: 184]
        return -1; [cite: 185]
    } else {
        printf("%d popped from stack\n", stack[top]); [cite: 187]
        return stack[top--]; [cite: 188]
    }
}

void display() {
    if (isEmpty()) { [cite: 192]
        printf("Stack is empty.\n"); [cite: 193]
    } else {
        printf("Stack elements: "); [cite: 195]
        for (int i = top; i >= 0; i--) { [cite: 196]
            printf("%d ", stack[i]); [cite: 197]
        }
        printf("\n"); // Corrected placement from [201]
    }
}

int main() { [cite: 202]
    int choice, val; [cite: 203]
    do { [cite: 204]
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: "); [cite: 207]
        scanf("%d", &choice); [cite: 208]
        switch (choice) { [cite: 209]
            case 1: [cite: 211]
                printf("Enter value to push: "); [cite: 212]
                scanf("%d", &val); [cite: 213]
                push(val); [cite: 214]
                break; [cite: 215]
            case 2: [cite: 216]
                pop(); [cite: 217]
                break; [cite: 218]
            case 3: [cite: 219]
                display(); [cite: 220]
                break; [cite: 221]
            case 4: [cite: 222]
                printf("Exiting...\n"); [cite: 223]
                break; [cite: 224]
            default: [cite: 225]
                printf("Invalid choice.\n"); [cite: 226]
        }
    } while (choice != 4); [cite: 227]
    return 0; [cite: 228]
}