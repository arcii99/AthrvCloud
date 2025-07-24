//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[10] = {1, 4, 5, 7, 8, 9, 11, 12, 15, 18};
    int i;

    printf("Original data:");
    for(i = 0; i < 10; i++) {
        printf(" %d", data[i]);
    }

    int smallest = data[0];
    int largest = data[0];

    for(i = 1; i < 10; i++) {
        if(data[i] < smallest) {
            smallest = data[i];
        }
        if(data[i] > largest) {
            largest = data[i];
        }
    }

    printf("\n\nSmallest value in data: %d", smallest);
    printf("\nLargest value in data: %d", largest);

    return 0;
}