//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100000

// Function to randomly generate nucleotide sequence
char* generate_sequence(int length) {
    char* sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 4; // Randomly generate a number between 0 and 3
        switch(random_number) {
            case 0: sequence[i] = 'A'; break;
            case 1: sequence[i] = 'C'; break;
            case 2: sequence[i] = 'G'; break;
            case 3: sequence[i] = 'T'; break;
        }
    }
    return sequence;
}

// Function to simulate sequencing errors
void simulate_errors(char* sequence, float error_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        float random_number = (float)rand() / (float)RAND_MAX; // Generate a random number between 0 and 1
        if (random_number <= error_rate) {
            int random_mutation = rand() % 3; // Randomly generate a number between 0 and 2
            switch(random_mutation) {
                case 0: sequence[i] = 'A' + ('C' - sequence[i]); break; // Mutate to opposite nucleotide
                case 1: sequence[i] = 'A' + ('G' - sequence[i]); break; // Mutate to opposite nucleotide
                case 2: sequence[i] = 'A' + ('T' - sequence[i]); break; // Mutate to opposite nucleotide
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    char* original_sequence = generate_sequence(SEQUENCE_LENGTH);
    printf("Original Sequence: %s\n", original_sequence);

    float error_rate = 0.01; // Set error rate to 1%
    simulate_errors(original_sequence, error_rate);
    printf("Sequenced Sequence: %s\n", original_sequence);

    free(original_sequence); // Free allocated memory
    return 0;
}