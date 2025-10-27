#include<stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, max, temp;
    for(i = 0; i < n - 1; i++) {
        max = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] > arr[max]) // Descending
                max = j;
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int n, i;
    printf("Enter number of movies:");
    scanf("%d", &n);

    int ratings[n];
    printf("Enter movie ratings:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &ratings[i]);

    selectionSort(ratings, n);

    printf("\nMovie ratings in descending order:\n");
    for(i = 0; i < n; i++)
        printf("%d", ratings[i]);

    return 0;
}