//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LENGTH 100 // Change this to set the length of the genome
#define MUTATION_RATE 0.01 // Change this to set the mutation rate

char random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return '\0';
    }
}

void generate_genome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_base();
    }
    genome[GENOME_LENGTH] = '\0'; // Terminate the string with null character
}

void print_genome(char genome[]) {
    printf("%s\n", genome);
}

void mutate_genome(char genome[]) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double) rand() / RAND_MAX < MUTATION_RATE) {
            genome[i] = random_base();
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    char genome[GENOME_LENGTH + 1];
    generate_genome(genome);

    printf("Original genome:\n");
    print_genome(genome);

    mutate_genome(genome);

    printf("\nMutated genome:\n");
    print_genome(genome);

    return 0;
}