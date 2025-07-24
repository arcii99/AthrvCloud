//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10

int main() {
    int genome[GENOME_SIZE];
    int i;

    srand(time(NULL)); // Seed the random number generator

    // Generate random genome sequence
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4; // Randomly assign A, C, G, or T
    }

    // Print the genome
    printf("Genome sequence: ");
    for (i = 0; i < GENOME_SIZE; i++) {
        switch (genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n");

    return 0;
}