//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // length of genome sequence
#define MUTATION_RATE 0.01 // probability of mutation

int main(void) {
    // initialize genome sequence
    char genome[GENOME_LENGTH];
    srand(time(NULL));
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // randomly assign base pairs (0-3)
    }
    
    // print original genome
    printf("Original Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%d", genome[i]);
    }
    printf("\n");
    
    // simulate mutation
    for(int i = 0; i < GENOME_LENGTH; i++) {
        if((double) rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = rand() % 4; // randomly assign new base pair
        }
    }
    
    // print mutated genome
    printf("Mutated Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%d", genome[i]);
    }
    printf("\n");
    
    return 0;
}