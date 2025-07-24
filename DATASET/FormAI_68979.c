//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int genomeLength = 1000; // length of genome
    char nucleotideArray[4] = {'A', 'C', 'G', 'T'}; // array of possible nucleotides
    char genome[genomeLength]; // array to store generated genome

    printf("Generating genome...\n");

    for (int i = 0; i < genomeLength; i++) {
        int randomInt = rand() % 4; // generate random integer between 0-3
        char nucleotide = nucleotideArray[randomInt]; // select nucleotide based on random integer
        genome[i] = nucleotide; // add nucleotide to genome array
    }

    printf("Genome generated!\n");

    printf("Genome sequence: ");

    for (int j = 0; j < genomeLength; j++) {
        printf("%c", genome[j]); // print out genome sequence
    }

    printf("\n");

    return 0;
}