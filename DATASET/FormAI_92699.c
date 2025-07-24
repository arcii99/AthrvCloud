//FormAI DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Future-proof memory management example program
// to demonstrate dynamically allocating memory
// with error-handling and freeing memory to prevent memory leaks

int main() {
    // Declare variables
    int *numArray, numCount;
    int sum = 0;

    // Prompt user for number count
    printf("Enter the number of values to sum: ");
    scanf("%d", &numCount);

    // Dynamically allocate memory for numArray with error-handling
    numArray = (int *) malloc(numCount * sizeof(int));
    if (numArray == NULL) {
        printf("Error: Unable to allocate memory");
        exit(1);
    }

    // Prompt user to enter numbers and store them in numArray
    printf("Enter %d integers: ", numCount);
    for (int i = 0; i < numCount; i++) {
        scanf("%d", &numArray[i]);
        sum += numArray[i];
    }

    // Output sum of numbers and free memory to prevent memory leaks
    printf("The sum is %d\n", sum);
    free(numArray);

    return 0;
}