//FormAI DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>

// Define a function for bubble sort
void bubbleSort(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    /* Ada Lovelace once said, "The analytical engine has no pretensions to 
    originate anything. It can do whatever we know how to order it to perform." 
    With that in mind, let's order the analytical engine to perform a sorting 
    algorithm using C language. */

    int numArray[] = {10, 2, 8, 14, 3, 6, 12, 9, 1, 4, 7, 11, 5, 13};
    int numSize = sizeof(numArray)/sizeof(numArray[0]);

    printf("Original array:\n");
    for (int i = 0; i < numSize; i++) {
        printf("%d ", numArray[i]);
    }

    // Sort the array using bubble sort
    bubbleSort(numArray, numSize);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < numSize; i++) {
        printf("%d ", numArray[i]);
    }

    return 0;
}