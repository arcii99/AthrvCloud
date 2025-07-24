//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.1

int main() {
    char genome[GENOME_LENGTH];
    srand(time(NULL));
    
    // Generate a random genome
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = rand() % 4;
    }

    // Print the original genome
    printf("Original genome: ");
    for(int i=0; i<GENOME_LENGTH; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");

    // Mutate the genome
    for(int i=0; i<GENOME_LENGTH; i++) {
        if((double)rand() / (double)RAND_MAX < MUTATION_RATE) {
            genome[i] = rand() % 4;
        }
    }

    // Print the mutated genome
    printf("Mutated genome: ");
    for(int i=0; i<GENOME_LENGTH; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");

    return 0;
}