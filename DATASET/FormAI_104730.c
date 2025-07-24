//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000

// Initialize the genome with random nucleotides
void init_genome(char *genome) {
    srand(time(NULL));
    for(int i = 0; i < GENOME_SIZE; i++) {
        int rand_nucleotide = rand() % 4;
        switch(rand_nucleotide) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
            default:
                break;
        }
    }
}

// Mutate the genome randomly
void mutate_genome(char *genome) {
    srand(time(NULL));
    for(int i = 0; i < GENOME_SIZE; i++) {
        int rand_mutate = rand() % 100;
        if(rand_mutate < 5) { // 5% chance of mutation
            int rand_nucleotide = rand() % 4;
            switch(rand_nucleotide) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'C';
                    break;
                case 2:
                    genome[i] = 'G';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
                default:
                    break;
            }
        }
    }
}

// Compare two genomes and returns the similarity percentage
double compare_genomes(char *genome1, char *genome2) {
    int matches = 0;
    for(int i = 0; i < GENOME_SIZE; i++) {
        if(genome1[i] == genome2[i]) {
            matches++;
        }
    }
    return (double)matches / GENOME_SIZE * 100;
}

// Main function to simulate genome sequencing
int main() {
    char genome1[GENOME_SIZE];
    char genome2[GENOME_SIZE];
    init_genome(genome1);
    printf("Original Genome: %s\n", genome1);
    printf("Simulating Genome Sequencing...\n");
    mutate_genome(genome1);
    printf("Mutated Genome: %s\n", genome1);
    printf("Simulating Genome Sequencing...\n");
    mutate_genome(genome1);
    printf("Mutated Genome: %s\n", genome1);
    printf("Simulating Genome Sequencing...\n");
    mutate_genome(genome1);
    printf("Mutated Genome: %s\n", genome1);
    init_genome(genome2);
    printf("Original Genome: %s\n", genome2);
    printf("Simulating Genome Sequencing...\n");
    mutate_genome(genome2);
    printf("Mutated Genome: %s\n", genome2);
    printf("Simulating Genome Sequencing...\n");
    mutate_genome(genome2);
    printf("Mutated Genome: %s\n", genome2);
    printf("Comparing genomes...\n");
    double similarity = compare_genomes(genome1, genome2);
    printf("Genome similarity percentage: %.2f%%\n", similarity);
    return 0;
}