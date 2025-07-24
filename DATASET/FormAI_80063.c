//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define GENOME_LEN 100     // Length of simulated genome
#define MUTATION_RATE 0.2  // Probability of mutation in each nucleotide

// Struct for a nucleotide
typedef struct {
    char base;   // 'A', 'C', 'G', or 'T'
    bool mutated; // True if this nucleotide has undergone mutation
} Nucleotide;

// Function to generate a random nucleotide
Nucleotide generate_nucleotide() {
    Nucleotide n;
    int r = rand() % 4;
    switch(r) {
        case 0:
            n.base = 'A';
            break;
        case 1:
            n.base = 'C';
            break;
        case 2:
            n.base = 'G';
            break;
        case 3:
            n.base = 'T';
            break;
    }
    n.mutated = false;
    return n;
}

// Function to create a randomized genome
void generate_genome(Nucleotide genome[]) {
    int i;
    for(i = 0; i < GENOME_LEN; i++) {
        genome[i] = generate_nucleotide();
    }
}

// Function to simulate mutation of a nucleotide
Nucleotide mutate_nucleotide(Nucleotide n) {
    Nucleotide new_n = n;
    if(!n.mutated && (rand()/(double)RAND_MAX) < MUTATION_RATE) {
        int r = rand() % 3;
        switch(r) {
            case 0:
                new_n.base = 'A';
                break;
            case 1:
                new_n.base = 'C';
                break;
            case 2:
                new_n.base = 'G';
                break;
            case 3:
                new_n.base = 'T';
                break;
        }
        new_n.mutated = true;
    }
    return new_n;
}

// Function to simulate mutation of a genome
void mutate_genome(Nucleotide genome[]) {
    int i;
    for(i = 0; i < GENOME_LEN; i++) {
        genome[i] = mutate_nucleotide(genome[i]);
    }
}

// Function to print a genome
void print_genome(Nucleotide genome[]) {
    int i;
    for(i = 0; i < GENOME_LEN; i++) {
        printf("%c", genome[i].base);
    }
    printf("\n");
}

// Asynchronous function to simulate genome sequencing
void sequence_genome_async(Nucleotide genome[]) {
    int i;
    for(i = 0; i < GENOME_LEN; i++) {
        usleep(100000);  // Simulate sequencing delay
        printf("%c", genome[i].base);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    Nucleotide genome[GENOME_LEN];

    generate_genome(genome);
    printf("Generated genome: ");
    print_genome(genome);

    mutate_genome(genome);
    printf("Mutated genome: ");
    print_genome(genome);

    printf("Sequencing genome asynchronously: ");
    sequence_genome_async(genome);

    return 0;
}