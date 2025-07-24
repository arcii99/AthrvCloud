//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of the genome string
#define MAX_LENGTH 1000

// Define the number of nucleotide bases
#define NUM_BASES 4

// Define the nucleotide base symbols
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Function to generate a random nucleotide base
char randomBase() {
    int randInt = rand() % NUM_BASES;
    switch (randInt) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
    }
}

// Function to generate a random genome string
void generateGenomeString(char* genomeString, int length) {
    int i;
    for (i = 0; i < length; i++) {
        genomeString[i] = randomBase();
    }
    genomeString[length] = '\0';
}

// Function to calculate the GC content of a genome string
float calculateGCContent(char* genomeString) {
    int i;
    float gcCount = 0.0;
    for (i = 0; i < strlen(genomeString); i++) {
        if (genomeString[i] == C || genomeString[i] == G) {
            gcCount++;
        }
    }
    return gcCount / strlen(genomeString);
}

// Main function
int main() {
    char genomeString[MAX_LENGTH];
    int length = 500;
    srand(time(NULL));
    generateGenomeString(genomeString, length);
    printf("Random genome string of length %d: %s\n", length, genomeString);
    printf("GC content of genome string: %f\n", calculateGCContent(genomeString));
    return 0;
}