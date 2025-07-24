//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100 // Size of the Genome Sequence
#define MUTATION_RATE 0.01 // Mutation rate

void randomlyPopulate(int genomeSequence[]) {
    // Populates the genome sequence with random values between 0 to 3
    for (int i = 0; i < GENOME_SIZE; i++) {
        genomeSequence[i] = rand() % 4;
    }
}

void mutate(int genomeSequence[]) {
    // Mutates the genome sequence by randomly selecting a gene and replacing it with another random value
    for (int i = 0; i < GENOME_SIZE; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            genomeSequence[i] = rand() % 4;
        }
    }
}

void printGenomeSequence(int genomeSequence[]) {
    // Prints the genome sequence
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%d ", genomeSequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int genomeSequence[GENOME_SIZE];
    randomlyPopulate(genomeSequence);
    printGenomeSequence(genomeSequence);

    mutate(genomeSequence);
    printGenomeSequence(genomeSequence);

    return 0;
}