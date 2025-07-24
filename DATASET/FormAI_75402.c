//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the genome sequence
    char genome[GENOME_LENGTH];
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = 'A' + rand() % 4; // Randomly choose A, T, C, or G
    }
    
    // Print the original genome sequence
    printf("Original genome sequence:\n");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // Introduce mutations
    for (i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            switch (genome[i]) {
                case 'A':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'C';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'A';
                    break;
            }
        }
    }
    
    // Print the mutated genome sequence
    printf("Mutated genome sequence:\n");
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}