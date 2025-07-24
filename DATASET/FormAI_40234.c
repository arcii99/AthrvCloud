//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numArray;  // declare pointer to integer array

    // allocate memory for array of 5 integers
    numArray = (int*) malloc(5 * sizeof(int));
    if (numArray == NULL) {  // check for errors in allocation
        printf("Error: failed to allocate memory for array.\n");
        return 1;
    }

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numArray[i]);  // read integers into array
    }

    printf("\nNumbers you entered:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numArray[i]);  // print all integers in array
    }
    printf("\n");

    free(numArray);  // release allocated memory

    return 0;  // exit program
}