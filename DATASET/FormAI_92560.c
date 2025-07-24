//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 10 // The length of the DNA sequence to be simulated
#define DNA_BASES "ACGT" // The possible bases of the DNA sequence

// Recursive function that generates the DNA sequence
void generateSequence(char *sequence, int index) {
    if (index == DNA_LENGTH) { // Base case: the entire sequence has been generated
        return;
    }
    // Choose a random base and add it to the sequence
    int randomIndex = rand() % 4;
    sequence[index] = DNA_BASES[randomIndex];
    printf("%c", sequence[index]);
    // Call the function again to generate the next base
    generateSequence(sequence, index + 1);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    char sequence[DNA_LENGTH + 1]; // Allocate memory for the sequence (add an extra character for the null terminator)
    sequence[DNA_LENGTH] = '\0'; // Add the null terminator at the end of the sequence
    generateSequence(sequence, 0); // Generate the sequence recursively
    printf("\n");
    return 0;
}