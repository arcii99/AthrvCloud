//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    //Create buckets
    int i, j;
    int count[n];
    for(i = 0; i < n; i++)
        count[i] = 0;
    //Add the items to the buckets
    for(i = 0; i < n; i++) {
        int bucket = n * arr[i];
        count[bucket]++;
    }
    //Sort the items of each bucket
    for(i = 0; i < n; i++) {
        int bucket_items[count[i]];
        j = 0;
        for(int x = 0; x < n; x++) {
            int bucket = n * arr[x];
            if(bucket == i) {
                bucket_items[j] = arr[x];
                j++;
            } 
        }
        for(int k = 0; k < j; k++) {
            for(int l = k + 1; l < j; l++) {
                if(bucket_items[l] < bucket_items[k]) {
                    float temp = bucket_items[l];
                    bucket_items[l] = bucket_items[k];
                    bucket_items[k] = temp;
                }
            }
        }
        //Put the sorted items back into the array
        j = 0;
        for(int x = 0; x < n; x++) {
            int bucket = n * arr[x];
            if(bucket == i) {
                arr[x] = bucket_items[j];
                j++;
            }
        }
    }
}

int main() {
    float arr[] = {0.1, 0.3, 0.2, 0.8, 0.7, 0.4, 0.9, 0.5, 0.6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Initial Array:\n");
    for(int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    bucketSort(arr, n);
    printf("\n\nSorted Array:\n");
    for(int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    return 0;
}