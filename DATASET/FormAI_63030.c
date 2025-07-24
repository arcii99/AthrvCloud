//FormAI DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    ptr = (int*) calloc(n, sizeof(int));
    if(ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated.\n");
        for(i = 0; i < n; ++i) {
            *(ptr + i) = i + 1;
        }
        printf("The elements of the array are: ");
        for(i = 0; i < n; ++i) {
            printf("%d  ", *(ptr + i));
        }
        ptr = realloc(ptr, n * sizeof(int) * 2);
        printf("\nMemory successfully re-allocated using realloc.\n");
        for(i = n; i < 2 * n; ++i) {
            *(ptr + i) = i + 1;
        }
        printf("The elements of the array after reallocation are: ");
        for(i = 0; i < 2 * n; ++i) {
            printf("%d  ", *(ptr + i));
        }
        free(ptr);
        printf("\nMemory successfully freed.\n");
    }
    return 0;
}