//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100

char randomNucleotide() {
    int randNum = rand() % 4;
    switch (randNum) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'A';
    }
}

void generateGenome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = randomNucleotide();
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    char genome1[GENOME_LENGTH + 1]; // Genome 1 for comparison
    char genome2[GENOME_LENGTH + 1]; // Genome 2 for comparison

    generateGenome(genome1);
    generateGenome(genome2);

    printf("Genome 1:\n%s\n\n", genome1);
    printf("Genome 2:\n%s\n\n", genome2);

    int differences = 0;
    int totalNucleotidesCompared = 0;

    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (genome1[i] != genome2[i]) {
            differences++;
        }
        totalNucleotidesCompared++;
    }

    printf("Number of nucleotide differences: %d\n", differences);
    printf("Sequence similarity: %.2f%%\n", (1 - ((float)differences / totalNucleotidesCompared)) * 100);

    return 0;
}