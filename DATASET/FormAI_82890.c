//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void mat_mul(int a[][SIZE], int b[][SIZE], int c[][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            c[i][j] = 0;
            for (int k=0; k<SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

int main() {
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            a[i][j] = i+j;
            b[i][j] = i*j;
            c[i][j] = 0;
        }
    }
    double before = get_time();
    mat_mul(a, b, c);
    double after = get_time();
    printf("Multiplication took %.3f seconds.\n", after - before);
    return 0;
}