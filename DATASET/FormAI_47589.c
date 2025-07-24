//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000

int main() {
    char bases[] = {'A', 'C', 'G', 'T'};
    char genome[GENOME_LENGTH + 1];
    genome[GENOME_LENGTH] = '\0';

    srand(time(NULL));
    // Generate the random genome sequence
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int base_index = rand() % 4;
        genome[i] = bases[base_index];
    }

    // Output the original genome sequence
    printf("Original Genome Sequence:\n%s\n", genome);

    // Create an error rate of 0.1% by randomly substituting a base with a different one
    int error_count = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        double error_probability = (double)rand() / (double)RAND_MAX;
        if (error_probability < 0.001) {
            int base_index = (rand() % 3 + 1) % 4;  // Ensure substitution base is different
            genome[i] = bases[base_index];
            error_count++;
        }
    }

    // Output the mutated genome sequence with error count and rate
    double error_rate = (double)error_count / (double)GENOME_LENGTH * 100;
    printf("Mutated Genome Sequence:\n%s\n", genome);
    printf("Error Count: %d\nError Rate: %.4f percent\n", error_count, error_rate);

    return 0;
}