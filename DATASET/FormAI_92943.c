//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define genome size and function to generate random nucleotides
#define GENOME_SIZE 100
char getRandomNucleotide() {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int randomIndex = rand() % 4;
    return nucleotides[randomIndex];
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random genome
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = getRandomNucleotide();
    }
    
    // Print the genome sequence
    printf("Genome sequence: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // Simulate genome sequencing by introducing mutations
    char mutatedGenome[GENOME_SIZE];
    int mutationCount = 0;
    for (int i = 0; i < GENOME_SIZE; i++) {
        // Introduce a mutation with 10% probability
        if (rand() % 10 == 0) {
            mutatedGenome[i] = getRandomNucleotide();
            mutationCount++;
        } else {
            mutatedGenome[i] = genome[i];
        }
    }
    
    // Print the mutated genome sequence and mutation count
    printf("Mutated genome sequence: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", mutatedGenome[i]);
    }
    printf("\n");
    printf("Number of mutations introduced: %d\n", mutationCount);
    
    return 0;
}