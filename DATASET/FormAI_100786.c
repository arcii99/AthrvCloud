//FormAI DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // allocating memory dynamically for the array
    int* arr = (int*) malloc(n * sizeof(int));

    // Checking if memory was successfully allocated
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("\nSum of array elements = %d\n", sum);

    // freeing allocated memory
    free(arr);

    return 0;
}