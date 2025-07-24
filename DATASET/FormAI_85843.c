//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int firstElement = 0, secondElement = 1, nextElement, numElements;

    printf("Enter the number of elements in the sequence: ");
    scanf("%d", &numElements);

    printf("Fibonacci Series: %d %d ", firstElement, secondElement);

    for (int i = 2; i < numElements; i++) {
        // find the next element in the sequence
        nextElement = firstElement + secondElement;
        // print the next element in the sequence
        printf("%d ", nextElement);
        // update the variables for the next iteration
        firstElement = secondElement;
        secondElement = nextElement;
    }

    printf("\n");

    return 0;
}