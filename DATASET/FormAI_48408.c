//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(float array[], int n)
{
    // Create n empty buckets
    float* buckets[n];
    int i;
    for(i=0; i<n; i++) {
        buckets[i] = NULL;
    }

    // Assign array elements to the appropriate buckets
    for(i=0; i<n; i++) {
        int bucketIndex = (int)(array[i] * n);
        if(buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = (float*)malloc(sizeof(float));
            *buckets[bucketIndex] = array[i];
        } else {
            // If the bucket is not empty, append the element at the end
            int j=1;
            while(*(buckets[bucketIndex]+j) != 0 && j<n) {
                j++;
            }
            if(j == n) {
                printf("Bucket overflow! Increase the size of buckets.\n");
                exit(1);
            }
            *(buckets[bucketIndex]+j) = array[i];
        }
    }

    // Sort the individual buckets
    for(i=0; i<n; i++) {
        if(buckets[i] != NULL) {
            int bucketSize = 1;
            while(*(buckets[i]+bucketSize) != 0) {
                bucketSize++;
            }
            int k;
            // Use insertion sort to sort the bucket elements
            for(int j=1; j<bucketSize; j++) {
                float temp = *(buckets[i]+j);
                k = j-1;
                while(k>=0 && *(buckets[i]+k) > temp) {
                    *(buckets[i]+k+1) = *(buckets[i]+k);
                    k--;
                }
                *(buckets[i]+k+1) = temp;
            }
        }
    }

    // Concatenate the sorted buckets
    int index=0;
    for(i=0; i<n; i++) {
        if(buckets[i] != NULL) {
            int bucketSize = 1;
            while(*(buckets[i]+bucketSize) != 0) {
                bucketSize++;
            }
            for(int j=0; j<bucketSize; j++) {
                array[index++] = *(buckets[i]+j);
            }
        }
    }
}

int main()
{
    float array[] = {0.42, 0.32, 0.77, 0.55, 0.11, 0.23, 0.88};
    int n = sizeof(array)/sizeof(float);
    printf("Original array: ");
    for(int i=0; i<n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    bucketSort(array, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}