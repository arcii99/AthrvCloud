//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define GENOME_LENGTH 1000000   // Define the length of the genome sequence
#define MUTATION_RATE 0.001     // Define the mutation rate for each base

int main() {
    // Create genome sequence array
    char genome[GENOME_LENGTH];
    
    // Initialize genome sequence with random nucleotides (A, T, C, G)
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int random_num = rand() % 4;    // Generate random number between 0 and 3
        switch(random_num) {    // Assign nucleotide based on random number
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }
    
    // Simulate mutations in the genome sequence
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float random_num = (float) rand() / RAND_MAX;     // Generate random number between 0 and 1
        if (random_num < MUTATION_RATE) {   // Determine if a mutation occurs
            switch(genome[i]) {     // Mutate nucleotide based on current value
                case 'A':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'A';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'C';
                    break;
            }
        }
    }
    
    // Print out the mutated genome sequence
    printf("Mutated genome sequence:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}