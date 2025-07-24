//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 10000

// Global variables for sharing among threads
char genome[MAX_LENGTH];
int genome_length = 0;
int number_of_threads = 4;

// Function to be executed by each thread
void *simulate_sequencing(void *arg) {
    int thread_id = *(int*)arg;
    int start_index = thread_id * genome_length / number_of_threads;
    int end_index = (thread_id + 1) * genome_length / number_of_threads;
    
    // Perform sequencing on the portion of genome assigned to this thread
    for (int i = start_index; i < end_index; i++) {
        switch(genome[i]) {
            case 'A':
                printf("Thread %d: Adenine\n", thread_id);
                break;
            case 'C':
                printf("Thread %d: Cytosine\n", thread_id);
                break;
            case 'G':
                printf("Thread %d: Guanine\n", thread_id);
                break;
            case 'T':
                printf("Thread %d: Thymine\n", thread_id);
                break;
            default:
                printf("Thread %d: Unknown nucleotide\n", thread_id);
        }
    }
    return NULL;
}

int main() {
    // Get genome from user input
    printf("Enter genome sequence (maximum length %d): ", MAX_LENGTH);
    fgets(genome, MAX_LENGTH, stdin);
    
    // Determine actual length of genome
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (genome[i] == '\n') {
            genome[i] = '\0';
            break;
        }
        genome_length++;
    }
    
    // Create threads and execute sequencing
    pthread_t threads[number_of_threads];
    int thread_ids[number_of_threads];
    for (int i = 0; i < number_of_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, simulate_sequencing, &thread_ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < number_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}