//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100 // Genome length of 100 base pairs
#define MUTATION_RATE 0.1 // 10% chance of mutation

// Function to randomly generate a DNA base (A, T, C, G)
char random_base() {
    int random_num = rand() % 4;
    char base;
    if (random_num == 0) base = 'A';
    else if (random_num == 1) base = 'T';
    else if (random_num == 2) base = 'C';
    else base = 'G';
    return base;
}

// Function to randomly mutate a base with given mutation rate
char mutate_base(char base) {
    if ((double)rand() / RAND_MAX <= MUTATION_RATE) {
        base = random_base();
    }
    return base;
}

// Function to print the genome sequence
void print_genome(char genome[]) {
    printf("Genome sequence: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Initialize genome array with random DNA bases
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = random_base();
    }

    // Print the original genome sequence
    print_genome(genome);

    // Simulate genome sequencing
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = mutate_base(genome[i]);
    }

    // Print the sequenced genome
    print_genome(genome);

    return 0;
}