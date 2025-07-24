//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    srand(time(NULL));
    int array[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("The sum is: %d\n", sum);
    return 0;
}