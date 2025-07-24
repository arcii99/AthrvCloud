//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // create array with DNA base pairs
    char dna[] = {'A', 'T', 'C', 'G'};

    // generate random DNA sequence
    char sequence[1000];
    int i;
    for (i = 0; i < 1000; i++) {
        int rnd = rand() % 4; // random int between 0-3
        sequence[i] = dna[rnd]; // add base pair to sequence
    }

    // print DNA sequence
    printf("DNA sequence: ");
    for (i = 0; i < 1000; i++) {
        printf("%c", sequence[i]);
        if ((i+1) % 80 == 0) printf("\n"); // add line break every 80 characters
    }

    // create array with RNA base pairs
    char rna[] = {'A', 'U', 'C', 'G'};

    // transcribe DNA to RNA
    char transcript[1000];
    for (i = 0; i < 1000; i++) {
        if (sequence[i] == 'T') transcript[i] = 'U';
        else transcript[i] = sequence[i];
    }

    // print RNA sequence
    printf("\nRNA sequence: ");
    for (i = 0; i < 1000; i++) {
        printf("%c", transcript[i]);
        if ((i+1) % 80 == 0) printf("\n"); // add line break every 80 characters
    }

    return 0;
}