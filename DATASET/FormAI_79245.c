//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100

char getRandomNucleotide() {
    int randNum = rand() % 4;
    switch (randNum) {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'C';
        default: return 'G';
    }
}

char* generateRandomGenome() {
    char *genome = malloc(GENOME_LENGTH * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomNucleotide();
    }
    return genome;
}

void printGenome(char *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c",genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed random number generator with current time
    char *genome = generateRandomGenome();
    printf("Original genome:\n");
    printGenome(genome);

    // Create mutated genomes
    char *mutation1 = malloc(GENOME_LENGTH * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        mutation1[i] = genome[i];
        int shouldMutate = rand() % 5;
        if (shouldMutate == 0) {
            mutation1[i] = getRandomNucleotide();
        }
    }

    char *mutation2 = malloc(GENOME_LENGTH * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        mutation2[i] = genome[i];
        int shouldMutate = rand() % 5;
        if (shouldMutate == 0) {
            mutation2[i] = getRandomNucleotide();
        }
    }

    // Print mutated genomes
    printf("Mutated genome 1:\n");
    printGenome(mutation1);
    printf("Mutated genome 2:\n");
    printGenome(mutation2);

    free(genome);
    free(mutation1);
    free(mutation2);
    return 0;
}