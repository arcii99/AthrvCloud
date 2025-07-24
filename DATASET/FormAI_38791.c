//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 10 // Length of the DNA sequence to be generated

void printSequence(char *sequence) {
    printf("Generated sequence: %s\n", sequence);
}

void generateSequence(char *sequence) {
    srand(time(0)); // Initialize the random number generator with current time
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int random = rand() % 4; // Generate a random number between 0 and 3
        switch (random) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'T';
                break;
            case 2:
                sequence[i] = 'C';
                break;
            case 3:
                sequence[i] = 'G';
                break;
        }
    }
}

int main() {
    char sequence[SEQUENCE_LENGTH + 1]; // +1 for the null terminator
    generateSequence(sequence);
    printSequence(sequence);
    return 0;
}