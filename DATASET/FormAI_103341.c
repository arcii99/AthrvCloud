//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>

#define MAX_SIZE 100 // Maximum array size

int main() {
    int arr[MAX_SIZE];
    int n, i, j, temp;

    /* Input size of array */
    printf("Enter size of array: ");
    scanf("%d", &n);

    /* Input elements of array */
    printf("Enter %d elements in array: ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Bubble sorting algorithm */
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    /* Print sorted array */
    printf("\nSorted array in ascending order: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}