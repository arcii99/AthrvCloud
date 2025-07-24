//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000
#define BASES "ACGT"

char *generate_genome() {
    srand(time(NULL));
    char *genome = malloc(sizeof(char) * (GENOME_LENGTH + 1));
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

void print_genome(char *genome) {
    printf("The Genome Sequence is:\n%s\n", genome);
}

void mutate_genome(char *genome, float mutation_rate) {
    srand(time(NULL));
    for(int i = 0; i < GENOME_LENGTH; i++) {
        float r = (float)rand()/(float)RAND_MAX;
        if (r < mutation_rate) {
            genome[i] = BASES[rand() % 4];
        }
    }
}

int main() {
    char *genome = generate_genome();
    print_genome(genome);
    float mutation_rate = 0.05;
    printf("Simulating genome mutation with a mutation rate of %f\n", mutation_rate);
    mutate_genome(genome, mutation_rate);
    print_genome(genome);
    free(genome);
    return 0;
}