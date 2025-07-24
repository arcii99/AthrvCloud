//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100
#define MUTATION_RATE 0.1

void generate_genome(int genome[]) {
    srand(time(NULL));
    for(int i=0; i<GENOME_SIZE; i++) {
        genome[i] = rand() % 4;
    }
}

void print_genome(int genome[]) {
    for(int i=0; i<GENOME_SIZE; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
            default:
                printf("N");
        }
    }
    printf("\n");
}

void mutate_genome(int genome[]) {
    srand(time(NULL));
    for(int i=0; i<GENOME_SIZE; i++) {
        double chance = (double)rand() / RAND_MAX;
        if(chance < MUTATION_RATE) {
            genome[i] = rand() % 4;
        }
    }
}

int main() {
    int genome[GENOME_SIZE];
    generate_genome(genome);
    printf("Original genome:\n");
    print_genome(genome);

    mutate_genome(genome);
    printf("Mutated genome:\n");
    print_genome(genome);

    return 0;
}