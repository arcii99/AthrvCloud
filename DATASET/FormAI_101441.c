//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5

typedef struct {
    int aliens;
    int probes;
    double probability;
} InvasionData;

void* calculate_prob(void* arg) {
    InvasionData* idata = (InvasionData*) arg;
    if (idata->probes != 0) {
        idata->probability = ((double)idata->aliens / (double)idata->probes) * 100.0;
    } else {
        idata->probability = 0.0;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    InvasionData* idata[NUM_THREADS];
    int aliens[NUM_THREADS] = {5000, 10000, 15000, 20000, 25000};
    int probes[NUM_THREADS] = {10000, 20000, 30000, 40000, 50000};

    for (int i = 0; i < NUM_THREADS; i++) {
        idata[i] = (InvasionData*) malloc(sizeof(InvasionData));
        idata[i]->aliens = aliens[i];
        idata[i]->probes = probes[i];
        idata[i]->probability = 0.0;

        pthread_create(&threads[i], NULL, calculate_prob, (void*) idata[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Invasion Data #%d: Aliens - %d, Probes - %d, Probability - %.2f%%\n",
               i+1, idata[i]->aliens, idata[i]->probes, idata[i]->probability);
        free(idata[i]);
    }
    pthread_exit(NULL);
    return 0;
}