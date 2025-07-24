//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000
#define MIN_VALUE 0
#define MAX_VALUE 100

int findMinimum(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int* randomData(int size, int min, int max) {
    int* data = (int*) malloc(size * sizeof(int));
    srand(time(0));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % (max - min + 1) + min;
    }
    return data;
}

int main() {
    int* data = randomData(DATA_SIZE, MIN_VALUE, MAX_VALUE);
    printf("Generated Data:\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int min = findMinimum(data, DATA_SIZE);

    printf("Minimum Value: %d\n", min);

    free(data);

    return 0;
}