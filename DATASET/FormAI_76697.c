//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000000 // Define the length of the genome sequence
#define NUCLEOTIDES "ACGT"      // Define the four nucleotides

int main() {
    char genome_sequence[SEQUENCE_LENGTH];   // Array to hold the genome sequence
    int i, j, random;

    srand(time(NULL));  // Seed random number generator with current time

    // Generate random genome sequence
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        random = rand() % 4;    // Generate random number between 0 and 3
        genome_sequence[i] = NUCLEOTIDES[random]; // Assign a random nucleotide to sequence
    }

    // Print out the genome sequence in fasta format
    printf("> Genome Sequence\n");
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", genome_sequence[i]);   // Print out the nucleotide
        if ((i + 1) % 60 == 0) {    // Add a line break after every 60 nucleotides
            printf("\n");
        }
    }
    printf("\n");

    // Perform genome analysis
    int count_A = 0, count_C = 0, count_G = 0, count_T = 0;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        switch (genome_sequence[i]) {
            case 'A':
                count_A++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
            case 'T':
                count_T++;
                break;
            default:
                printf("Invalid nucleotide found: %c\n", genome_sequence[i]);
        }
    }

    // Print out genome analysis
    printf("Genome Analysis Results:\n");
    printf("Number of A's: %d\n", count_A);
    printf("Number of C's: %d\n", count_C);
    printf("Number of G's: %d\n", count_G);
    printf("Number of T's: %d\n", count_T);

    // Perform genome search
    char search_pattern[4] = "ACGT";
    int search_count = 0;
    printf("Searching for pattern: %s\n", search_pattern);
    for (i = 0; i < SEQUENCE_LENGTH - 3; i++) {
        for (j = 0; j < 4; j++) {
            if (genome_sequence[i+j] != search_pattern[j]) {
                break;
            }
        }
        if (j == 4) {   // Pattern found
            search_count++;
        }
    }
    printf("Number of times pattern found: %d\n", search_count);

    return 0;
}