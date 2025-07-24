//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <time.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int x = 10;
    int y = 20;

    start = clock();
    int result = add(x, y);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The result is %d\n", result);
    printf("CPU time used is %f seconds", cpu_time_used);

    return 0;
}