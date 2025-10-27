#include <stdio.h> [cite: 301]
#include <stdlib.h> [cite: 302]

struct Node { [cite: 303]
    int data; [cite: 304]
    struct Node* next; [cite: 305]
};

struct Node* top = NULL; [cite: 307]

int isEmpty() {
    return top == NULL; [cite: 309]
}

void push(int x) { [cite: 311]
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); [cite: 312]
    if (!newNode) { [cite: 312]
        printf("Heap overflow!\n"); [cite: 316]
        return; [cite: 317]
    }
    newNode->data = x; [cite: 318]
    newNode->next = top; [cite: 319]
    top = newNode; [cite: 320]
    printf("%d pushed to stack\n", x); [cite: 321]
}

int pop() { [cite: 322]
    if (isEmpty()) { [cite: 323]
        printf("Stack Underflow!\n"); [cite: 324]
        return -1; [cite: 325]
    } else { // Else block added to fix bug in [328]
        int popped = top->data; [cite: 328]
        struct Node* temp = top; [cite: 329]
        top = top->next; [cite: 330]
        free(temp); [cite: 331]
        printf("%d popped from stack\n", popped); [cite: 332]
        return popped; [cite: 333]
    }
}

void display() { [cite: 334]
    if (isEmpty()) { [cite: 335]
        printf("Stack is empty.\n"); [cite: 336]
    } else {
        struct Node* temp = top; [cite: 338]
        printf("Stack elements: "); [cite: 339]
        while (temp != NULL) { [cite: 342]
            printf("%d ", temp->data); [cite: 343]
            temp = temp->next; [cite: 344]
        }
        printf("\n"); [cite: 346]
    }
}

int main() { [cite: 348]
    int choice, val; [cite: 349]
    do { [cite: 350]
        printf("\n1. Push\n2. Pop\n3. Display\n4. IsEmpty\n5. Exit\nEnter your choice: "); [cite: 351]
        scanf("%d", &choice); [cite: 352]
        switch (choice) { [cite: 353]
            case 1: [cite: 354]
                printf("Enter value to push: "); [cite: 355]
                scanf("%d", &val); [cite: 356]
                push(val); [cite: 357]
                break; [cite: 358]
            case 2: [cite: 359]
                pop(); [cite: 360]
                break; [cite: 361]
            case 3: [cite: 362]
                display(); [cite: 363]
                break; [cite: 364]
            case 4: [cite: 365]
                if (isEmpty()) [cite: 368]
                    printf("Stack is empty.\n"); [cite: 369]
                else
                    printf("Stack is not empty.\n"); [cite: 371]
                break; [cite: 372]
            case 5: [cite: 373]
                printf("Exiting...\n"); // Corrected string from [374]
                break; [cite: 375]
            default: [cite: 376]
                printf("Invalid choice.\n"); // Corrected string from [377]
        }
    } while (choice != 5); [cite: 379]
    return 0; [cite: 380]
}