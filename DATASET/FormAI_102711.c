//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000

int main() {
    srand(time(NULL)); // Seed random number generator

    uint8_t genome[GENOME_LENGTH]; // Create an array to store genome sequence

    // Generate genome sequence randomly
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // Each element can be one of four nucleotides - A, C, G, or T
    }

    // Print the genome sequence
    printf("Genome sequence:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (i % 10 == 0 && i > 0) {
            printf("\n");
        }
        printf("%c ", genome[i] == 0 ? 'A' : genome[i] == 1 ? 'C' : genome[i] == 2 ? 'G' : 'T');
    }
    printf("\n");

    // Generate a fragment sequence randomly
    int fragment_start = rand() % GENOME_LENGTH;
    int fragment_length = rand() % (GENOME_LENGTH - fragment_start) + 1;
    printf("Fragment start: %d\n", fragment_start);
    printf("Fragment length: %d\n", fragment_length);

    uint8_t fragment[fragment_length];
    for (int i = 0; i < fragment_length; i++) {
        fragment[i] = genome[fragment_start + i];
    }

    // Print the fragment sequence
    printf("Fragment sequence:\n");
    for (int i = 0; i < fragment_length; i++) {
        if (i % 10 == 0 && i > 0) {
            printf("\n");
        }
        printf("%c ", fragment[i] == 0 ? 'A' : fragment[i] == 1 ? 'C' : fragment[i] == 2 ? 'G' : 'T');
    }
    printf("\n");

    return 0;
}