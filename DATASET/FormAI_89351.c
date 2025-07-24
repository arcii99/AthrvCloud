//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

//Define the number of buckets
#define NUM_BUCKETS 10

//Define the structure of a bucket
typedef struct Bucket {
    int count;
    float* values;
} Bucket;

//Bucket Sort function
void bucketSort(float arr[], int n) {
    //Create the buckets
    Bucket* buckets = (Bucket*) calloc(NUM_BUCKETS, sizeof(Bucket));
    int i, j;

    //Distribute the values to the buckets
    for(i=0; i<n; i++) {
        int index = arr[i]*NUM_BUCKETS;
        buckets[index].values = (float*) realloc(buckets[index].values, (buckets[index].count+1)*sizeof(float));
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    //Sort the values in each bucket using insertion sort
    for(i=0; i<NUM_BUCKETS; i++) {
        for(j=1; j<buckets[i].count; j++) {
            float temp = buckets[i].values[j];
            int k = j-1;
            while(k>=0 && buckets[i].values[k]>temp) {
                buckets[i].values[k+1] = buckets[i].values[k];
                k--;
            }
            buckets[i].values[k+1] = temp;
        }
    }

    //Concatenate the sorted values from each bucket
    int index = 0;
    for(i=0; i<NUM_BUCKETS; i++) {
        for(j=0; j<buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
    }

    //Free the allocated memory
    for(i=0; i<NUM_BUCKETS; i++) {
        free(buckets[i].values);
    }
    free(buckets);
}

//Driver function
int main() {
    float arr[] = {0.7, 0.3, 0.4, 0.8, 0.2, 0.6, 0.5, 0.1, 0.9, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for(int i=0; i<n; i++) printf("%.2f ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++) printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}