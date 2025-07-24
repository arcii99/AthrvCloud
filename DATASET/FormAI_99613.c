//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an int array of size 10
    int *arr = (int*) malloc(10 * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    // Initialize array elements and print them out
    printf("Initial Array: ");
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    // Free memory allocated for array
    free(arr);
    printf("\nMemory has been freed\n");

    // Allocate memory for a string
    char *str = (char*) malloc(20 * sizeof(char));

    // Check if memory allocation was successful
    if (str == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    // Read in a string from user
    printf("Enter a string (max 19 characters): ");
    scanf("%19s", str);

    // Print out the entered string 
    printf("You entered: %s\n", str);

    // Free memory allocated for string
    free(str);
    printf("Memory has been freed\n");

    return 0;
}