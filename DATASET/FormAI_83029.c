//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ITERATIONS 10000000

double squareRoot(double num) {
    return sqrt(num);
}

double cubeRoot(double num) {
    return cbrt(num);
}

double sine(double angle) {
    return sin(angle);
}

double cosine(double angle) {
    return cos(angle);
}

double tangent(double angle) {
    return tan(angle);
}

int main() {
    double num = 256.0; // Test value
    double angle = 0.5; // Test value
    double result;
    clock_t start, end;
    double cpu_time_used;

    // Square root benchmarking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = squareRoot(num);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Square root took %f seconds\n", cpu_time_used);

    // Cube root benchmarking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = cubeRoot(num);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Cube root took %f seconds\n", cpu_time_used);

    // Sine benchmarking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = sine(angle);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sine took %f seconds\n", cpu_time_used);

    // Cosine benchmarking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = cosine(angle);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Cosine took %f seconds\n", cpu_time_used);

    // Tangent benchmarking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result = tangent(angle);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tangent took %f seconds\n", cpu_time_used);

    return 0;
}