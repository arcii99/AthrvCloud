//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000 // Total number of base pairs in the genome
#define MUTATION_RATE 0.01 // Probability of a mutation at each base pair

char get_random_base() {
    // Returns a random base (A, C, G, or T)
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
    return 'A';
}

void simulate_genome_evolution(char* genome) {
    // Simulates evolution of the genome by introducing mutations
    for (int i = 0; i < GENOME_SIZE; i++) {
        double r = (double) rand() / RAND_MAX;
        if (r < MUTATION_RATE) {
            genome[i] = get_random_base();
        }
    }
}

void print_genome_statistics(char* genome) {
    // Prints basic statistics about the genome
    int count[4] = {0};
    for (int i = 0; i < GENOME_SIZE; i++) {
        switch (genome[i]) {
            case 'A': count[0]++; break;
            case 'C': count[1]++; break;
            case 'G': count[2]++; break;
            case 'T': count[3]++; break;
        }
    }
    printf("BASE COUNT:\n");
    printf("A: %d\nC: %d\nG: %d\nT: %d\n", count[0], count[1], count[2], count[3]);
}

int main() {
    srand(time(NULL));
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = get_random_base();
    }
    printf("INITIAL GENOME:\n");
    printf("%.*s\n\n", GENOME_SIZE, genome);
    simulate_genome_evolution(genome);
    printf("GENOME AFTER EVOLUTION:\n");
    printf("%.*s\n\n", GENOME_SIZE, genome);
    print_genome_statistics(genome);
    return 0;
}