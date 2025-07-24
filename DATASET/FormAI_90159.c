//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LEN 150
#define MUTATION_PROB 0.1

int main(void) {
    // Initialize genome with random nucleotides
    char genome[GENOME_LEN + 1];
    srand(time(NULL));
    for (int i = 0; i < GENOME_LEN; i++) {
        int rand_nuc = rand() % 4;
        switch (rand_nuc) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }
    genome[GENOME_LEN] = '\0';

    printf("Initial genome: %s\n", genome);

    // Mutate genome
    for (int i = 0; i < GENOME_LEN; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_PROB) {
            int rand_nuc = rand() % 4;
            switch (rand_nuc) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'T';
                    break;
                case 2:
                    genome[i] = 'C';
                    break;
                case 3:
                    genome[i] = 'G';
                    break;
            }
        }
    }

    printf("Mutated genome: %s\n", genome);

    return 0;
}