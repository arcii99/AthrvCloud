//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GENOME_LENGTH 1000
#define NUM_BASES 4
#define MUTATION_RATE 0.01
#define SEQUENCE_LENGTH 20

// Base nucleotides used in DNA sequencing
const char nucleotides[NUM_BASES] = {'A', 'C', 'G', 'T'};

// Function to generate random DNA sequence
void generate_dna_sequence(char *dna_sequence) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        int rand_num = rand() % NUM_BASES;
        dna_sequence[i] = nucleotides[rand_num];
    }
    dna_sequence[i] = '\0';
}

// Function to mutate DNA sequence
void mutate_dna_sequence(char *dna_sequence) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        if ((rand() / (double)RAND_MAX) < MUTATION_RATE) {
            int rand_num = rand() % NUM_BASES;
            dna_sequence[i] = nucleotides[rand_num];
        }
    }
}

// Function to print DNA sequence
void print_dna_sequence(char *dna_sequence) {
    printf("%s\n", dna_sequence);
}

// Function to generate random DNA subsequence
void generate_dna_subsequence(char *dna_sequence, char *subsequence, int start_index) {
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        subsequence[i] = dna_sequence[start_index + i];
    }
    subsequence[i] = '\0';
}

int main() {
    char dna_sequence[GENOME_LENGTH + 1];
    char subsequence[SEQUENCE_LENGTH + 1];
    srand(time(NULL));

    // Generate and mutate DNA sequence
    generate_dna_sequence(dna_sequence);
    mutate_dna_sequence(dna_sequence);

    // Print DNA sequence
    print_dna_sequence(dna_sequence);

    // Generate and print random subsequence
    generate_dna_subsequence(dna_sequence, subsequence, rand() % (GENOME_LENGTH - SEQUENCE_LENGTH));
    printf("Random DNA Subsequence: %s\n", subsequence);

    return 0;
}