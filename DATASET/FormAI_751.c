//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 500
#define MUTATION_RATE 0.01

int main()
{
    srand(time(NULL));
    
    char genome[GENOME_SIZE];
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4;
    }
    
    printf("Original genome: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%d", genome[i]);
    }
    printf("\n");
    
    int num_mutations = 0;
    for (double i = 0; i < GENOME_SIZE * MUTATION_RATE; i++) {
        int mutation_index = rand() % GENOME_SIZE;
        int new_value = rand() % 4;
        genome[mutation_index] = new_value;
        num_mutations++;
    }
    
    printf("Mutated genome: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%d", genome[i]);
    }
    printf("\n");
    printf("Number of mutations: %d\n", num_mutations);
    
    double counts[4] = {0};
    for (int i = 0; i < GENOME_SIZE; i++) {
        counts[genome[i]]++;
    }
    
    printf("Base counts:\n");
    printf("A: %.0lf\n", counts[0]);
    printf("C: %.0lf\n", counts[1]);
    printf("G: %.0lf\n", counts[2]);
    printf("T: %.0lf\n", counts[3]);
    
    return 0;
}