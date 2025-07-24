//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define global variables
#define GENOME_SIZE 1000
char genome[GENOME_SIZE]; // the genome to sequence
int index = 0; // the current index being sequenced

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // thread-safe lock

// Function to generate random genome
void generate_genome() {
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = "ATGC"[rand() % 4];
    }
}

// Thread function to sequence genome
void* sequence_genome(void* arg) {
    int id = *(int*) arg;
    while (index < GENOME_SIZE) {
        // Acquire lock before accessing shared variable
        pthread_mutex_lock(&lock);
        int current_index = index;
        index++;
        // Release lock after accessing shared variable
        pthread_mutex_unlock(&lock);
        
        // If all indices have been sequenced, exit thread
        if (current_index >= GENOME_SIZE) {
            break;
        }
        
        // Simulate sequencing process
        printf("Thread %d sequencing index %d (%c)\n", id, current_index, genome[current_index]);
        usleep(rand() % 1000);
    }
    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Generate random genome
    generate_genome(); 
    
    // Create threads
    pthread_t threads[4];
    int thread_ids[4];
    for (int i = 0; i < 4; i++) {
        thread_ids[i] = i;
        int status = pthread_create(&threads[i], NULL, sequence_genome, (void*) &thread_ids[i]);
        if (status != 0) {
            printf("Error creating thread %d: %s\n", i, strerror(status));
        }
    }
    
    // Join threads
    for (int i = 0; i < 4; i++) {
        int status = pthread_join(threads[i], NULL);
        if (status != 0) {
            printf("Error joining thread %d: %s\n", i, strerror(status));
        }
    }
    
    // Done sequencing genome
    printf("Sequencing complete!\n");
    
    // Exit program
    return 0;
}