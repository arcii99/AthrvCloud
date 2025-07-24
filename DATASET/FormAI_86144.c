//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000

// Generate a random DNA sequence of specified length
char* generate_sequence(size_t length) {
    char* sequence = malloc(sizeof(char) * length);
    if (sequence == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    srand(time(NULL));
    for (size_t i = 0; i < length; i++) {
        int base_num = rand() % 4;
        if (base_num == 0) {
            sequence[i] = 'A';
        } else if (base_num == 1) {
            sequence[i] = 'C';
        } else if (base_num == 2) {
            sequence[i] = 'G';
        } else {
            sequence[i] = 'T';
        }
    }
    sequence[length] = '\0'; // Add null terminator to end of string
    return sequence;
}

// Print a DNA sequence
void print_sequence(char* sequence) {
    printf("DNA Sequence: %s\n", sequence);
}

// Simulate genome sequencing by generating a DNA sequence of length "sequenced_length"
// from the original DNA sequence starting at the specified "start_index".
char* sequence_genome(char* original_sequence, size_t start_index, size_t sequenced_length) {
    char* sequenced_sequence = malloc(sizeof(char) * (sequenced_length + 1));
    if (sequenced_sequence == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    size_t end_index = start_index + sequenced_length - 1;
    if (end_index > GENOME_SIZE) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }

    for (size_t i = 0; i < sequenced_length; i++) {
        sequenced_sequence[i] = original_sequence[start_index + i];
    }
    sequenced_sequence[sequenced_length] = '\0'; // Add null terminator to end of string
    return sequenced_sequence;
}

int main() {
    // Generate original DNA sequence
    char* original_sequence = generate_sequence(GENOME_SIZE);

    // Print original sequence
    print_sequence(original_sequence);

    // Sequence part of genome
    char* sequenced_sequence = sequence_genome(original_sequence, 200, 100);

    // Print sequenced sequence
    print_sequence(sequenced_sequence);

    // Free memory allocated for sequences
    free(original_sequence);
    free(sequenced_sequence);

    return 0;
}