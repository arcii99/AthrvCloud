//FormAI DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Custom sorting function
void mySortingFunction(int numbers[], int size) {
    int i, j, temp;

    for(i=0; i<size-1; i++) {
        for(j=0; j<size-i-1; j++) {
            // If current element is greater than the next element, swap them
            if(numbers[j] > numbers[j+1]) {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
}

int main() {
    int numbers[10] = {7, 3, 14, 8, 1, 25, 11, 6, 2, 19};
    int size = 10, i;

    printf("Before sorting: ");
    for(i=0; i<size; i++) {
        printf("%d ", numbers[i]);
    }

    mySortingFunction(numbers, size);

    printf("\nAfter sorting: ");
    for(i=0; i<size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}