//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 1000

char generate_base() {
    switch(rand() % 4) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return '\0';
    }
}

void generate_dna(char *dna) {
    int i;
    for (i = 0; i < DNA_LENGTH; i++) {
        dna[i] = generate_base();
    }
}

void print_dna(char *dna) {
    int i;
    for (i = 0; i < DNA_LENGTH; i++) {
        putchar(dna[i]);
        if (i % 10 == 9) {
            putchar(' ');
        }
        if (i % 50 == 49) {
            putchar('\n');
        }
    }
    putchar('\n');
}

void mutate_dna(char *dna, float rate) {
    int i;
    for (i = 0; i < DNA_LENGTH; i++) {
        if ((float)rand()/(float)RAND_MAX < rate) {
            dna[i] = generate_base();
        }
    }
}

int main() {
    srand(time(NULL));

    char dna[DNA_LENGTH];
    generate_dna(dna);
    printf("Original DNA Sequence:\n");
    print_dna(dna);

    float mutation_rate = 0.01;
    mutate_dna(dna, mutation_rate);
    printf("DNA Sequence after Mutation (rate = %f):\n", mutation_rate);
    print_dna(dna);

    return 0;
}