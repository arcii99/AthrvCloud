//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4 // Number of threads
#define NUM_SIMULATIONS 100000 // Number of simulations per thread
#define ALIEN_PROBABILITY 0.02 // Probability of alien invasion

// Function to simulate an alien invasion
void* simulate_invasion(void* thread_id) {
    int* id_ptr = (int*) thread_id;
    int thread_id_val = *id_ptr;
    srand((unsigned) time(NULL) + thread_id_val);
    int count = 0;
    for(int i = 0; i < NUM_SIMULATIONS; i++) {
        float random_num = ((float) rand() / (float) RAND_MAX);
        if(random_num <= ALIEN_PROBABILITY) {
            count++;
        }
    }
    int* invasions = malloc(sizeof(int));
    *invasions = count;
    pthread_exit(invasions);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int total_invasions = 0;
    void* thread_return;
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int status = pthread_create(&threads[i], NULL, simulate_invasion, &thread_ids[i]);
        if(status != 0) {
            printf("Error: Could not create thread %d\n", i);
            exit(-1);
        }
    }
    for(int i = 0; i < NUM_THREADS; i++) {
        int status = pthread_join(threads[i], &thread_return);
        if(status != 0) {
            printf("Error: Could not join thread %d\n", i);
            exit(-1);
        }
        int* invasions = (int*) thread_return;
        total_invasions += *invasions;
        free(invasions);
    }
    float probability = ((float) total_invasions) / ((float) NUM_THREADS * NUM_SIMULATIONS);
    printf("Probability of an alien invasion: %.2f%%\n", probability * 100);
    pthread_exit(NULL);
}