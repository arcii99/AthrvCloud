//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000 // length of genome sequence
#define NUM_BASES 4 // number of possible bases in genome sequence
#define MUTATION_RATE 0.01 // probability of mutation occuring

int main(void) {
    srand(time(NULL)); // seed random number generator with current time
    
    // generate random genome sequence
    int genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % NUM_BASES;
    }
    
    // print out the original genome sequence
    printf("Original genome sequence:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n\n");
    
    // introduce mutations in the genome sequence
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) { // mutation occurs
            genome[i] = rand() % NUM_BASES; // generate new base randomly
        }
    }
    
    // print out the mutated genome sequence
    printf("Mutated genome sequence:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n\n");
    
    return 0;
}