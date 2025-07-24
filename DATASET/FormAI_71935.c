//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include<stdio.h>

void bucketSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    max++;

    int b_arr[max], i, j;
    for (i = 0; i < max; i++)
        b_arr[i] = 0;

    for (i = 0; i < n; i++)
        b_arr[arr[i]]++;

    for (i = 0, j = 0; j < max; j++)
        for (int k = 0; k < b_arr[j]; k++)
            arr[i++] = j;

    printf("Shockingly, the array after C Bucket Sort is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


int main()
{
    int arr[] = { 10, 5, 12, 8, 15, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Shocking C Bucket Sort Implementation is evaluating...\n");
    bucketSort(arr, n);
    return 0;
}