//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;
    int i, sum = 0;

    // allocate memory for the array dynamically
    arr = (int*)malloc(size * sizeof(int));

    // check for successful allocation
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // fill the array with user input
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // calculate and print the sum
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);

    // free the memory allocated for the array
    free(arr);

    return 0;
}