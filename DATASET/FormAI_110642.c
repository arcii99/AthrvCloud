//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for genome simulation
#define GENOME_LENGTH 100
#define NUM_GENOME_SEQUENCES 1000
#define RANDOM_BASE_CHANCE 20

// Define a struct for holding genome sequence data
typedef struct {
    char sequence[GENOME_LENGTH];
    int num_mutations;
} GenomeSequence;

// Function to generate a random base (A, C, G, or T)
char randomBase() {
    int randomNum = rand() % 100;
    if (randomNum < 25) {
        return 'A';
    } else if (randomNum < 50) {
        return 'C';
    } else if (randomNum < 75) {
        return 'G';
    } else {
        return 'T';
    }
}

// Function to simulate a mutation occurring in the genome sequence
char mutateBase(char base) {
    int randomNum = rand() % 100;
    if (randomNum < RANDOM_BASE_CHANCE) {
        if (base == 'A') {
            return 'C';
        } else if (base == 'C') {
            return 'A';
        } else if (base == 'G') {
            return 'T';
        } else {
            return 'G';
        }
    } else {
        return base;
    }
}

// Function to generate a random genome sequence
GenomeSequence generateGenomeSequence() {
    GenomeSequence sequence;
    sequence.num_mutations = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        sequence.sequence[i] = randomBase();
    }
    return sequence;
}

// Function to simulate mutations in a genome sequence
void mutateGenomeSequence(GenomeSequence* sequence) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        char originalBase = sequence->sequence[i];
        char newBase = mutateBase(originalBase);
        if (newBase != originalBase) {
            sequence->num_mutations++;
        }
        sequence->sequence[i] = newBase;
    }
}

// Function to print a genome sequence to the console
void printGenomeSequence(GenomeSequence sequence) {
    printf("Sequence: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", sequence.sequence[i]);
    }
    printf("\nNumber of Mutations: %d\n", sequence.num_mutations);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate an array of genome sequences
    GenomeSequence genomeSequences[NUM_GENOME_SEQUENCES];
    for (int i = 0; i < NUM_GENOME_SEQUENCES; i++) {
        genomeSequences[i] = generateGenomeSequence();
    }
    
    // Simulate mutations in each genome sequence
    for (int i = 0; i < NUM_GENOME_SEQUENCES; i++) {
        mutateGenomeSequence(&genomeSequences[i]);
    }
    
    // Print each genome sequence to the console
    for (int i = 0; i < NUM_GENOME_SEQUENCES; i++) {
        printf("Genome Sequence %d \n", i+1);
        printGenomeSequence(genomeSequences[i]);
        printf("\n");
    }
    
    return 0;
}