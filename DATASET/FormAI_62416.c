//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 1000000
#define MAX_RANDOM_NUMBER 100

void performCalculation(int *array, int length) {
    for(int i = 0; i < length; i++) {
        int value = array[i];
        int result = 0;
        for(int j = 0; j < value; j++) {
            result += j * value;
        }
        array[i] = result;
    }
}

int main() {
    int array[ARRAY_LENGTH];
    srand(time(NULL));
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        array[i] = rand() % MAX_RANDOM_NUMBER + 1;
    }
    clock_t start = clock();
    performCalculation(array, ARRAY_LENGTH);
    clock_t end = clock();
    double timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", timeElapsed);
    return 0;
}