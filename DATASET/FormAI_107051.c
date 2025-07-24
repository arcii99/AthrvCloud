//FormAI DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL) {
        printf("Memory allocation failed!");
        exit(0);
    }

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    printf("The elements are: ");
    for(int i = 0; i < n; i++) {
        printf("%d, ", ptr[i]);
    }
    printf("\n");

    printf("The sum of the elements is: %d\n", sum);

    free(ptr);

    return 0;
}