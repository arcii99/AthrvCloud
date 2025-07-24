//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 1000000
#define MAX_LENGTH 10000000
#define MIN_BASES 1
#define MAX_BASES 4

/*
This program generates a simulated C genome sequence with a random length and base pairs.
*/

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int sequence_length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH; // Generate a random sequence length
    char *sequence = malloc(sequence_length * sizeof(char)); // Allocate memory for the sequence

    // Generate the random sequence
    for (int i = 0; i < sequence_length; i++) {
        int base = rand() % (MAX_BASES - MIN_BASES + 1) + MIN_BASES; // Generate a random base pair
        switch (base) {
            case 1:
                sequence[i] = 'A';
                break;
            case 2:
                sequence[i] = 'C';
                break;
            case 3:
                sequence[i] = 'G';
                break;
            case 4:
                sequence[i] = 'T';
                break;
        }
    }

    // Print the sequence
    for (int i = 0; i < sequence_length; i++) {
        printf("%c", sequence[i]);
    }

    free(sequence); // Free the memory allocated for the sequence

    return 0;
}