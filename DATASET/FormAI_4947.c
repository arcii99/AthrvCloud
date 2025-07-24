//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10000

char random_base() {
    int random_int = rand() % 4;
    switch (random_int) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return ' ';
    }
}

void generate_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = random_base();
    }
}

void print_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

void mutate_sequence(char* sequence, int length, int n_mutations) {
    for (int i = 0; i < n_mutations; i++) {
        int mutation_index = rand() % length;
        sequence[mutation_index] = random_base();
    }
}

int main() {
    srand(time(NULL));

    char genome[MAX_LENGTH];
    int genome_length = 5000;
    int n_mutations = 10;

    generate_sequence(genome, genome_length);
    printf("Original Sequence:\n");
    print_sequence(genome, genome_length);

    mutate_sequence(genome, genome_length, n_mutations);
    printf("\n\nMutated Sequence:\n");
    print_sequence(genome, genome_length);

    return 0;
}