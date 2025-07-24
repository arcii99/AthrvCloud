//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

/* Define the math function to be tested */
int math_function(int input) {
    return input * input + input - 1;
}

/* Define the benchmarking function */
long long benchmark(int (*func)(int), int* data, int size) {
    clock_t start, end;
    long long total_time = 0;
    for (int i = 0; i < size; i++) {
        start = clock();
        func(data[i]);
        end = clock();
        total_time += (end - start);
    }
    return total_time;
}

/* Test the math function */
int main() {
    int data[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 1000;
    }
    long long time_taken = benchmark(math_function, data, SIZE);
    printf("Average time taken to execute math_function: %lld cycles\n", time_taken/SIZE);
    return 0;
}