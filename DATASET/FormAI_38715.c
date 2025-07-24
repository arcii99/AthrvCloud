//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // define genome length for simulation
#define MUTATION_PROBABILITY 0.005 // define mutation probability

int main(void) {
    // initialize random seed
    srand(time(NULL));

    // create empty genome string
    char genome[GENOME_LENGTH+1];
    genome[GENOME_LENGTH] = '\0';

    // fill genome string with random nucleotides (A, C, G, or T)
    for (int i=0; i<GENOME_LENGTH; i++) {
        switch (rand() % 4) {
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

    // print the original genome
    printf("Original Genome: %s\n", genome);

    // create a copy of the genome for mutation
    char mutated_genome[GENOME_LENGTH+1];
    mutated_genome[GENOME_LENGTH] = '\0';
    for (int i=0; i<GENOME_LENGTH; i++) {
        mutated_genome[i] = genome[i];
    }

    // randomly mutate nucleotides with a given probability
    for (int i=0; i<GENOME_LENGTH; i++) {
        if (rand()/(double)RAND_MAX <= MUTATION_PROBABILITY) {
            switch (rand() % 3) {
                case 0:
                    mutated_genome[i] = 'A';
                    break;
                case 1:
                    mutated_genome[i] = 'C';
                    break;
                case 2:
                    mutated_genome[i] = 'G';
                    break;
                case 3:
                    mutated_genome[i] = 'T';
                    break;
            }
        }
    }

    // print the mutated genome
    printf("Mutated Genome: %s\n", mutated_genome);

    // exit program
    return 0;
}