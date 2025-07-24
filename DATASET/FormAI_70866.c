//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10000

int main(void) {
    // Initialize random number generator
    srand(time(NULL));
    
    // Generate random genome
    int genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // 0 = A, 1 = C, 2 = G, 3 = T
    }
    
    // Simulate sequencing errors by randomly changing some of the bases
    int num_errors = GENOME_LENGTH / 100; // introduce one error per 100 bases
    for (int i = 0; i < num_errors; i++) {
        int error_pos = rand() % GENOME_LENGTH;
        int error_base = rand() % 4;
        genome[error_pos] = error_base;
    }
    
    // Simulate sequencing reads by randomly selecting a starting position and a read length
    int num_reads = 1000;
    for (int i = 0; i < num_reads; i++) {
        // Select starting position
        int start_pos = rand() % (GENOME_LENGTH - 100); // reads cannot be longer than 100 bases
        
        // Select read length
        int read_length = rand() % 100 + 1; // minimum read length is 1
        
        // Print read
        printf(">%d_%d_%d\n", i, start_pos, read_length);
        for (int j = 0; j < read_length; j++) {
            printf("%c", "ACGT"[genome[start_pos + j]]);
        }
        printf("\n");
    }
    
    return 0;
}