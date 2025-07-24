//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000

char randomBase() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
    return 'N';
}

void generateRandomGenome(char genome[]) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = randomBase();
    }
}

void mutateGenome(char genome[], float mutationRate) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        float r = (float) rand() / (float) RAND_MAX;
        if (r < mutationRate) {
            genome[i] = randomBase();
        }
    }
}

void printGenome(char genome[]) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        putchar(genome[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char genome[GENOME_SIZE];
    float mutationRate = 0.01;
    
    generateRandomGenome(genome);
    printGenome(genome);
    
    for (int i = 0; i < 10; i++) {
        mutateGenome(genome, mutationRate);
        printGenome(genome);
    }
    
    return 0;
}