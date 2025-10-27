#include<stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    int n, i, key, pos;
    printf("Enter number of products:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter product IDs in sorted order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter product ID to search:");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);

    if(pos == -1)
        printf("Product ID%d not found in the list.\n", key);
    else
        printf("Product ID%d found at position%d.\n", key, pos + 1);

    return 0;
}