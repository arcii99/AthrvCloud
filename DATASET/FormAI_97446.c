//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int max) {
    int i, j;
    int *buckets = malloc(sizeof(int) * (max+1));
    for (i = 0; i < max+1; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        (buckets[arr[i]])++;
    }
    for (i = 0, j = 0; i < max+1; i++) {
        while ((buckets[i]--) > 0) {
            arr[j++] = i;
        }
    }
    free(buckets);
}

int main() {
    printf("Welcome to the Bucket Sort implementation program!\n\n");
    
    int n, max;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            max = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    bucketSort(arr, n, max);
    
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nThank you for using the Bucket Sort implementation program!\n");
    return 0;
}