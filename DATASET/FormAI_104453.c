//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Visionary style sorting program
int main()
{
    int n, i, j, temp;

    // Get the number of elements to be sorted
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int* arr = (int*)malloc(n * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nUnsorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Sort the array using bubble sort algorithm
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

    printf("\n\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Free the dynamically allocated memory
    free(arr);

    printf("\n\nVisionary Style Sorting Program Complete!");

    return 0;
}