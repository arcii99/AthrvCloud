//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

int data[ARRAY_SIZE];
int result[NUM_THREADS] = {0};

void* thread_sum(void* arg){
    int thread_id = (int)arg;
    int i;
    int partial_sum = 0;
    for(i = thread_id*(ARRAY_SIZE/NUM_THREADS); i < (thread_id+1)*(ARRAY_SIZE/NUM_THREADS); i++){
        partial_sum += data[i];
    }
    result[thread_id] = partial_sum;
    pthread_exit(NULL);
}

int main(){
    int i, sum = 0;
    pthread_t threads[NUM_THREADS];

    for(i = 0; i < ARRAY_SIZE; i++){
        data[i] = rand() % 100;
        sum += data[i];
    }

    for(i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, thread_sum, (void*)i);
    }

    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    int thread_sum = 0;
    for(i = 0; i < NUM_THREADS; i++){
        thread_sum += result[i];
    }

    printf("Total sum using %d threads: %d\n", NUM_THREADS, thread_sum);
    printf("Total sum using 1 thread: %d\n", sum);

    return 0;
}