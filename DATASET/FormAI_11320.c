//FormAI DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocating memory for an integer variable
    int *num = (int*) malloc(sizeof(int));
    if(num == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Taking input from user
    printf("Enter a number: ");
    scanf("%d", num);

    // Printing the entered number
    printf("Your entered number is: %d\n", *num);

    // Reallocating memory for an integer array
    int *arr = (int*) realloc(NULL, 5*sizeof(int));
    if(arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    // Initializing the array
    for(int i=0; i<5; i++) {
        arr[i] = i+1;
    }

    // Printing the array
    printf("The array elements are: ");
    for(int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Freeing the allocated memories
    free(num);
    free(arr);

    return 0;
}