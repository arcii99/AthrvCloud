//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000 // define genome size
#define MUTATION_RATE 0.01 // define mutation rate

// Function to randomly generate nucleotides
char generateNucleotide() {
    int randomNum = rand() % 4; // get random number from 0-3
    
    // assign nucleotide based on random number
    if (randomNum == 0) {
        return 'A';
    } else if (randomNum == 1) {
        return 'C';
    } else if (randomNum == 2) {
        return 'G';
    } else {
        return 'T';
    }
}

// Function to randomly mutate a nucleotide
void mutateNucleotide(char *nucleotide) {
    double randomNum = (double)rand() / RAND_MAX; // get random float from 0-1
    
    // check if mutation should occur
    if (randomNum < MUTATION_RATE) {
        *nucleotide = generateNucleotide();
    }
}

int main() {
    char genome[GENOME_SIZE]; // initialize genome array
    int i;
    
    // initialize genome with random nucleotides
    srand(time(NULL)); // seed random number generator
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = generateNucleotide();
    }
    
    // simulate mutations on genome
    for (i = 0; i < GENOME_SIZE; i++) {
        mutateNucleotide(&genome[i]);
    }
    
    // print mutated genome
    for (i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    
    return 0;
}