//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float array[], int n) {
    
    // Create number of buckets
    int i, j, count[n];    
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    
    // Add elements to the respective bucket
    for (i = 0; i < n; i++) {
        count[(int)array[i]]++;
    }
    
    // Sort the elements in each bucket 
    for (i = 0, j = 0; i < n; i++) {
        while (count[i] > 0) {
            array[j++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    float array[n];
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    bucketSort(array, n);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }

    return 0;
}