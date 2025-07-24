//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

// Function to randomly generate a genome of length GENOME_LENGTH
void generate_random_genome(int genome[GENOME_LENGTH]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 4; // Generate a random nucleotide (0 = A, 1 = C, 2 = G, 3 = T)
    }
}

// Function to print a genome to the console
void print_genome(int genome[GENOME_LENGTH]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("-");
        }
    }
    printf("\n");
}

// Function to mutate a single nucleotide in a genome with probability MUTATION_RATE
void mutate_genome(int genome[GENOME_LENGTH]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (((double) rand() / RAND_MAX) < MUTATION_RATE) { // Check if this nucleotide should mutate
            genome[i] = rand() % 4; // Generate a random new nucleotide
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int genome[GENOME_LENGTH];
    
    printf("Generating a random genome...\n");
    generate_random_genome(genome);
    
    printf("Initial genome: ");
    print_genome(genome);
    
    printf("Mutating genome...\n");
    mutate_genome(genome);
    
    printf("Mutated genome: ");
    print_genome(genome);
    
    return 0;
}