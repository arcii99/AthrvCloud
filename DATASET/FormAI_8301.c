//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time

    // generate random DNA sequence
    char dna[100] = "";
    for (int i = 0; i < 100; i++) {
        int randNum = rand() % 4; // generate random number from 0 to 3
        if (randNum == 0) {
            dna[i] = 'A';
        } else if (randNum == 1) {
            dna[i] = 'C';
        } else if (randNum == 2) {
            dna[i] = 'G';
        } else {
            dna[i] = 'T';
        }
    }

    printf("Original DNA sequence: %s\n", dna);

    // simulate genome sequencing errors
    int numErrors = rand() % 10;
    for (int i = 0; i < numErrors; i++) {
        int errorIndex = rand() % 100; // generate random index to introduce error
        int errorType = rand() % 2; // generate random error type (1 for substitution, 2 for deletion)
        if (errorType == 1) {
            int randNum = rand() % 3;
            if (randNum == 0) {
                dna[errorIndex] = 'C';
            } else if (randNum == 1) {
                dna[errorIndex] = 'G';
            } else {
                dna[errorIndex] = 'T';
            }
        } else {
            for (int j = errorIndex; j < 99; j++) {
                dna[j] = dna[j+1];
            }
        }
    }

    printf("Sequence after errors: %s\n", dna);

    // simulate genome assembly
    int numContigs = rand() % 5 + 1; // generate random number of contigs between 1 and 5
    char* contigs[5];
    for (int i = 0; i < numContigs; i++) {
        int contigLength = rand() % 30 + 10; // generate random contig length between 10 and 39
        contigs[i] = (char*) malloc(contigLength * sizeof(char)); // allocate memory for contig
        for (int j = 0; j < contigLength; j++) {
            contigs[i][j] = dna[i*30+j]; // split dna into contigs
        }
    }

    printf("Contigs: ");
    for (int i = 0; i < numContigs; i++) {
        printf("%s ", contigs[i]);
        free(contigs[i]); // free memory allocated for contig
    }
    printf("\n");

    return 0;
}