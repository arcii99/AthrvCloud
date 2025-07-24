//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int num;
    printf("How many integers would you like to store? ");
    scanf("%d", &num);

    ptr = (int*)calloc(num, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    for (int i = 0; i < num; i++) {
        printf("Enter integer #%d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    printf("You entered: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    free(ptr);

    return 0;
}