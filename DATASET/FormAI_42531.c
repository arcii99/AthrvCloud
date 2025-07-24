//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <time.h>

int main()
{
    int n, i, j, temp;
    clock_t start, end; // declare variables for time measurement
    
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the array elements:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    // Start measuring time
    start = clock();
    
    // Bubble Sort Algorithm
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // End measuring time
    end = clock();
    
    printf("Sorted Array:\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    printf("\nTime taken for sorting: %f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
    
    return 0;
}