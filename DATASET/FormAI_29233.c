//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Seed random generator with current time

    // Create a random sequence of A, C, G, T nucleotides
    char sequence[50];
    for (int i = 0; i < 50; i++) {
        int random_num = rand() % 4;  // Generate random number between 0 and 3

        // Assign each number to a nucleotide
        switch (random_num) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }

    // Print the sequence
    for (int i = 0; i < 50; i++) {
        printf("%c ", sequence[i]);
    }
    printf("\n");

    // Simulate sequencing error where a random nucleotide is replaced with a different one
    int error_index = rand() % 50; // Generate random index to introduce error
    int error_num = rand() % 3;  // Generate random number between 0 and 2
    
    // Assign each number to a nucleotide (excluding the original nucleotide)
    char error_nucleotide;
    switch (sequence[error_index]) {
        case 'A':
            if (error_num == 0) error_nucleotide = 'C';
            else error_nucleotide = 'G';
            break;
        case 'C':
            if (error_num == 0) error_nucleotide = 'A';
            else error_nucleotide = 'G';
            break;
        case 'G':
            if (error_num == 0) error_nucleotide = 'A';
            else error_nucleotide = 'C';
            break;
        case 'T':
            if (error_num == 0) error_nucleotide = 'A';
            else error_nucleotide = 'C';
            break;
    }

    // Replace the nucleotide at the error index with the new nucleotide
    sequence[error_index] = error_nucleotide;

    // Print the new sequence with error
    printf("Sequencing Error at index %d: %c was replaced with %c\n", error_index, sequence[error_index], error_nucleotide);
    for (int i = 0; i < 50; i++) {
        printf("%c ", sequence[i]);
    }
    printf("\n");

    return 0;
}