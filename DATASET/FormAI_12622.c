//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 100000000

int main(int argc, char* argv[]) {
    double x, y, z, pi;
    int i, count = 0;
    srand(time(NULL));

    for (i = 0; i < MAX_ITER; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1)
            count++;
    }
    pi = 4 * count / (double)MAX_ITER;

    printf("Approximated pi: %lf\n", pi);
}