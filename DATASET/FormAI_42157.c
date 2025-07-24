//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 10000

int main() {
    srand(time(NULL)); // Seed the random number generator

    char genome[GENOME_LENGTH + 1]; // +1 for NULL terminator
    memset(genome, 'A', sizeof(genome)); // Initialize genome with all A's
    printf("Initialized genome: %s\n\n", genome);

    // Generate mutations
    int num_mutations = rand() % 100 + 1; // Random number between 1 and 100
    for (int i = 0; i < num_mutations; i++) {
        int position = rand() % GENOME_LENGTH; // Random position in the genome
        char mutation;
        do {
            mutation = rand() % 4; // Random nucleotide (A, C, T, or G)
        } while (mutation == genome[position]); // Ensure mutation is different from original nucleotide
        genome[position] = mutation;
    }

    printf("Mutated genome: %s\n", genome);

    return 0;
}