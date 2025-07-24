//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    printf("Welcome to the Happy Benchmarking Program!\n");

    int num_iterations;
    printf("Please enter the number of iterations you'd like to run: ");
    scanf("%d", &num_iterations);

    double total_time = 0.0;

    for (int i = 0; i < num_iterations; i++) {
        clock_t start_time = clock();

        // Code to be benchmarked
        for (int j = 0; j < 1000000000; j++) {
            int num = rand() % 100;
            if (num == 50) {
                printf("Happy Benchmarking!\n");
            }
        }

        clock_t end_time = clock();
        double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

        printf("Iteration #%d took %f seconds.\n", i+1, elapsed_time);
        total_time += elapsed_time;
    }

    printf("All iterations completed.\n");
    printf("Average time per iteration: %f seconds.\n", total_time / num_iterations);

    printf("Thanks for benchmarking with us! Have a happy day!\n");

    return 0;
}