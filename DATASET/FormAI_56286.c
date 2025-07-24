//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define GENOME_LENGTH 1000  // Length of genome to be sequenced
#define READ_LENGTH 100     // Length of each read

char genome[GENOME_LENGTH];  // Global variable to store genome

// Function to randomly generate genome sequence
void generate_genome() {
    int i;
    srand(time(NULL));  // Initialize seed for random number generation

    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = "ACGT"[rand() % 4];  // Generate random nucleotide, either A, C, G or T
    }
}

// Function to generate random reads from genome
void generate_reads(char *reads, int num_reads) {
    int i, j, start;
    srand(time(NULL));  // Initialize seed for random number generation

    for (i = 0; i < num_reads; i++) {
        start = rand() % (GENOME_LENGTH - READ_LENGTH + 1);  // Generate random start position for read
        for (j = 0; j < READ_LENGTH; j++) {
            reads[i * READ_LENGTH + j] = genome[start + j];  // Copy nucleotide from genome to read
        }
    }
}

// Function to distribute work among threads
void *worker_thread(void *arg) {
    char *reads = (char *) arg;
    int thread_num = *((int *)(&reads[0]));  // Get thread number from first element of reads array
    int num_reads = *((int *)(&reads[4]));  // Get number of reads from next 4 bytes of reads array

    printf("Thread %d processing %d reads\n", thread_num, num_reads);

    // Generate random reads from genome
    generate_reads(&reads[8], num_reads);

    pthread_exit(NULL);
}

int main() {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    char thread_reads[NUM_THREADS][8 + NUM_THREADS * READ_LENGTH];  // Allocate memory for thread reads

    printf("Generating genome sequence...\n");
    generate_genome();  // Generate random genome sequence
    printf("Genome sequence generated\n");

    for (i = 0; i < NUM_THREADS; i++) {
        *((int *)(&thread_reads[i][0])) = i;             // Store thread number in first element of thread reads
        *((int *)(&thread_reads[i][4])) = READ_LENGTH;   // Store number of reads in next 4 bytes of thread reads
        rc = pthread_create(&threads[i], NULL, worker_thread, (void *) &thread_reads[i]);  // Create thread to process reads
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete execution
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: Return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads completed execution\n");

    return 0;
}