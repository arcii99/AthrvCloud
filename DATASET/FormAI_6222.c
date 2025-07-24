//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function to perform bucket sort
void bucket_sort(float arr[], int n)
{
    // create n empty buckets
    int i, j;
    int count[n];
    float bucket[n][n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // fill the buckets with corresponding elements
    for (i = 0; i < n; i++) {
        int bucket_index = n*arr[i];
        bucket[bucket_index][count[bucket_index]] = arr[i];
        count[bucket_index]++;
    }

    // sort the elements in each bucket
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i] - 1; j++) {
            int k;
            for(k = 0; k < count[i] - j - 1; k++) {
                if(bucket[i][k] > bucket[i][k+1]) {
                    float temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k+1];
                    bucket[i][k+1] = temp;
                }
            }
        }
    }
    // concatenate sorted buckets sequentially
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

// main function
int main() {
    
    // sample input array
    float arr[] = {0.2, 0.5, 0.1, 0.8, 0.3, 0.9, 0.4, 0.7, 0.6, 0.0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // print original array
    printf("Original array:\n");
    for(int i=0; i<n; i++) {
        printf("%.2f ", arr[i]);
    }

    // perform bucket sort
    bucket_sort(arr, n);

    // print sorted array
    printf("\n\nSorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}