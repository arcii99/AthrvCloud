//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10
#define MUTATION_RATE 0.05

void generateRandomGenome(int genome[]) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // nucleotide: 0=A, 1=C, 2=G, 3=T
    }
}

void printGenome(int genome[]) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n");
}

void mutateGenome(int genome[]) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = rand() % 4; // randomly mutate to one of four nucleotides
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int genome1[GENOME_LENGTH];
    int genome2[GENOME_LENGTH];

    generateRandomGenome(genome1);
    generateRandomGenome(genome2);

    printf("Genome 1: ");
    printGenome(genome1);

    printf("Genome 2: ");
    printGenome(genome2);

    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        if (rand() % 2 == 0) {
            genome1[i] = genome2[i]; // randomly choose to inherit nucleotide from genome2
        }
    }

    printf("Offspring: ");
    printGenome(genome1);

    mutateGenome(genome1);

    printf("Mutated offspring: ");
    printGenome(genome1);

    return 0;
}