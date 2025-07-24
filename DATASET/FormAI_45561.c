//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i, j, k;
    int N = 100; // number of elements
    int arr[N];
 
    // fill the array with random values
    for (i = 0; i < N; i++) 
    {
        arr[i] = rand();
    }

    for (i = 0; i < N; i++) 
    {
        for (j = i+1; j < N; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                // swap values
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }

    printf("Sorted Array\n");
    // print the sorted array
    for (i = 0; i < N; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}