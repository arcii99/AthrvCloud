//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    double total_time = 0;

    printf("Welcome to the benchmarking program! \n");
    printf("Please enter the number of iterations you want to run: ");
    scanf("%d", &num);

    printf("\nStarting benchmarking... \n");

    for (int i = 0; i < num; i++) {
        clock_t start_time = clock(); // starting the clock
        // Insert the code you want to benchmark here
        for (int j=0; j<10000000; j++){
            int x = rand();
        }
        clock_t end_time = clock(); // stopping the clock
        double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        total_time += time_taken;
        printf("Iteration %d took %f seconds \n", i+1, time_taken);
    }

    printf("\nBenchmarking complete! \n");
    double average_time = total_time / num;
    printf("Average time taken per iteration is %f seconds \n", average_time);

    return 0;
}