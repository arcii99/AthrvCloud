//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 50
#define MUTATION_RATE 0.05

char randomBase() {
    switch (rand() % 4) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
}

void mutate(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = randomBase();
        }
    }
}

void printGenome(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = randomBase();
    }
    printGenome(genome);

    for (int i = 0; i < 10; i++) {
        mutate(genome);
        printGenome(genome);
    }

    return 0;
}