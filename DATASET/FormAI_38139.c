//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

/* Function to print array */
void printArr(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Bucket sort implementation */
void bucketSort(int arr[], int n)
{
    // Create buckets
    int buckets[BUCKET_SIZE][n];
    int sizes[BUCKET_SIZE] = {0};
    
    // Determine the max value
    int maxVal = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    // Calculate number of digits in the max value
    int numDigit = 0, temp = maxVal;
    while(temp) {
        numDigit++;
        temp /= 10;
    }
    
    // Place the elements in the appropriate bucket
    for(int i=1; i<=numDigit; i++) {
        for(int j=0; j<n; j++) {
            int digit = (arr[j] / (int) pow(10, i-1)) % 10;
            buckets[digit][sizes[digit]++] = arr[j];
        }
        
        // Copy the elements back to the original array
        int k = 0;
        for(int j=0; j<BUCKET_SIZE; j++) {
            for(int l=0; l<sizes[j]; l++) {
                arr[k++] = buckets[j][l];
            }
            sizes[j] = 0;
        }
    }
}

int main()
{
    // Generate random array
    int arr[10];
    srand(time(0));
    for(int i=0; i<10; i++) {
        arr[i] = rand() % 100;
    }
    
    // Print unsorted array
    printf("Unsorted Array: ");
    printArr(arr, 10);
    
    // Sort the array using bucket sort
    bucketSort(arr, 10);
    
    // Print sorted array
    printf("Sorted Array: ");
    printArr(arr, 10);

    return 0;
}