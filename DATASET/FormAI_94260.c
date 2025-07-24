//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define SEQUENCE_LENGTH 1000

char gene_sequence[SEQUENCE_LENGTH];
int read_count;
pthread_mutex_t mutex;

// Thread function to simulate DNA sequencing
void* dna_sequence_simulator(void* arg) {
    int thread_num = *(int*)arg;
    int start_index, end_index;

    start_index = thread_num * (SEQUENCE_LENGTH / MAX_THREADS);
    end_index = (thread_num + 1) * (SEQUENCE_LENGTH / MAX_THREADS);

    for (int i = start_index; i < end_index; i++) {
        if (i % 5 == 0) { // Simulate sequencing error
            gene_sequence[i] = 'N';
        } else {
            gene_sequence[i] = "ACGT"[rand() % 4];
        }
    }

    pthread_mutex_lock(&mutex);
    read_count++;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_nums[MAX_THREADS];

    srand(time(NULL));
    read_count = 0;
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, dna_sequence_simulator, &thread_nums[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Gene sequence: %s\n", gene_sequence);
    printf("Read count: %d\n", read_count);

    pthread_mutex_destroy(&mutex);
    return 0;
}