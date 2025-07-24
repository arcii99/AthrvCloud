//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, num;

    printf("How many integers do you want to enter?");
    scanf("%d", &num);

    // allocating memory dynamically
    ptr = (int*)malloc(num * sizeof(int));

    // displaying error message if memory allocation fails
    if (ptr == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    printf("Enter the integers: ");

    for (i = 0; i < num; i++) {
        scanf("%d", ptr + i);
    }

    printf("The integers are:");

    for (i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }

    // deallocating the memory
    free(ptr);

    return 0;
}