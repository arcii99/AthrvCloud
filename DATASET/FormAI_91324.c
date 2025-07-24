//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 50

// Utility function to print the sequence
void print_sequence(int *sequence) {
    printf("Sequence:");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf(" %d", sequence[i]);
    }
    printf("\n");
}

// Function to generate a random sequence
void generate_sequence(int *sequence) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = rand() % 4; // Generate a random integer between 0 and 3 inclusive
    }
}

// Function to simulate genome sequencing
void simulate_sequencing(int *reference, int *sequence) {
    // Create a copy of the reference sequence
    int reference_copy[SEQUENCE_LENGTH];
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        reference_copy[i] = reference[i];
    }

    // Introduce mutations into the sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (reference_copy[i] == sequence[i]) {
            continue; // If the base is the same as the reference, no mutation occurs
        }

        // Otherwise, introduce a random mutation
        int mutation = rand() % 3; // Generate a random integer between 0 and 2 inclusive
        switch (mutation) {
            case 0: // Substitution
                sequence[i] = reference_copy[i];
                break;
            case 1: // Insertion
                for (int j = SEQUENCE_LENGTH - 1; j > i; j--) {
                    sequence[j] = sequence[j - 1];
                }
                sequence[i] = reference_copy[i];
                break;
            case 2: // Deletion
                for (int j = i + 1; j < SEQUENCE_LENGTH; j++) {
                    sequence[j - 1] = sequence[j];
                }
                sequence[SEQUENCE_LENGTH - 1] = rand() % 4; // Insert a random base at the end
                break;
        }
        reference_copy[i] = sequence[i]; // Update the reference copy
    }
}

int main() {
    int reference_sequence[SEQUENCE_LENGTH];
    generate_sequence(reference_sequence);
    print_sequence(reference_sequence);

    int sequence[SEQUENCE_LENGTH];
    generate_sequence(sequence);
    print_sequence(sequence);

    simulate_sequencing(reference_sequence, sequence);
    print_sequence(sequence);

    return 0;
}