//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void BucketSort(float arr[], int n)
{
    int i, j;
    float temp;
    int count[n];

    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[(int)arr[i]]++;
    }

    for (i = 0, j = 0; i < n; i++) {
        for (temp = 0; temp < count[i]; temp++) {
            arr[j++] = i;
        }
    }
}

int main()
{
    float arr[10] = { 0.84, 0.23, 0.62, 0.92, 0.12, 0.65, 0.54, 0.17, 0.25, 0.73 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    BucketSort(arr, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}