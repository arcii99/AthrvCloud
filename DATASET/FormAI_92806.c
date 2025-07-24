//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100 // defines the size of the genome
#define MUTATION_PROBABILITY 0.01 // defines the probability of mutation

int main() {
    char genome[GENOME_SIZE]; // declare an array to store the genome
    int i;

    srand(time(0)); // seed random number generator

    // initialize the genome with random nucleotides
    for (i = 0; i < GENOME_SIZE; i++) {
        switch (rand() % 4) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'T';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }

    printf("Original genome sequence: %s\n", genome);

    // introduce mutations to the genome based on the mutation probability
    for (i = 0; i < GENOME_SIZE; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_PROBABILITY) {
            switch (rand() % 3) {
                case 0: // replace the nucleotide with a random one
                    switch (rand() % 4) {
                        case 0:
                            genome[i] = 'A';
                            break;
                        case 1:
                            genome[i] = 'C';
                            break;
                        case 2:
                            genome[i] = 'T';
                            break;
                        case 3:
                            genome[i] = 'G';
                            break;
                    }
                    break;
                case 1: // delete the nucleotide
                    genome[i] = '-';
                    break;
                case 2: // insert a random nucleotide
                    switch (rand() % 4) {
                        case 0:
                            genome[i] = 'A';
                            break;
                        case 1:
                            genome[i] = 'C';
                            break;
                        case 2:
                            genome[i] = 'T';
                            break;
                        case 3:
                            genome[i] = 'G';
                            break;
                    }
                    break;
            }
        }
    }

    printf("Mutated genome sequence: %s\n", genome);

    return 0;
}