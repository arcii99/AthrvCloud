//FormAI DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;

    printf("Enter two numbers: ");
    if (scanf("%d%d", &num1, &num2) != 2) {
        fprintf(stderr, "Invalid input provided. Please try again.\n");
        exit(EXIT_FAILURE); // Exit program with error code
    }

    if (num2 == 0) {
        fprintf(stderr, "Divide by zero error. Please try again.\n");
        exit(EXIT_FAILURE); // Exit program with error code
    }

    result = num1 / num2;
    printf("%d divided by %d is equal to %d\n", num1, num2, result);

    int* array = malloc(sizeof(int) * 10);
    if (array == NULL) {
        fprintf(stderr, "Failed to allocate memory. Program cannot continue.\n");
        exit(EXIT_FAILURE); // Exit program with error code
    }

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    printf("Array contents: ");
    for (int i = 0; i <= 10; i++) { // Intentional off-by-one error
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}