//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // Declare and initialize an integer variable
    int n = 5;
    printf("You have selected to create an array of %d integers.\n", n);

    // Dynamically allocate memory using malloc()
    int *arr = (int*)malloc(n * sizeof(int));

    // Check if memory is allocated successfully
    if (arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Memory allocated successfully!\n");

    // Initialize values in the dynamically allocated array
    for (int i = 0; i < n; i++) 
    {
        arr[i] = i + 1; // Store the i'th integer in the i'th element of arr
    }

    // Print out values in the dynamically allocated array
    printf("Values in the dynamically allocated array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    // Release dynamically allocated memory using free()
    free(arr);

    printf("\nMemory released successfully!\n");

    return 0;
}