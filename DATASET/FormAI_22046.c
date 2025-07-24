//FormAI DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int num, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = (int*) malloc(num * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(0);
    }

    printf("Enter %d elements:\n", num);

    for(i = 0; i < num; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("The sum of elements is %d\n", sum);

    free(ptr);
    ptr = NULL;

    return 0;
}