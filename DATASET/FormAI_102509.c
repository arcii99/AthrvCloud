//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

// Define nucleotides
typedef enum { A, C, G, T } nucleotide_t;

// Define genome
typedef struct {
    nucleotide_t nucleotides[MAX_GENOME_LENGTH];
    int length;
} genome_t;

// Print genome
void printGenome(genome_t genome) {
    for(int i=0; i<genome.length; i++) {
        printf("%c", "ACGT"[genome.nucleotides[i]]);
    }
    printf("\n");
}

// Generate random nucleotide
nucleotide_t randomNucleotide() {
    return rand() % 4;
}

// Generate random genome
genome_t randomGenome(int length) {
    genome_t genome;
    genome.length = length;
    for(int i=0; i<length; i++) {
        genome.nucleotides[i] = randomNucleotide();
    }
    return genome;
}

// Mutate genome
void mutateGenome(genome_t* genome) {
    for(int i=0; i<genome->length; i++) {
        if((double)rand()/(double)RAND_MAX < MUTATION_RATE) {
            genome->nucleotides[i] = randomNucleotide();
        }
    }
}

// Crossover genomes
genome_t crossoverGenomes(genome_t genome1, genome_t genome2) {
    int length = genome1.length < genome2.length ? genome1.length : genome2.length;
    genome_t genome;
    genome.length = length;
    for(int i=0; i<length; i++) {
        genome.nucleotides[i] = rand() % 2 ? genome1.nucleotides[i] : genome2.nucleotides[i];
    }
    return genome;
}

// Main function
int main() {
    srand(time(NULL));
    genome_t genome1 = randomGenome(500);
    genome_t genome2 = randomGenome(700);
    printf("Original genomes:\n");
    printf("Genome 1: ");
    printGenome(genome1);
    printf("Genome 2: ");
    printGenome(genome2);
    genome_t genome3 = crossoverGenomes(genome1, genome2);
    printf("Crossover genome:\n");
    printf("Genome 3: ");
    printGenome(genome3);
    mutateGenome(&genome3);
    printf("Mutated genome:\n");
    printf("Genome 3: ");
    printGenome(genome3);
    return 0;
}