//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

// Bucket sort function
void bucketSort(int arr[], int n)
{
    // Create 10 buckets, each for a specific range
    int buckets[10][n];
    
    // Initialize bucket
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<n; j++)
        {
            buckets[i][j] = -1;
        }
    }
    
    // Divide the elements of the array into buckets
    for(int i=0; i<n; i++)
    {
        int bucketIndex = (arr[i]/10);
        
        for(int j=0; j<n; j++)
        {
            if(buckets[bucketIndex][j] == -1)
            {
                buckets[bucketIndex][j] = arr[i];
                break;
            }
        }
    }
    
    // Sort individual buckets
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(buckets[i][j] > buckets[i][k])
                {
                    // Swap the elements
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }
    
    // Concatenate the sorted buckets to get the sorted array
    int index = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(buckets[i][j] != -1)
            {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {34, 10, 78, 35, 89, 42, 23, 56, 32, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Before sorting:\n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("After sorting:\n");
    printArray(arr, n);
    
    return 0;
}