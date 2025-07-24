//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array, n, i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    array = (int*)malloc(n * sizeof(int));

    // Check if memory was successfully allocated
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Prompt user to enter numbers and store in array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    // Display the sum of the elements
    printf("The sum of the elements is: %d\n", sum);

    // Free memory allocated to the array
    free(array);

    return 0;
}