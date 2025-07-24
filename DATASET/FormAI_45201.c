//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main(void) {
    int *array = (int *) malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("SUM: %d\n", sum);

    free(array);

    return 0;
}