//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

char getRandomNucleotide() {
    int randomInt = rand() % 4;
    switch (randomInt) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        default:
            return 'T';
    }
}

void generateRandomGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomNucleotide();
    }
    genome[GENOME_LENGTH] = '\0';
}

void mutateGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        double randomDouble = (double) rand() / RAND_MAX;
        if (randomDouble < MUTATION_RATE) {
            genome[i] = getRandomNucleotide();
        }
    }
}

void printGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    srand((unsigned int) time(NULL));

    char genome[GENOME_LENGTH + 1];
    generateRandomGenome(genome);
    printf("Original Genome: ");
    printGenome(genome);

    for (int generation = 1; generation <= 10; generation++) {
        mutateGenome(genome);
        printf("Generation %d:     ", generation);
        printGenome(genome);
    }

    return 0;
}