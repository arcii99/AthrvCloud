//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

char generate_random_base() {
    int random_num = rand() % 4;
    char base;

    switch(random_num) {
        case 0:
            base = 'A';
            break;
        case 1:
            base = 'C';
            break;
        case 2:
            base = 'G';
            break;
        case 3:
            base = 'T';
            break;
        default:
            base = 'N';
    }

    return base;
}

void generate_genome(char genome[]) {
    int i;

    for(i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = generate_random_base();
    }
}

void mutate_genome(char genome[]) {
    int i;

    for(i = 0; i < GENOME_LENGTH; i++) {
        double random_num = ((double)rand() / RAND_MAX);

        if(random_num < MUTATION_RATE) {
            genome[i] = generate_random_base();
        }
    }
}

void print_genome(char genome[]) {
    int i;

    for(i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }

    printf("\n");
}

int main() {
    char genome[GENOME_LENGTH];
    srand(time(0));

    generate_genome(genome);
    print_genome(genome);

    mutate_genome(genome);
    print_genome(genome);

    return 0;
}