//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char random_nucleotide() {
    int r = random_int(0, 3);
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

void generate_genome(char *genome) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = random_nucleotide();
    }
    genome[GENOME_SIZE] = '\0';
}

void print_genome(char *genome) {
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    srand(time(0));
    
    char genome1[GENOME_SIZE + 1];
    char genome2[GENOME_SIZE + 1];
    
    generate_genome(genome1);
    generate_genome(genome2);
    
    printf("Genome 1:\n");
    print_genome(genome1);
    
    printf("Genome 2:\n");
    print_genome(genome2);
    
    printf("Comparing genomes:\n");
    int differences = 0;
    for (int i = 0; i < GENOME_SIZE; i++) {
        if (genome1[i] != genome2[i]) {
            printf("Found difference at position %d: %c != %c\n", i, genome1[i], genome2[i]);
            differences++;
        }
    }
    printf("Total differences: %d\n", differences);
    
    return 0;
}