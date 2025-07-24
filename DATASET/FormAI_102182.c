//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASES "AGCT"

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int genome_length = 1000;
    char genome[genome_length + 1]; // +1 for null terminator
    for(int i = 0; i < genome_length; i++) {
        genome[i] = BASES[rand() % 4]; // Randomly choose one of the four nucleotide bases
    }
    genome[genome_length] = '\0'; // Add null terminator to end of string
    printf("Original genome: %s\n", genome);

    // Simulate sequencing errors
    int num_errors = genome_length / 10; // 10% error rate
    for(int i = 0; i < num_errors; i++) {
        int error_index = rand() % genome_length;
        genome[error_index] = BASES[rand() % 3]; // Choose a different base from the original
    }
    printf("Sequenced genome: %s\n", genome);

    return 0;
}