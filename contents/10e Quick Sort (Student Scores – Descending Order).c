#include<stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] >= pivot) { // Descending
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of students:");
    scanf("%d", &n);

    int scores[n];
    printf("Enter student scores:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &scores[i]);

    quickSort(scores, 0, n - 1);

    printf("\nScores in descending order:\n");
    for(i = 0; i < n; i++)
        printf("%d", scores[i]);

    return 0;
}
