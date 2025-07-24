//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BASES 10000 // maximum length of genome sequence
#define NUM_BASES 4     // number of possible nucleotide bases

typedef struct {
    char bases[MAX_BASES];
    int length;
} GenomeSequence;

void generateSequence(GenomeSequence *sequence) {
    int i;
    srand(time(NULL));
    sequence->length = rand() % MAX_BASES + 1;
    for (i = 0; i < sequence->length; i++) {
        switch (rand() % NUM_BASES) {
            case 0:
                sequence->bases[i] = 'A';
                break;
            case 1:
                sequence->bases[i] = 'C';
                break;
            case 2:
                sequence->bases[i] = 'G';
                break;
            case 3:
                sequence->bases[i] = 'T';
                break;
        }
    }
    sequence->bases[sequence->length] = '\0';
}

void printSequence(GenomeSequence sequence) {
    printf("Sequence length: %d\n", sequence.length);
    printf("Sequence: %s\n", sequence.bases);
}

int main() {
    GenomeSequence sequence;
    generateSequence(&sequence);
    printSequence(sequence);
    return 0;
}