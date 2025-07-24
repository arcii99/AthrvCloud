//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>

// Function to sort an array using Bucket Sort
void bucketSort(int arr[], int n)
{
    // create a 2D array of buckets
    int bucket[n][n];

    // initialize all elements of bucket to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            bucket[i][j] = 0;

    // insert elements into the correct bucket
    for (int i = 0; i < n; i++) {
        int idx = arr[i] / n;
        bucket[idx][arr[i] % n] = arr[i];
    }

    // sort elements within each bucket
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            for (int k = 0; k < n-1-j; k++) {
                if (bucket[i][k] > bucket[i][k+1]) {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k+1];
                    bucket[i][k+1] = temp;
                }
            }
        }
    }

    // concatenate all the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (bucket[i][j] != 0)
                arr[index++] = bucket[i][j];
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {5, 3, 2, 8, 6, 4, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting: ");
    printArray(arr, n);
    return 0;
}