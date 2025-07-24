//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 50

char getRandomBase() {
    int r = rand() % 4;
    switch(r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

void generateRandomGenome(char genome[]) {
    for(int i=0; i<GENOME_SIZE; i++) {
        genome[i] = getRandomBase();
    }
}

void printGenome(char genome[]) {
    for(int i=0; i<GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutateGenome(char genome[], float mutationRate) {
    for(int i=0; i<GENOME_SIZE; i++) {
        float r = ((float) rand()) / RAND_MAX;
        if (r < mutationRate) {
            genome[i] = getRandomBase();
        }
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_SIZE];
    generateRandomGenome(genome);
    printf("Original Genome: ");
    printGenome(genome);
    mutateGenome(genome, 0.1);
    printf("Mutated Genome: ");
    printGenome(genome);
    return 0;
}