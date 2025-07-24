//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100
#define MUTATION_RATE 0.1

void print_genome(char* genome) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c ", genome[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void simulate_genome_sequence(char* genome) {
    srand(time(NULL));
    // Populate the genome randomly
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4;
    }

    printf("Original genome:\n");
    print_genome(genome);

    // Introduce mutations
    for (int i = 0; i < GENOME_SIZE; i++) {
        if ((rand() / (double)RAND_MAX) < MUTATION_RATE) {
            genome[i] = rand() % 4;
        }
    }

    printf("Mutated genome:\n");
    print_genome(genome);

    // Translate the genome to protein sequence
    char protein[GENOME_SIZE / 3];
    for (int i = 0; i < GENOME_SIZE; i += 3) {
        int codon = genome[i] * 16 + genome[i+1] * 4 + genome[i+2];
        switch (codon) {
            case 0: protein[i/3] = 'A'; break;
            case 1: protein[i/3] = 'C'; break;
            case 2: protein[i/3] = 'G'; break;
            case 3: protein[i/3] = 'T'; break;
            default: protein[i/3] = 'X'; break;
        }
    }

    printf("Protein sequence:\n");
    for (int i = 0; i < GENOME_SIZE / 3; i++) {
        printf("%c", protein[i]);
    }
    printf("\n");
}

int main() {
    char genome[GENOME_SIZE];
    simulate_genome_sequence(genome);
    return 0;
}