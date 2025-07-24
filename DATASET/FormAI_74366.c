//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000000 // Length of the genome sequence
#define MUTATION_RATE 0.01 // Mutation rate

/*
 * Returns a random nucleotide
 */
char random_nucleotide() {
    int rand_num = rand() % 4;
    switch (rand_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

/*
 * Creates a random genome sequence
 */
void create_genome_sequence(char genome_sequence[]) {
    for (int i = 0; i < LENGTH; i++) {
        genome_sequence[i] = random_nucleotide();
    }
}

/*
 * Mutates the genome sequence with a given mutation rate
 */
void mutate_genome_sequence(char genome_sequence[]) {
    for (int i = 0; i < LENGTH; i++) {
        double mutation_chance = (double) rand() / (double) RAND_MAX;
        if (mutation_chance < MUTATION_RATE) {
            genome_sequence[i] = random_nucleotide();
        }
    }
}

/*
 * Prints the genome sequence
 */
void print_genome_sequence(char genome_sequence[]) {
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", genome_sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initializes the random number generator
    char genome_sequence[LENGTH];
    
    create_genome_sequence(genome_sequence);
    printf("Original genome sequence:\n");
    print_genome_sequence(genome_sequence);
    
    mutate_genome_sequence(genome_sequence);
    printf("Mutated genome sequence:\n");
    print_genome_sequence(genome_sequence);
    
    return 0;
}