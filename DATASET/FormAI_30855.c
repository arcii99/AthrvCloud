//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory using calloc()
    ptr = (int*) calloc(n, sizeof(int));

    // Check if memory is successfully allocated
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // Get values from user and store in the dynamically allocated memory
    printf("Enter values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    // Display the values and sum
    printf("\nElements in the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\nSum of elements: %d", sum);

    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}