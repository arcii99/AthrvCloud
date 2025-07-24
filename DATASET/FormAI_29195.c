//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    int array[MAX_SIZE];
    int i, n;

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Array size too large.");
        return 1;
    }

    printf("Enter %d integer(s) for the array:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Error: Invalid input format.");
            return 1;
        }
    }

    printf("Array contents:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nEnter the index of the element to access: ");
    if (scanf("%d", &i) != 1) {
        printf("Error: Invalid input format.");
        return 1;
    }

    if (i < 0 || i >= n) {
        printf("Error: Index out of range.");
        return 1;
    }

    printf("Array[%d] = %d\n", i, array[i]);

    return 0;
}