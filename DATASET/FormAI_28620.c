//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(float arr[], int n)
{
    // Create buckets 0 to 9
    int i, j;
    int bucket[10];
    for (i=0; i < 10; i++) {
        bucket[i] = 0;
    }

    // Add values to respective buckets
    for (i=0; i<n; i++) {
        int bucket_index = arr[i] * 10;
        bucket[bucket_index]++;
    }

    // Sort each bucket
    for (i=0; i<10; i++) {
        for (j=0; j<bucket[i]; j++) {
            printf("%f ", (float)i/10);
        }
    }
}

int main()
{
    float arr[] = {0.21, 0.13, 0.35, 0.27, 0.08, 0.10, 0.55, 0.49, 0.41, 0.30};

    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting:\n");
    for(int i=0; i<n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");

    // Perform bucket sort
    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for(int i=0; i<n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}