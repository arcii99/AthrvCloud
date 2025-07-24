//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEGMENT_SIZE 100 // change this to the desired segment size

int main(void) {
    // initialize random seed
    srand(time(NULL));

    // generate random DNA sequence
    char dna[] = "ATGC";
    int dna_size = 1000;
    char sequence[dna_size];
    for (int i = 0; i < dna_size; i++) {
        sequence[i] = dna[rand() % 4]; // randomly choose a base
    }

    // simulate genome sequencing
    int num_segments = dna_size / SEGMENT_SIZE;
    char segments[num_segments][SEGMENT_SIZE];
    for (int i = 0; i < num_segments; i++) {
        for (int j = 0; j < SEGMENT_SIZE; j++) {
            segments[i][j] = sequence[i * SEGMENT_SIZE + j];
        }
    }

    // output results
    printf("Original DNA sequence: %s\n\n", sequence);
    printf("Sequencing results:\n");
    for (int i = 0; i < num_segments; i++) {
        printf("Segment %d: %s\n", i+1, segments[i]);
    }

    return 0;
}