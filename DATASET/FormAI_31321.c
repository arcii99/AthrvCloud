//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DNA_LENGTH 50 // Length of the DNA sequence to be generated
#define MUTATION_RATE 0.1 // Chance of a mutation in the DNA sequence

char generate_base() {
    /* Generate a random base from A, C, G, or T */
    int base = rand() % 4;
    switch (base) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'A'; // Return 'A' by default (this should never happen)
    }
}

char* generate_dna_sequence() {
    /* Generate a random DNA sequence */
    char* dna_sequence = malloc(DNA_LENGTH + 1); // Allocate memory (don't forget the null terminator)
    srand(time(NULL)); // Seed the random number generator with the current time (not the best way to do it, but it's good enough for this example)
    for (int i = 0; i < DNA_LENGTH; i++) {
        dna_sequence[i] = generate_base(); // Generate a random base
        if ((double)rand() / RAND_MAX <= MUTATION_RATE) {
            dna_sequence[i] = generate_base(); // Mutate the base with a certain probability (MUTATION_RATE)
        }
    }
    dna_sequence[DNA_LENGTH] = '\0'; // Add the null terminator
    return dna_sequence;
}

int main() {
    char* dna_sequence = generate_dna_sequence(); // Generate a random DNA sequence
    printf("DNA sequence: %s\n", dna_sequence); // Print the DNA sequence
    free(dna_sequence); // Free the memory allocated for the DNA sequence
    return 0;
}