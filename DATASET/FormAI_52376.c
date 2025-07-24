//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

//Bucket Sort Implementation
void bucketSort(int arr[], int n) {
    int i, j;
    int *buckets = (int*)malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        buckets[i] = 0;
    }

    for(i=0; i<n; i++){
        (buckets[arr[i]])++;
    }

    for(i=0,j=0; i<n; i++){
        for(; buckets[i]>0;(buckets[i])--){
            arr[j++] = i;
        }
    }

    free(buckets);
}

//Main Driver
int main() {

    int arr[] = {22, 45, 12, 8, 10, 6, 72, 81, 33, 52};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}