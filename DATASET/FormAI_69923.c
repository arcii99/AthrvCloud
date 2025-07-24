//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, n, i;

    printf("Enter the number of integers you want to store: ");
    scanf("%d", &n);

    /* allocate memory dynamically */
    ptr = (int*)malloc(n * sizeof(int));

    /* if memory was allocated successfully */
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    } else {
        printf("Memory allocation successful.\n");
    }

    /* get input from user */
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr+i);
    }

    /* print the integers */
    printf("Integers entered:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr+i));
    }

    /* free allocated memory */
    free(ptr);

    return 0;
}