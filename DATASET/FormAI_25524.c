//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random nucleotide
char genNucleotide() {
    int r = rand() % 4;
    switch(r) {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'G';
        default: return '\0';
    }
}

int main() {
    srand(time(0));
    // Length of the DNA sequence
    int len = 1000;
    // Allocate memory for the DNA sequence
    char* seq = (char*)malloc(len*sizeof(char));
    // Generate the sequence
    for(int i=0; i<len; i++) {
        *(seq+i) = genNucleotide();
    }
    // Print the sequence
    printf("DNA Sequence:\n");
    for(int i=0; i<len; i++) {
        printf("%c", *(seq+i));
    }
    printf("\n");
    // Free the memory
    free(seq);

    return 0;
}