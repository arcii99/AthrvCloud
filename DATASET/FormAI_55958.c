//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

/* function prototype */
void bucketSort(float arr[], int n);

int main(void) {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d elements separated by space: ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Output: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bucketSort(float arr[], int n) {
    /* create n empty buckets */
    int i, j;
    float bucket[n][n], temp;

    /* Initialize all buckets */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            bucket[i][j] = 0;
        }
    }

    /* Add elements into the buckets */
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        for (j = 0; j < n; j++) {
            if (bucketIndex == j) {
                bucket[j][i] = arr[i];
            }
        }
    }

    /* Sort the elements in each bucket */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (bucket[i][j] > bucket[i][j+1]) {
                temp = bucket[i][j];
                bucket[i][j] = bucket[i][j+1];
                bucket[i][j+1] = temp;
            }
        }
    }

    /* Merge the sorted buckets into the original array */
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (bucket[i][j] != 0) {
                arr[index] = bucket[i][j];
                index++;
            }
        }
    }
}