//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* dynamicArray = NULL;
    int arraySize = 10;

    dynamicArray = (int*) malloc(sizeof(int) * arraySize);

    if (dynamicArray != NULL) {
        printf("Dynamic array created successfully!\n");
    } else {
        printf("Failed to create dynamic array.\n");
        return -1;
    }

    for (int i = 0; i < arraySize; i++) {
        dynamicArray[i] = i;
    }

    printf("Printing the dynamic array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", dynamicArray[i]);
    }

    arraySize = 15;
    int* biggerDynamicArray = (int*) realloc(dynamicArray, sizeof(int) * arraySize);

    if (biggerDynamicArray != NULL) {
        printf("\n\nDynamic array resized successfully!\n");
        dynamicArray = biggerDynamicArray;
    } else {
        printf("\n\nFailed to resize dynamic array.\n");
        return -1;
    }

    for (int i = 10; i < arraySize; i++) {
        dynamicArray[i] = i;
    }

    printf("Printing the bigger dynamic array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", dynamicArray[i]);
    }

    free(dynamicArray);

    printf("\n\nDynamic array freed.\n");

    return 0;
}