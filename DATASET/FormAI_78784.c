//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

void bucket_sort(int arr[], int n, int M) {
    // n -> num elements, M -> max element value
    int bucket_size = min(n, M); // number of buckets
    
    int **buckets = malloc(bucket_size * sizeof(int*)); // allocate and define buckets
    for(int i = 0; i < bucket_size; i++) {
        buckets[i] = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            buckets[i][j] = -1;
        }
    }

    // populate buckets
    for(int i = 0; i < n; i++) {
        int index = min(arr[i] / M, bucket_size - 1);
        for(int j = 0; j < n; j++) {
            if(buckets[index][j] == -1) {
                buckets[index][j] = arr[i];
                break;
            }
        }
    }

    // sort each bucket and merge
    int index = 0;
    for(int i = 0; i < bucket_size; i++) {
        for(int j = 0; j < n; j++) {
            if(buckets[i][j] != -1) {
                // sort within bucket (insertion sort)
                int k = j;
                while(k > 0 && buckets[i][k] < buckets[i][k-1]) {
                    int tmp = buckets[i][k-1];
                    buckets[i][k-1] = buckets[i][k];
                    buckets[i][k] = tmp;
                    k--;
                }
                arr[index++] = buckets[i][j]; // merge sorted bucket into main array
            }
        }
    }

    // cleanup
    for(int i = 0; i < bucket_size; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {8, 5, 2, 9, 5, 6, 3};
    int n = sizeof(arr) / sizeof(int);
    int M = 10;

    printf("Before sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n, M);

    printf("\nAfter sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}