//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100 // The length of our simulated DNA sequence

// Function to randomly generate a DNA sequence
void generateSequence(char sequence[]) {
    int i;
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    // Seed the random number generator with the current time
    srand(time(NULL)); 
    
    // Randomly generate a nucleotide for each position in the sequence
    for(i=0; i<SEQUENCE_LENGTH; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
}

// Function to print out a DNA sequence
void printSequence(char sequence[]) {
    int i;
    for(i=0; i<SEQUENCE_LENGTH; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main(void) {
    char sequence[SEQUENCE_LENGTH];
    // Generate a random DNA sequence
    generateSequence(sequence);
    printf("Generated DNA sequence: ");
    // Print out the generated sequence
    printSequence(sequence);
    return 0;
}