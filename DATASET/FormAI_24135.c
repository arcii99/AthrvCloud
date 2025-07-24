//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// pre-defined genome bases
typedef enum {A, C, G, T} base_t;

// struct for holding genome sequence data
typedef struct {
    unsigned int length;
    base_t *data;
} genome_t;

// generate a random base from A, C, G, T
base_t generate_base() {
    int val = rand() % 4;
    switch (val) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            return A;
    }
}

// generate a random genome sequence of a specified length
genome_t generate_genome(int length) {
    genome_t genome;
    genome.length = length;
    genome.data = (base_t *) malloc(sizeof(base_t) * length);
    if (genome.data == NULL) {
        printf("Failed to allocate genome memory\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        genome.data[i] = generate_base();
    }

    return genome;
}

// print a genome sequence in a readable format
void print_genome(genome_t genome) {
    for (int i = 0; i < genome.length; i++) {
        switch (genome.data[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed random number generator

    genome_t genome1 = generate_genome(100);
    printf("Genome 1: ");
    print_genome(genome1);

    genome_t genome2 = generate_genome(100);
    printf("Genome 2: ");
    print_genome(genome2);

    return 0;
}