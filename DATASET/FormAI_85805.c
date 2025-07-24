//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LEN 100
#define MUTATION_RATE 0.01

char random_base() {
    // return a random base from A, C, G, or T
    int rand_num = rand() % 4;
    char bases[] = {'A', 'C', 'G', 'T'};
    return bases[rand_num];
}

void mutate_genome(char *genome) {
    // randomly mutate a percentage of bases in the genome
    for (int i = 0; i < GENOME_LEN; i++) {
        double rand_num = (double) rand() / RAND_MAX;
        if (rand_num < MUTATION_RATE) {
            genome[i] = random_base();
        }
    }
}

void print_genome(char *genome, char *label) {
    printf("%s: ", label);
    for (int i = 0; i < GENOME_LEN; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // generate a reference genome
    char ref_genome[GENOME_LEN];
    for (int i = 0; i < GENOME_LEN; i++) {
        ref_genome[i] = random_base();
    }
    
    // generate a mutated genome from the reference
    char mut_genome[GENOME_LEN];
    for (int i = 0; i < GENOME_LEN; i++) {
        mut_genome[i] = ref_genome[i];
    }
    mutate_genome(mut_genome);
    
    // print genomes
    print_genome(ref_genome, "Reference genome");
    print_genome(mut_genome, "Mutated genome");
    
    return 0;
}