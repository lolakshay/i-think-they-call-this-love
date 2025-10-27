#include<stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; // Return index if found
    }
    return -1; // Not found
}

int main() {
    int n, i, key, pos;
    printf("Enter number of employees present today:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter employee IDs:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter employee ID to search:");
    scanf("%d", &key);

    pos = linearSearch(arr, n, key);

    if(pos == -1)
        printf("Employee ID%d not found in attendance list.\n", key);
    else
        printf("Employee ID%d found at position%d.\n", key, pos + 1);

    return 0;
}