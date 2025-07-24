//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the length of the genome sequence
#define GENOME_LENGTH 100

// Define the range of allowed nucleotides
#define NUCLEOTIDES "ACGT"

// Function to generate a random nucleotide
char gen_random_nucleotide() {
    int random_index = rand() % 4;
    return NUCLEOTIDES[random_index];
}

int main() {
    srand(time(NULL));

    // Allocate memory for the genome sequence
    char* genome_sequence = malloc(GENOME_LENGTH * sizeof(char));

    // Generate the genome sequence by randomly selecting nucleotides
    for (int i = 0; i < GENOME_LENGTH; ++i) {
        genome_sequence[i] = gen_random_nucleotide();
    }

    // Print out the genome sequence
    printf("Generated Genome Sequence: ");
    for (int i = 0; i < GENOME_LENGTH; ++i) {
        printf("%c", genome_sequence[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(genome_sequence);

    return 0;
}