//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n = malloc(sizeof(int));
    if(n == NULL) {
        printf("Memory allocation failed! Exiting program..");
        exit(1);
    }
    printf("Enter a number: ");
    scanf("%d", n);

    printf("Value entered: %d\n", *n);

    free(n);
    printf("Memory freed successfully.\n");

    return 0;
}