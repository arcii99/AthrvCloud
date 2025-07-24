//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

char generateRandomBase() {
    char bases[] = {'A', 'C', 'G', 'T'};
    int randomIndex = rand() % 4;
    return bases[randomIndex];
}

void mutate(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float randomNum = (float)rand() / RAND_MAX;
        if (randomNum < MUTATION_RATE) {
            genome[i] = generateRandomBase();
        }
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    
    // Generate random genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = generateRandomBase();
    }
    
    printf("Original Genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    // Mutate genome
    mutate(genome);
    
    printf("\n\nMutated Genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    return 0;
}