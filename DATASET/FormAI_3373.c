//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* arr = (int*) malloc(sizeof(int) * 5); // allocate memory for an array of 5 integers
    if (arr == NULL) { // check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // initialize array with values 1 to 5
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    printf("The array is: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    // resize array to hold 10 integers
    int* resized_arr = (int*) realloc(arr, sizeof(int) * 10);
    if (resized_arr == NULL) { // check if memory reallocation was successful
        printf("Memory reallocation failed.\n");
        free(arr); // free previously allocated memory
        return 1;
    }
    
    // initialize new elements in resized array with values 6 to 10
    for (int i = 5; i < 10; i++) {
        resized_arr[i] = i + 1;
    }
    
    printf("\nThe resized array is: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", resized_arr[i]);
    }
    
    free(resized_arr); // free dynamically allocated memory
    
    return 0;
}