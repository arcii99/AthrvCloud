//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LENGTH 10000
#define MUTATION_RATE 0.01

void print_genome(char genome[]) {
    int i;
    for (i=0; i<GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void mutate_genome(char genome[]) {
    int i;
    for (i=0; i<GENOME_LENGTH; i++) {
        if ((double)random_int(0, 100)/100.0 < MUTATION_RATE) {
            genome[i] = random_int(65, 90);
        }
    }
}

int main() {
    char genome[GENOME_LENGTH+1];
    int i;
    srand(time(0));

    // Generate random genome
    for (i=0; i<GENOME_LENGTH; i++) {
        genome[i] = random_int(65, 90);
    }
    genome[GENOME_LENGTH] = '\0';

    printf("Original genome:\n");
    print_genome(genome);

    // Mutate genome and print result
    mutate_genome(genome);
    printf("Mutated genome:\n");
    print_genome(genome);

    return 0;
}