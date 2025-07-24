//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <time.h>

// The function we will benchmark
int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Main function
int main(){
    int n = 40;
    clock_t start, end;
    double time_used;

    start = clock();
    int result = fibonacci(n);
    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Result: %d\n", result);
    printf("Time taken: %f seconds\n", time_used);

    return 0;
}