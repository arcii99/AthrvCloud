//FormAI DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_ITERATIONS 1000000

void random_work() {
    // Simulate some random work with a sleep function
    int rng = rand() % 5;
    sleep(rng);
}

int main() {
    printf("=== Benchmark Started ===\n");

    // Initialize variables for time tracking
    clock_t start, end;
    double cpu_time_used = 0;

    // Start the benchmark for single process
    printf("\n== SINGLE PROCESS ==\n");
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        random_work();
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total CPU Time Used: %f seconds\n", cpu_time_used);

    // Start the benchmark for parent-child processes
    printf("\n== PARENT-CHILD PROCESSES ==\n");
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        if (fork() == 0) {
            random_work();
            exit(0);
        } else {
            wait(NULL);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total CPU Time Used: %f seconds\n", cpu_time_used);

    // Start the benchmark for multi-threading
    printf("\n== MULTI-THREADING ==\n");
    start = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *(*)(void *)) random_work, NULL);
        pthread_join(thread_id, NULL);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Total CPU Time Used: %f seconds\n", cpu_time_used);
    
    printf("\n=== Benchmark Finished ===\n");
    return 0;
}