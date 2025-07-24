//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // Number of nucleotides in genome sequence
#define MUTATION_CHANCE 0.01 // Probability of a mutation occurring

// Function to generate random nucleotides
char generateNucleotide() {
    int rnd = rand() % 4; // Randomly generate a number from 0-3
    char nucleotide;
    switch (rnd) {
        case 0:
            nucleotide = 'A';
            break;
        case 1:
            nucleotide = 'C';
            break;
        case 2:
            nucleotide = 'G';
            break;
        case 3:
            nucleotide = 'T';
            break;
    }
    return nucleotide;
}

// Function to generate a random genome sequence
void generateGenomeSequence(char *genome) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        *(genome + i) = generateNucleotide();
    }
}

// Function to mutate a nucleotide with a certain probability
void mutateNucleotide(char *nucleotide) {
    float rnd = (float) rand() / RAND_MAX; // Randomly generate a number from 0-1
    if (rnd < MUTATION_CHANCE) { // If probability threshold is met
        *nucleotide = generateNucleotide(); // Mutate the nucleotide
    }
}

// Function to simulate genome sequencing by generating a sample and comparing it to the original sequence
void simulateGenomeSequencing(char *genome) {
    char sample[GENOME_LENGTH]; // Generate a sample genome sequence
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        sample[i] = *(genome + i);
        mutateNucleotide(&sample[i]); // Mutate each nucleotide in the sample
    }
    int numErrors = 0; // Counter for number of errors found
    for (i = 0; i < GENOME_LENGTH; i++) {
        if (*(genome + i) != sample[i]) { // If there is a difference between the sample sequence and the original sequence
            numErrors++; // Increment the error counter
        }
    }
    printf("Number of errors found: %d\n", numErrors);
}

int main() {
    srand(time(NULL)); // Seed for random number generation based on current time
    char genome[GENOME_LENGTH];
    generateGenomeSequence(genome);
    simulateGenomeSequencing(genome); // Simulate genome sequencing by generating a sample and comparing it to the original sequence
    return 0;
}