//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Memory Management Fun Fair!\n");
    printf("Get ready for a wild ride!\n\n");

    // Allocate memory for an integer array
    int num_elements = 5;
    int *int_array = (int*)malloc(num_elements * sizeof(int));

    if (int_array == NULL) {
        printf("Oops, not enough memory!\n");
        return 1;
    }

    // Populate the array with some numbers
    for (int i = 0; i < num_elements; i++) {
        int_array[i] = i * 10;
    }

    printf("Here is your array: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n\n");

    // Reallocate memory for a larger integer array
    num_elements = 10;
    int *new_int_array = (int*)realloc(int_array, num_elements * sizeof(int));

    if (new_int_array == NULL) {
        printf("Oops, not enough memory!\n");
        free(int_array);
        return 1;
    }

    int_array = new_int_array;

    // Populate the larger array with some more numbers
    for (int i = 5; i < num_elements; i++) {
        int_array[i] = i * 10;
    }

    printf("Here is your new array: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n\n");

    // Free the memory
    free(int_array);

    printf("Thanks for visiting the Memory Management Fun Fair! Come back soon!\n");

    return 0;
}