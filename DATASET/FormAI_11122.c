//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my fantastic memory management program!\n\n");

    // Using malloc to dynamically allocate memory
    int *arr = (int*) malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Uh-oh, something went wrong while allocating memory!\n");
        return 0;
    }

    // Using a for loop to populate the array with values
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Using a for loop to print out each value in the array
    printf("The values in the array are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Using realloc to resize the dynamically allocated memory
    int *new_arr = (int*) realloc(arr, 20 * sizeof(int));
    if (new_arr == NULL) {
        printf("Uh-oh, something went wrong while reallocating memory!\n");
        free(arr);
        return 0;
    }
    arr = new_arr;

    // Using a for loop to populate the rest of the array with values
    for (int i = 10; i < 20; i++) {
        arr[i] = i * 3;
    }

    // Using a for loop to print out each value in the array
    printf("The new values in the array are:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Using free to deallocate the dynamically allocated memory
    free(arr);
    printf("\nMemory has been successfully deallocated!\n");
    printf("Thank you for using my awesome memory management program!\n");

    return 0;
}