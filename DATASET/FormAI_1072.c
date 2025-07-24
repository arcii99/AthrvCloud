//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 20

char getRandomBase() {
    char bases[4] = {'A', 'C', 'G', 'T'};
    int index = rand() % 4;
    return bases[index];
}

void generateGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = getRandomBase();
    }
}

void printGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    generateGenome(genome);
    printf("Original genome: ");
    printGenome(genome);
    printf("\n");

    char mutatedGenome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        mutatedGenome[i] = genome[i];
    }

    int mutationIndex = rand() % GENOME_LENGTH;
    char mutatedBase = getRandomBase();
    mutatedGenome[mutationIndex] = mutatedBase;

    printf("Mutated genome: ");
    printGenome(mutatedGenome);
    printf("\n");

    return 0;
}