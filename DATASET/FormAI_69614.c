//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr; // pointer to int array
    int num_elements; // number of elements in array

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    // allocate memory dynamically
    arr = (int*) malloc(num_elements * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // read array values from user
    printf("Enter %d integer values: ", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    // calculate sum of array elements
    int sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    // free dynamically allocated memory
    free(arr);

    return 0;
}