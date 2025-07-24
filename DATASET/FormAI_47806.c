//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

double probability;

void *calculateProbability(void *arg) {
    int index = *((int *)arg);
    for(int i = 0; i < 100000000; i++) {
        probability += (double)rand() / (double)RAND_MAX;
    }
    printf("Thread %d finished calculating probability\n", index);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];
    int rc;

    for(int i = 0; i < NUM_THREADS; i++) {
        indexes[i] = i;
        rc = pthread_create(&threads[i], NULL, calculateProbability, (void *)&indexes[i]);
        if(rc) {
            printf("Error: return code from pthread_create is %d\n", rc);
            exit(-1);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            printf("Error: return code from pthread_join is %d\n", rc);
            exit(-1);
        }
    }

    probability /= (double)NUM_THREADS;
    printf("The probability of an alien invasion is %f\n", probability);

    pthread_exit(NULL);
}