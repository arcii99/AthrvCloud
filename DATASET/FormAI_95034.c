//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 50

char random_nucleotide() {
    int random_number = rand() % 4;
    switch(random_number) {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'G';
        case 3: return 'C';
    }
}

void generate_random_genome(char genome[GENOME_LENGTH+1]) {
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
    genome[GENOME_LENGTH] = '\0';
}

void mutate_genome(char genome[GENOME_LENGTH+1], int mutation_count) {
    srand(time(NULL)); // seed random generator
    for(int i=0; i<mutation_count; i++) {
        int random_index = rand() % GENOME_LENGTH;
        genome[random_index] = random_nucleotide();
    }
}

void print_genome(char genome[GENOME_LENGTH+1]) {
    printf("%s\n", genome);
}

int main() {
    char genome[GENOME_LENGTH+1];

    generate_random_genome(genome);
    printf("Original Genome:\n");
    print_genome(genome);

    int mutation_count = rand() % 5;
    printf("Mutation Count: %d\n", mutation_count);

    mutate_genome(genome, mutation_count);
    printf("Mutated Genome:\n");
    print_genome(genome);

    return 0;
}