#include<stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1]) { // Descending
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of players:");
    scanf("%d", &n);

    int scores[n];
    printf("Enter player scores:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &scores[i]);

    bubbleSort(scores, n);

    printf("\nScores in descending order:\n");
    for(i = 0; i < n; i++)
        printf("%d", scores[i]);

    return 0;
}