//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    /* Create n buckets */
    int i;
    for (i = 0; i < n; i++) {
        int bucketIndex = (int) arr[i] * n;
        printf("Bucket Index: %d\n", bucketIndex);
    }

    /*
     * Sorting individual buckets
     *
     * Code for sorting individual buckets goes here
     */
}

int main(int argc, char const *argv[]) {
    float arr[] = {0.32, 0.15, 0.54, 0.37, 0.44, 0.88, 0.11, 0.22, 0.98, 0.65};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array Before Sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%f\t", arr[i]);
    }
    printf("\n");
 
    bucketSort(arr, n);
 
    printf("Array After Sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%f\t", arr[i]);
    }
    printf("\n");
 
    return 0;
}