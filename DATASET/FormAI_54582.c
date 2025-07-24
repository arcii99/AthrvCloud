//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    int *ptr = NULL;
    int num, i;

    printf("How many integers do you want to enter:");
    scanf("%d", &num);

    ptr = (int *)malloc(num * sizeof(int));

    if (ptr == NULL) {
        printf("Failed to allocate memory");
        exit(1);
    }

    // Storing values in allocated memory
    printf("Enter %d integers:\n", num);

    for (i = 0; i < num; i++) {
        scanf("%d", ptr + i);
    }

    // Displaying values in allocated memory
    printf("Values stored in dynamic memory are:\n");

    for (i = 0; i < num; i++) {
        printf("%d\n", *(ptr + i));
    }

    // Deallocating the memory
    free(ptr);

    printf("Memory has been freed");

    return 0;
}