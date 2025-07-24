//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
/**
 * C Genome Sequencing Simulator
 * Simulates the sequencing of genomes, randomizing nucleotides and introducing mutations
 * Author: The AI Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000 // Size of genome to be sequenced
#define MUTATION_RATE 0.01 // Probability of mutation occuring at one nucleotide

char* nucleotides = "ACGT"; // Array of possible nucleotides

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for genome
    char* genome = (char*) malloc(GENOME_SIZE * sizeof(char));

    // Generate random genome
    for (int i = 0; i < GENOME_SIZE; i++) {
        int random_index = rand() % 4;
        genome[i] = nucleotides[random_index];
    }

    // Introduce mutations to genome
    for (int i = 0; i < GENOME_SIZE; i++) {
        float random_num = (float) rand() / RAND_MAX;
        if (random_num < MUTATION_RATE) {
            int random_index = rand() % 4;
            genome[i] = nucleotides[random_index];
        }
    }

    // Print first 100 nucleotides of genome
    printf("First 100 nucleotides of genome: ");
    for (int i = 0; i < 100; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // Free memory
    free(genome);

    return 0;
}