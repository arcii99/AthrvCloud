//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

char nucleotides[4] = {'A', 'C', 'G', 'T'};

void generate_random_genome(char *genome) {
    srand(time(NULL));
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        int r = rand() % 4;
        genome[i] = nucleotides[r];
    }
    genome[GENOME_LENGTH] = '\0';
}

void mutate_genome(char *genome) {
    srand(time(NULL));
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand() / (double)RAND_MAX < MUTATION_RATE) {
            int r = rand() % 4;
            genome[i] = nucleotides[r];
        }
    }
}

void print_genome(char *genome) {
    printf("%s\n", genome);
}

int main() {
    char genome[GENOME_LENGTH+1];
    generate_random_genome(genome);
    print_genome(genome);
    mutate_genome(genome);
    print_genome(genome);
    return 0;
}