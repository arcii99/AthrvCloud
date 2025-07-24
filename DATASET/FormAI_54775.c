//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define LOOP_TIME 1000000000

void test_func() {
    int i = 0;
    while (i < LOOP_TIME) {
        i++;
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    printf("Starting benchmarking program...\n");

    start = clock();
    double test_func_time[10];
    for (int i = 0; i < 10; i++) {
        test_func();
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        test_func_time[i] = cpu_time_used;
        printf("Test Function Run %d Time: %lf\n", i+1, cpu_time_used);
        start = clock();
    }

    double average_time = 0;
    for (int i = 0; i < 10; i++) {
        average_time += test_func_time[i];
    }
    average_time /= 10;
    printf("Average Test Function Run Time: %lf\n", average_time);

    return 0;
}