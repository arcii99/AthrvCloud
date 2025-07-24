//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the alphabet to use in genome sequencing
#define ALPHABET_SIZE 4
const char ALPHABET[ALPHABET_SIZE] = {'A', 'C', 'G', 'T'};

// Define the maximum length of the genome to sequence
#define MAX_GENOME_LENGTH 1000

// Define the mutation rate, which determines the chance of a nucleotide being mutated
#define MUTATION_RATE 0.1

// Function to randomly generate a nucleotide from the alphabet
char random_nucleotide() {
    int index = rand() % ALPHABET_SIZE;
    return ALPHABET[index];
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Randomly generate a genome to sequence
    char genome[MAX_GENOME_LENGTH];
    int genome_length = rand() % MAX_GENOME_LENGTH + 1;
    for (int i = 0; i < genome_length; i++) {
        genome[i] = random_nucleotide();
    }
    genome[genome_length] = '\0';

    // Print the original genome
    printf("Original genome: %s\n", genome);

    // Simulate sequencing the genome by randomly selecting a starting point
    // and sequencing a given number of nucleotides
    int start_index = rand() % genome_length;
    int sequenced_length = rand() % (genome_length - start_index + 1);
    char sequenced_genome[MAX_GENOME_LENGTH];
    for (int i = 0; i < sequenced_length; i++) {
        sequenced_genome[i] = genome[start_index + i];

        // Simulate mutations by randomly selecting a nucleotide to mutate
        if (rand() < MUTATION_RATE * RAND_MAX) {
            sequenced_genome[i] = random_nucleotide();
        }
    }
    sequenced_genome[sequenced_length] = '\0';

    // Print the sequenced genome
    printf("Sequenced genome: %s\n", sequenced_genome);

    return 0;
}