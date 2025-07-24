//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// function to implement bucket sort
void bucketSort(int arr[], int n)
{
    // create array of buckets
    int max_val = 100; // maximum value of array elements
    int bucket[max_val]; 
    for(int i=0; i<max_val; i++){
        bucket[i] = 0;
    }
    
    // distribute elements into buckets
    for(int i=0; i<n; i++){
        bucket[arr[i]]++;
    }
    
    // sort elements inside each bucket
    for(int i=0; i<max_val; i++){
        for(int j=0; j<bucket[i]; j++){
            printf("%d ", i);
        }
    }
}

// main function to test bucket sort
int main()
{
    int arr[] = {23, 67, 87, 12, 45, 78, 10, 4, 33, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nSorted array: ");
    bucketSort(arr, n);
    
    return 0;
}