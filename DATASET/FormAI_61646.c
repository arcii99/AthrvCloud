//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000

void generate_genome(char genome[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int nucleotide = rand() % 4;
        if (nucleotide == 0) genome[i] = 'A';
        else if (nucleotide == 1) genome[i] = 'C';
        else if (nucleotide == 2) genome[i] = 'G';
        else genome[i] = 'T';
    }
}

void mutate_genome(char genome[], int size, double mutation_rate) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        double r = (double) rand() / (double) RAND_MAX;
        if (r < mutation_rate) {
            int nucleotide = rand() % 4;
            if (nucleotide == 0) genome[i] = 'A';
            else if (nucleotide == 1) genome[i] = 'C';
            else if (nucleotide == 2) genome[i] = 'G';
            else genome[i] = 'T';
        }
    }
}

int main() {
    char genome[GENOME_SIZE];

    // Generate a random genome
    generate_genome(genome, GENOME_SIZE);
    printf("Original genome:\n%s\n\n", genome);

    // Mutate the genome
    double mutation_rate = 0.01;
    mutate_genome(genome, GENOME_SIZE, mutation_rate);
    printf("Mutated genome (mutation rate = %lf):\n%s\n", mutation_rate, genome);

    return 0;
}