//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

void *calc_pi(void *thread_id){
    long tid = (long)thread_id; // Cast thread_id to long

    int iter_per_thread = 100000000 / NUM_THREADS; // Divide total number of iterations by number of threads
    int start = tid * iter_per_thread; // Calculate starting point for each thread
    int end = start + iter_per_thread; // Calculate ending point for each thread

    double pi = 0;
    int sign = 1;

    for (int i = start; i < end; i++){
        pi += (double) sign / (2 * i + 1);
        sign = -sign;
    }

    double *pi_partial = malloc(sizeof(double));
    *pi_partial = 4 * pi;

    pthread_exit((void *) pi_partial);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    void *status;
    double pi_total = 0;

    clock_t start = clock();

    for (t = 0; t < NUM_THREADS; t++){
        rc = pthread_create(&threads[t], NULL, calc_pi, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++){
        pthread_join(threads[t], &status);
        pi_total += *(double *)status;
        free(status);
    }

    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Multi-threaded pi calculation: %.15f\n", pi_total);
    printf("Time taken: %f seconds\n", total_time);

    return 0;
}