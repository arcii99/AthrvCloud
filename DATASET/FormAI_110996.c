//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr[] = {12, 8, 6, 14, 23, 9, 10, 3, 20, 17, 34, 45, 65, 77, 89, 91, 100}; // array to be sorted
    int n = sizeof(arr)/sizeof(arr[0]); // total number of elements in the array
    int max = 100, min = 1; // maximum and minimum elements in the array
    int range = max - min + 1; // range of the elements
    int *bucket = (int*)malloc(range * sizeof(int)); // dynamically allocated bucket array

    // initialize the bucket array
    for(int i = 0; i < range; i++)
        bucket[i] = 0;

    // count the frequency of each element in the array and store it in the bucket
    for(int i = 0; i < n; i++)
        bucket[arr[i] - min]++;

    // sort the array using the bucket
    int index = 0;
    for(int i = 0; i < range; i++)
    {
        for(int j = 0; j < bucket[i]; j++)
        {
            arr[index] = i + min;
            index++;
        }
    }

    // print the sorted array
    printf("The sorted array is:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(bucket); // free the dynamically allocated bucket array
}