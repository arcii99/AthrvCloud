//FormAI DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>

// Function to sort an array using Bubble Sort algorithm
void bubbleSort(int arr[], int n) 
{
    int i, j;
    for (i = 0; i < n-1; i++)             
        for (j = 0; j < n-i-1; j++)    
            if (arr[j] > arr[j+1]) {
                // Invasive move, replace elements in original array
                arr[j] = arr[j] - arr[j+1];
                arr[j+1] = arr[j] + arr[j+1];
                arr[j] = arr[j+1] - arr[j];
            }
}

int main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}