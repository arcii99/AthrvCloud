//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BASES 4
#define LENGTH 100

int main() {
    // set up random number generator
    srand(time(NULL));

    // initialize array to hold bases (A, C, G, T)
    char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};

    // initialize array to hold genome sequence
    char sequence[LENGTH];

    // populate sequence array with random bases
    for (int i = 0; i < LENGTH; i++) {
        int index = rand() % NUM_BASES;
        sequence[i] = bases[index];
    }

    // output the genome sequence
    printf("Genome Sequence: ");
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");

    return 0;
}