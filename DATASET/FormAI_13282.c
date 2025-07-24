//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10 // length of the genome sequence to be simulated
#define MUTATION_RATE 0.1 // percentage of base pairs that will mutate

// function to randomly generate a base pair (A, C, G, or T)
char randomBasePair() {
    int randNum = rand() % 4;
    switch(randNum) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'X'; // in case of error, return X
    }
}

// function to simulate genetic mutation by flipping a random base pair
char mutateBasePair(char basePair) {
    if((double)rand() / RAND_MAX < MUTATION_RATE) { // check if mutation will occur
        switch(basePair) {
            case 'A':
                return 'T';
            case 'C':
                return 'G';
            case 'G':
                return 'C';
            case 'T':
                return 'A';
            default:
                return basePair; // in case of error, return the original base pair
        }
    }
    return basePair; // if no mutation occurs, return the original base pair
}

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // create genome sequence array and populate it with random base pairs
    char genome[GENOME_LENGTH];
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = randomBasePair();
    }
    
    // print original genome sequence
    printf("Original Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    // mutate the genome sequence
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = mutateBasePair(genome[i]);
    }
    
    // print mutated genome sequence
    printf("\n\nMutated Genome Sequence: ");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    
    return 0;
}