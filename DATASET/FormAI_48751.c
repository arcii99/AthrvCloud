//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000 // Length of the genome sequence
#define NUCLEOTIDE_COUNT 4 // Total number of nucleotides (A,T,C,G)
#define MUTATION_RATE 0.01 // Mutation rate, as a fraction of genome length

char nucleotides[] = {'A', 'T', 'C', 'G'}; // Array of nucleotides

// Function to generate a random nucleotide
char generateRandomNucleotide() {
    int index = rand() % NUCLEOTIDE_COUNT;
    return nucleotides[index];
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char genome[GENOME_LENGTH]; // Array to store the genome sequence
    int i, j, mutations;

    // Generate the initial genome sequence
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = generateRandomNucleotide();
    }

    // Simulate mutations in the genome sequence
    mutations = (int)(MUTATION_RATE * GENOME_LENGTH);
    for (i = 0; i < mutations; i++) {
        j = rand() % GENOME_LENGTH; // Select a random index to mutate
        genome[j] = generateRandomNucleotide(); // Replace the nucleotide at the random index
    }

    // Print the mutated genome sequence
    printf("The mutated genome sequence is:\n");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }

    return 0;
}