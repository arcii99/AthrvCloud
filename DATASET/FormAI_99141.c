//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 10000000

void perform_math_operations(){

    volatile double a = 34.56;
    volatile double b = 67.89;
    volatile double c = 123.45;
    volatile double d = 678.90;
    volatile double e = 910.11;
    
    for(int i = 0; i < NUM_ITERATIONS; i++){
        
        a *= b;
        a /= c;
        a += d;
        a -= e;
        
    }
}

int main(){

    clock_t start_time, end_time;
    double total_cpu_time_taken;
    
    start_time = clock();
    
    perform_math_operations();
    
    end_time = clock();
    
    total_cpu_time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("The total CPU time taken is %lf seconds to perform %d math operations.\n", total_cpu_time_taken, NUM_ITERATIONS);
    
    return 0;
}