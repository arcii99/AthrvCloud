//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <time.h>

#define N 10000000

double procedure1() {
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        sum += (double)i;
    }
    return sum;
}

double procedure2() {
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        sum += (double)(i * i);
    }
    return sum;
}

double procedure3() {
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        sum += (double)(1.0 / i);
    }
    return sum;
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    
    // Test Procedure 1
    start = clock();
    double result1 = procedure1();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Procedure 1: %lf\n", result1);
    printf("CPU time used: %lf\n\n", cpu_time_used);
    
    // Test Procedure 2
    start = clock();
    double result2 = procedure2();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Procedure 2: %lf\n", result2);
    printf("CPU time used: %lf\n\n", cpu_time_used);
    
    // Test Procedure 3
    start = clock();
    double result3 = procedure3();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Procedure 3: %lf\n", result3);
    printf("CPU time used: %lf\n\n", cpu_time_used);
    
    return 0;
}