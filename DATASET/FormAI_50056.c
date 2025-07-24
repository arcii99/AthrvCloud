//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100

char generateRandomNucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
    return 'A';
}

void printGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
}

int main() {
    srand(time(NULL));

    char genome1[GENOME_LENGTH];
    char genome2[GENOME_LENGTH];

    // generate random genomes
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome1[i] = generateRandomNucleotide();
        genome2[i] = generateRandomNucleotide();
    }

    printf("Original genomes:\n");
    printGenome(genome1);
    printf("\n");
    printGenome(genome2);
    printf("\n");

    // perform mutations
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int r = rand() % 100;
        if (r < 1) { // 1% chance of mutation
            genome1[i] = generateRandomNucleotide();
        }
        r = rand() % 100;
        if (r < 1) { // 1% chance of mutation
            genome2[i] = generateRandomNucleotide();
        }
    }

    printf("Mutated genomes:\n");
    printGenome(genome1);
    printf("\n");
    printGenome(genome2);
    printf("\n");

    // compare genomes
    int differences = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (genome1[i] != genome2[i]) {
            differences++;
        }
    }

    printf("Number of differences between genomes: %d\n", differences);

    return 0;
}