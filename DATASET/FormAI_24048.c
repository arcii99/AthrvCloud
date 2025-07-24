//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100
#define MUTATION_RATE 0.01

char BASES[] = {'A', 'C', 'G', 'T'};

void mutate(char *genome);

int main(void) {
    srand(time(NULL));
    char genome[GENOME_SIZE];
    int i;

    // Generate random genome
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = BASES[rand() % 4];
    }

    printf("Original Genome: %s\n", genome);

    // Mutate genome
    mutate(genome);

    printf("Mutated Genome: %s\n", genome);

    return 0;
}

void mutate(char *genome) {
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        float r = (float)rand() / RAND_MAX;
        if (r < MUTATION_RATE) {
            genome[i] = BASES[rand() % 4];
        }
    }
}