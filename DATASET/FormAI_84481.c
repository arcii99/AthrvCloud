//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define N 100  // number of nucleotides in the genome
#define MAX_MUTATIONS 10  // maximum number of mutations to introduce
#define MUTATION_PROBABILITY 0.01  // probability of a mutation occurring

char genome[N+1];  // the genome sequence
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // mutex for thread synchronization
bool finished = false;  // flag to indicate when simulation is finished

void random_fill_genome() {
    for (int i = 0; i < N; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
            default:
                break;
        }
    }
    genome[N] = '\0';
}

void print_genome() {
    printf("%s\n", genome);
}

void introduce_mutations() {
    int mutations = rand() % MAX_MUTATIONS;
    for (int i = 0; i < mutations; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_PROBABILITY) {
            int index = rand() % N;
            int r = rand() % 3;
            switch (r) {
                case 0:
                    genome[index] = 'A';
                    break;
                case 1:
                    genome[index] = 'C';
                    break;
                case 2:
                    genome[index] = 'G';
                    break;
                case 3:
                    genome[index] = 'T';
                    break;
                default:
                    break;
            }
        }
    }
}

void *simulation_thread(void *arg) {
    while (!finished) {
        pthread_mutex_lock(&mutex);
        introduce_mutations();
        print_genome();
        pthread_mutex_unlock(&mutex);
        usleep(10000); // sleep for 10 milliseconds
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    random_fill_genome();
    
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, simulation_thread, NULL);
    if (rc != 0) {
        printf("Error: could not create thread\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Press enter to exit\n");
    getchar();
    finished = true;
    
    rc = pthread_join(thread, NULL);
    if (rc != 0) {
        printf("Error: could not join thread\n");
        exit(EXIT_FAILURE);
    }
    
    pthread_mutex_destroy(&mutex);
    return 0;
}