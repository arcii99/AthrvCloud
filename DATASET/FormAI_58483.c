//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    //Create buckets
    int i, j, k, buckets[10][10], num[10];
    for (i = 0; i < 10; i++)
        num[i] = 0;
    
    //Distribute the elements into the corresponding bucket
    for (i = 0; i < n; i++)
    {
        int bucket = arr[i] / 10;
        buckets[bucket][num[bucket]] = arr[i];
        num[bucket]++;
    }
    
    //Sort the elements in each bucket
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < num[i]-1; j++)
        {
            for (k = 0; k < num[i]-j-1; k++)
            {
                if (buckets[i][k] > buckets[i][k+1])
                {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k+1];
                    buckets[i][k+1] = temp;
                }
            }
        }
    }
    
    //Concatenate the sorted elements from each bucket
    int index = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < num[i]; j++)
        {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main()
{
    int arr[] = {56, 78, 12, 42, 90, 45, 68, 72, 21, 33};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bucketSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}