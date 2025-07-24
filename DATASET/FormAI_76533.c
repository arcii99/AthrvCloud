//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; 
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.");
        exit(0);
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    printf("The elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

    ptr = (int*) realloc(ptr, n * 2 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed.");
        exit(0);
    }

    printf("\nEnter %d more elements: ", n);
    for (int i = n; i < n * 2; i++) {
        scanf("%d", ptr + i);
    }

    printf("The new elements are: ");
    for (int i = 0; i < n * 2; i++) {
        printf("%d ", *(ptr + i));
    }

    free(ptr);

    return 0;
}