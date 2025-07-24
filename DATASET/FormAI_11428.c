//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

int main() {
    char genome[GENOME_LENGTH];
    srand(time(NULL));
    
    // Generate random genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4;
        switch (genome[i]) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
    
    // Display original genome
    printf("Original Genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    // Mutate genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = rand() % 4;
            switch (genome[i]) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'C';
                    break;
                case 2:
                    genome[i] = 'G';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
            }
        }
    }
    
    // Display mutated genome
    printf("\nMutated Genome: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    return 0;
}