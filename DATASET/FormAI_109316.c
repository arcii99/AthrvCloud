//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LEN 1000
#define MUTATION_RATE 0.01

int main() {

    char genome[GENOME_LEN];
    int i;
    float mutation_probability;

    // Seed random number generator
    srand(time(NULL));
    
    // Initiate genome with random nucleotides
    for (i = 0; i < GENOME_LEN; i++) {
        int rand_num = rand() % 4;
        switch (rand_num) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }

    printf("Original Genome: %s\n", genome);

    // Simulate mutations
    for (i = 0; i < GENOME_LEN; i++) {
        // Generate mutation probability for this nucleotide
        mutation_probability = (float)rand() / RAND_MAX;
        if (mutation_probability < MUTATION_RATE) {
            // Choose random nucleotide for mutation
            int rand_num = rand() % 4;
            char new_nucleotide;
            switch (rand_num) {
                case 0:
                    new_nucleotide = 'A';
                    break;
                case 1:
                    new_nucleotide = 'C';
                    break;
                case 2:
                    new_nucleotide = 'G';
                    break;
                case 3:
                    new_nucleotide = 'T';
                    break;
            }
            // Replace original nucleotide with mutated nucleotide
            genome[i] = new_nucleotide;
        }
    }

    printf("Mutated Genome: %s\n", genome);

    return 0;
}