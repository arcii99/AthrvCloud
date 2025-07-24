//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct genome {
    int dna_strand[1000];
} Genome;

int random_num() {
    return rand() % 4;
}

void generate_genome(Genome *g, int len) {
    for(int i = 0; i < len; i++) {
        g->dna_strand[i] = random_num();
    }
}

void print_genome(Genome *g, int len) {
    for(int i = 0; i < len; i++) {
        switch(g->dna_strand[i]) {
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
        }
    }
    printf("\n");
}

void mutate_genome(Genome *g, int len) {
    int mutations = len / 50; // introduce 2% mutations
    for(int i = 0; i < mutations; i++) {
        int mutation_point = rand() % len;
        g->dna_strand[mutation_point] = random_num();
    }
}

int main() {
    srand(time(NULL));
    int genome_length = 1000;
    Genome g1;
    printf("Generating Genome:\n");
    generate_genome(&g1, genome_length);
    print_genome(&g1, genome_length);
    printf("----------------------------------------\n");
    printf("Mutating Genome:\n");
    mutate_genome(&g1, genome_length);
    print_genome(&g1, genome_length);
    return 0;
}