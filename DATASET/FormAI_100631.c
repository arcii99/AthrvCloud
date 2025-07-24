//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array
    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        exit(0);
    }

    // Prompt user to input array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    // Print array elements and their sum
    printf("Elements in array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

    printf("\nSum of all elements: %d", sum);

    // Free dynamically allocated memory
    free(ptr);

    return 0;
}