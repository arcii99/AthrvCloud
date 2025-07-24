//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random nucleotide bases
char rand_base() {
    int num = rand() % 4;
    char base;

    switch(num) {
        case 0:
            base = 'A';
            break;
        case 1:
            base = 'C';
            break;
        case 2:
            base = 'G';
            break;
        case 3:
            base = 'T';
            break;
    }

    return base;
}

int main() {
    // set random seed
    srand(time(0));

    // create a genome sequence of length 1000
    char genome[1000];
    for (int i = 0; i < 1000; i++) {
        genome[i] = rand_base();
    }

    // print out the genome sequence
    printf("Genome Sequence: ");
    for (int i = 0; i < 1000; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // generate random start and end indices for the subsequence
    int start = rand() % 900;
    int end = start + (rand() % (100 - (start % 100)));

    // create a subsequence based on the start and end indices
    char subsequence[end - start];
    for (int i = start; i < end; i++) {
        subsequence[i - start] = genome[i];
    }

    // print out the subsequence
    printf("Subsequence (from base %d to base %d): ", start, end);
    for (int i = 0; i < end - start; i++) {
        printf("%c", subsequence[i]);
    }
    printf("\n");

    return 0;
}