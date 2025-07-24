//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // Set genome length

int main() {
    char genome[GENOME_LENGTH]; // Initialize an empty genome sequence
    srand(time(NULL)); // Seed the random number generator
    
    // Fill the genome sequence with randomly generated nucleotides
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int randomNum = rand() % 4;
        if (randomNum == 0) {
            genome[i] = 'A';
        } else if (randomNum == 1) {
            genome[i] = 'C';
        } else if (randomNum == 2) {
            genome[i] = 'G';
        } else {
            genome[i] = 'T';
        }
    }
    
    // Print the original genome sequence
    printf("Original Genome Sequence: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // Simulate a mutation in the genome sequence
    int mutatePos = rand() % GENOME_LENGTH;
    int mutateType = rand() % 3;
    if (mutateType == 0) {
        genome[mutatePos] = 'A';
    } else if (mutateType == 1) {
        genome[mutatePos] = 'C';
    } else if (mutateType == 2) {
        genome[mutatePos] = 'G';
    } else {
        genome[mutatePos] = 'T';
    }
    
    // Print the mutated genome sequence
    printf("Mutated Genome Sequence: ");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}