//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* numbers = malloc(sizeof(int) * 5);

    // Add some values to the array
    for(int i = 0; i < 5; i++) {
        // Using pointer arithmetic
        *(numbers + i) = i + 1;
    }

    printf("The values in the array are: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(numbers + i));
    }
    printf("\n");

    // Let's shrink the array
    int* smallerArray = realloc(numbers, sizeof(int) * 3);
    if(smallerArray != NULL) {
        numbers = smallerArray;
    }

    printf("The values in the shrunken array are: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", *(numbers + i));
    }
    printf("\n");

    free(numbers);

    return 0;
}