//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for nucleotides
#define A 0
#define C 1
#define G 2
#define T 3

// Define the length of the genome sequence
#define GENOME_LENGTH 1000

// Function to generate random nucleotides
int random_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            // Should not reach here, but return A by default to avoid errors
            return A;
    }
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Define and initialize the genome sequence
    int genome[GENOME_LENGTH];
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }

    // Print the genome sequence
    for (int i = 0; i < GENOME_LENGTH; i++) {
        switch (genome[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
            default:
                // Should not reach here, but print A by default to avoid errors
                printf("A");
        }
    }

    // Exit successfully
    return 0;
}