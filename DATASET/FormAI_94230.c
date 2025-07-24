//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_CHANCE 0.1

void printGenome(char *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutateGenome(char *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((float)rand() / RAND_MAX < MUTATION_CHANCE) {
            genome[i] = (char)((int)'A' + rand() % 26);
        }
    }
}

int main() {
    srand(time(NULL)); // Set random seed based on current time
    
    // Initialize genome with random values
    char genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = (char)((int)'A' + rand() % 26);
    }
    
    printf("Initial genome:\n");
    printGenome(genome);
    
    // Simulate mutations
    for (int generation = 1; generation <= 10; generation++) {
        printf("Generation %d:\n", generation);
        mutateGenome(genome);
        printGenome(genome);
    }
    
    return 0;
}