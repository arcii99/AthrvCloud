//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 4096
#define ITERATIONS 500000

double test_speed() {
    clock_t t1, t2;
    double elapsedTime;
    int i, j;
    char buffer[BUFFER_SIZE];

    srand((unsigned) time(NULL));

    t1 = clock();
    for (i = 0; i < ITERATIONS; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            buffer[j] = rand() % 256;
        }
    }
    t2 = clock();

    elapsedTime = (double) (t2 - t1) / CLOCKS_PER_SEC;
    return elapsedTime;
}

int main() {
    double elapsedTime = test_speed();
    printf("Took %f seconds to perform %d iterations of %d byte buffer.\n", elapsedTime, ITERATIONS, BUFFER_SIZE);
    return 0;
}