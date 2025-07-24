//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000 // Length of genome sequence
#define MUTATION_RATE 0.01 // Probability of mutation in each nucleotide position
#define SEED 123456 // Seed for random number generator

// Function to randomly generate a genome sequence
void generate_genome_sequence(char *sequence) {
    int i;
    srand(SEED);
    for(i=0; i<GENOME_LENGTH; i++) {
        int nucleotide_index = rand() % 4;
        switch(nucleotide_index) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
}

// Function to mutate a genome sequence based on mutation rate
void mutate_genome_sequence(char *sequence) {
    int i;
    srand(SEED);
    for(i=0; i<GENOME_LENGTH; i++) {
        float mutation_probability = (float)rand() / (float)RAND_MAX;
        if(mutation_probability < MUTATION_RATE) {
            int nucleotide_index = rand() % 4;
            switch(nucleotide_index) {
                case 0:
                    sequence[i] = 'A';
                    break;
                case 1:
                    sequence[i] = 'C';
                    break;
                case 2:
                    sequence[i] = 'G';
                    break;
                case 3:
                    sequence[i] = 'T';
                    break;
            }
        }
    }
}

int main() {
    char genome_sequence[GENOME_LENGTH];
    generate_genome_sequence(genome_sequence);
    printf("Generated Genome Sequence: %s\n", genome_sequence);
    mutate_genome_sequence(genome_sequence);
    printf("Mutated Genome Sequence: %s\n", genome_sequence);
    return 0;
}