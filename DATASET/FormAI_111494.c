//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void bubblesort(int *array, int length) {
    int i, j, temp;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int i;
    int *array = (int*)malloc(ARRAY_SIZE*sizeof(int));
    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    printf("Unsorted:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    bubblesort(array, ARRAY_SIZE);

    printf("\n\nSorted:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}