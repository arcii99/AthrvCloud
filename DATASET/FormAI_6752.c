//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, *ptr, sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    ptr = (int*) malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Failed to allocate memory");
        exit(0);
    }

    printf("Memory allocated successfully\n");

    // assigning values to the array
    for (int i = 0; i < size; i++) {
        *(ptr + i) = i + 1;
    }

    // calculating the sum of the array elements
    for (int i = 0; i < size; i++) {
        sum += *(ptr + i);
    }

    printf("Sum of the array elements = %d\n", sum);

    // freeing the allocated memory
    free(ptr);

    printf("Memory freed successfully\n");

    return 0;
}