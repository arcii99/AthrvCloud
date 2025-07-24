//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUCLEOTIDES "ACGT"

int main() {
    char sequence[SEQUENCE_LENGTH + 1];
    int i;

    // Seed random number generator with current time
    srand(time(NULL));

    // Generate random genome sequence
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }
    sequence[SEQUENCE_LENGTH] = '\0';

    // Print out the generated sequence
    printf("Generated sequence:\n%s\n", sequence);

    // Count the number of times each nucleotide occurs in the sequence
    int countA = 0, countC = 0, countG = 0, countT = 0;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        switch(sequence[i]) {
            case 'A':
                countA++;
                break;
            case 'C':
                countC++;
                break;
            case 'G':
                countG++;
                break;
            case 'T':
                countT++;
                break;
            default:
                break;
        }
    }

    // Print out the nucleotide counts
    printf("\nNucleotide counts:\n");
    printf("A: %d\n", countA);
    printf("C: %d\n", countC);
    printf("G: %d\n", countG);
    printf("T: %d\n", countT);

    return 0;
}