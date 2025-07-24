//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Get current time before the benchmarking starts
    clock_t benchmark_start = clock();
    
    //The code that we are going to benchmark
    for (int i=1; i<10000000; i++){
        for (int j=0; j<i; j++){
            int temp = i*j;
        }
    }
    
    //Get current time after the benchmarking has ended
    clock_t benchmark_end = clock();
    
    //Calculate the time taken for benchmarking
    double benchmark_time = (double)(benchmark_end - benchmark_start) / CLOCKS_PER_SEC;
    
    printf("Benchmarking time: %.5f seconds\n", benchmark_time);
    
    return 0;
}