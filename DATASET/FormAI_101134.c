//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>

void BucketSort(float arr[], int n)
{
    // Create buckets and initialize them with 0
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    // Count the elements in each bucket
    for (i = 0; i < n; i++)
        count[(int)arr[i]]++;

    // Sort the elements in each bucket
    for (i = 0, j = 0; i < n; i++)
        for (; count[i] > 0; (count[i])--)
            arr[j++] = (float)i;

}

int main()
{
    float arr[] = { 0.43, 0.32, 0.89, 0.12, 0.85, 
                    0.54, 0.23, 0.78, 0.67 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);

    //Bucket Sort function call
    BucketSort(arr, n);

    printf("\n\nAfter sorting:\n");
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);

    return 0;
}