//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define NUM_CHROMOSOMES 23

int main(void) {
    srand(time(NULL));

    // Initialize the genome
    int genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // Randomly generate a nucleotide
    }

    // Initialize the chromosomes
    int chromosomes[NUM_CHROMOSOMES][GENOME_LENGTH/NUM_CHROMOSOMES];
    int k = 0;
    for (int i = 0; i < NUM_CHROMOSOMES; i++) {
        for (int j = 0; j < GENOME_LENGTH/NUM_CHROMOSOMES; j++) {
            chromosomes[i][j] = genome[k++];
        }
    }

    // Print the genome
    printf("Genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");

    // Print the chromosomes
    printf("Chromosomes:\n");
    for (int i = 0; i < NUM_CHROMOSOMES; i++) {
        printf("Chromosome %d: ", i+1);
        for (int j = 0; j < GENOME_LENGTH/NUM_CHROMOSOMES; j++) {
            printf("%d ", chromosomes[i][j]);
        }
        printf("\n");
    }

    return 0;
}