//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char BASES[4] = {'A', 'C', 'G', 'T'};
int GENOME_LENGTH = 100;

char* create_genome(int genome_length) {
    char* genome = (char*) malloc((genome_length + 1) * sizeof(char));
    for (int i = 0; i < genome_length; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[genome_length] = '\0';
    return genome;
}

char* mutate_genome(char* genome) {
    int mutation_index = rand() % GENOME_LENGTH;
    genome[mutation_index] = BASES[rand() % 4];
    return genome;
}

int main() {
    srand(time(NULL));
    char* original_genome = create_genome(GENOME_LENGTH);
    printf("Original genome: %s\n", original_genome);
    
    char* mutated_genome = mutate_genome(original_genome);
    printf("Mutated genome: %s\n", mutated_genome);
    
    free(original_genome);
    free(mutated_genome);
    return 0;
}