//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define NUCLEOTIDES_LENGTH 4
#define MUTATION_RATE 0.01

char nucleotides[NUCLEOTIDES_LENGTH] = {'A', 'C', 'G', 'T'};

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create a random genome
    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = nucleotides[rand() % NUCLEOTIDES_LENGTH];
    }
    
    // Print the original genome and its length
    printf("Original genome: %s\n", genome);
    printf("Length of genome: %d\n", GENOME_LENGTH);

    // Mutate the genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        // Check if mutation occurs
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            // Mutate the nucleotide
            genome[i] = nucleotides[rand() % NUCLEOTIDES_LENGTH];
        }
    }
    
    // Print the mutated genome and its length
    printf("Mutated genome: %s\n", genome);
    printf("Length of genome: %d\n", GENOME_LENGTH);
    
    return 0;
}