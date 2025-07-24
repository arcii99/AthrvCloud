//FormAI DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdlib.h>

#define MAX_SIZE 100

int main() {

    int* myArray;
    myArray = (int*) malloc(MAX_SIZE * sizeof(int));

    if (myArray == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    printf("Memory allocated successfully.\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        myArray[i] = i * 2;
    }

    printf("Array initialized successfully.\n");

    int sum = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += myArray[i];
    }

    printf("Sum of array elements: %d\n", sum);

    free(myArray);

    printf("Memory freed successfully.\n");

    return 0;
}