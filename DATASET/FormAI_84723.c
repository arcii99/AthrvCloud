//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
/* A Genome Sequencing Simulator Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 100 /* length of the genome sequence */
#define MUTATION_RATE 5 /* mutation rate in percent */

/* function to randomly generate a DNA base */
char random_base() {
    char base[4] = {'A', 'C', 'G', 'T'};
    return base[rand() % 4];
}

/* function to generate a random genome sequence */
void initialize_genome(char genome[], int length) {
    int i;
    for(i=0; i<length; i++) {
        genome[i] = random_base();
    }
}

/* function to mutate a genome base */
char mutate_base(char base) {
    int chance = rand() % 100;
    if(chance < MUTATION_RATE) {
        base = random_base();
    }
    return base;
}

/* function to mutate a genome sequence */
void mutate_genome(char genome[], int length) {
    int i;
    for(i=0; i<length; i++) {
        genome[i] = mutate_base(genome[i]);
    }
}

/* function to display a genome sequence */
void display_genome(char genome[], int length) {
    int i;
    for(i=0; i<length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    char genome[LENGTH];
    srand(time(NULL));
    initialize_genome(genome, LENGTH);
    printf("Original Genome Sequence:\n");
    display_genome(genome, LENGTH);
    printf("Mutated Genome Sequence:\n");
    mutate_genome(genome, LENGTH);
    display_genome(genome, LENGTH);
    return 0;
}