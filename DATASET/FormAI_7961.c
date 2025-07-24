//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, *ptr, sum = 0;

    printf("Enter the number of integers you want to allocate memory for: ");
    scanf("%d", &size);

    // Allocate memory dynamically using malloc()
    ptr = (int*)malloc(size * sizeof(int));

    // Check if memory is allocated successfully
    if(ptr == NULL) {
        printf("Memory allocation failed.");
        exit(0);
    }

    // Prompt user to enter integers
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);  // Calculate the sum of entered integers
    }

    // Display the sum of entered integers
    printf("Sum of entered integers = %d\n", sum);

    // Free the allocated memory
    free(ptr);

    return 0;
}