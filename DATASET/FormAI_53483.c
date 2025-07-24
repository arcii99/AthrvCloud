//FormAI DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter the number of integers to allocate memory for:\n");
    scanf("%d", &n);

    int* ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    printf("The integers entered are:\n");
    for (i=0; i<n; i++) {
        printf("%d\n", *(ptr + i));
    }

    free(ptr);
    return 0;
}