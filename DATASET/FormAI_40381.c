//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#define MAX_SIZE 100

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int i, n, arr[MAX_SIZE];

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter %d array elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call Bubble Sort function
    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}