//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 10000

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate random genome sequence
    char genome[MAX_GENOME_LENGTH];
    int genome_length = rand() % MAX_GENOME_LENGTH;
    for (int i = 0; i < genome_length; i++) {
        int nucleotide = rand() % 4;
        if (nucleotide == 0) {
            genome[i] = 'A';
        } else if (nucleotide == 1) {
            genome[i] = 'C';
        } else if (nucleotide == 2) {
            genome[i] = 'G';
        } else {
            genome[i] = 'T';
        }
    }

    // Print the generated genome sequence
    printf("Generated genome sequence: %s \n", genome);

    // Simulate sequencing errors
    char sequenced_genome[MAX_GENOME_LENGTH];
    for (int i = 0; i < genome_length; i++) {
        int error = rand() % 100;
        if (error < 5) {
            // Substitution error
            int new_nucleotide = rand() % 4;
            while (new_nucleotide == genome[i]) {
                new_nucleotide = rand() % 4;
            }
            sequenced_genome[i] = new_nucleotide;
            printf("Substitution error at position %i: %c -> %c\n", i, genome[i], new_nucleotide);
        } else if (error < 10) {
            // Deletion error
            printf("Deletion error at position %i: %c deleted\n", i, genome[i]);
        } else {
            // No error
            sequenced_genome[i] = genome[i];
        }
    }

    // Print the sequenced genome sequence
    printf("Sequenced genome sequence: %s \n", sequenced_genome);

    return 0;
}