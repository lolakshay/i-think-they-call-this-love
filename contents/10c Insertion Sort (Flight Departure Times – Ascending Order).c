#include<stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) { // Ascending
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;
    printf("Enter number of flights:");
    scanf("%d", &n);

    int times[n];
    printf("Enter departure times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &times[i]);

    insertionSort(times, n);

    printf("\nDeparture times in ascending order:\n");
    for(i = 0; i < n; i++)
        printf("%d", times[i]);

    return 0;
}