//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX 100 // Maximum number of elements in the array

int main()
{
    int arr[MAX], n, i, j, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort algorithm
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

    printf("Sorted array in ascending order:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}