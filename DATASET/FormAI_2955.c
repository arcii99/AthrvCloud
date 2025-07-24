//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100

void generate_genome(int genome[]) {
    srand(time(NULL));
    for(int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4 + 1;
    }
}

void mutate_genome(int genome[], int mutation_rate) {
    srand(time(NULL));
    for(int i = 0; i < GENOME_SIZE; i++) {
        int random_number = rand() % 1000;
        if(random_number < mutation_rate) {
            genome[i] = rand() % 4 + 1;
        }
    }
}

int main() {
    int genome[GENOME_SIZE];
    int mutation_rate;
    
    printf("Enter the mutation rate (0 - 1000): ");
    scanf("%d", &mutation_rate);
    
    generate_genome(genome);
    
    printf("Initial genome sequence: ");
    for(int i = 0; i < GENOME_SIZE; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");
    
    mutate_genome(genome, mutation_rate);
    
    printf("Mutated genome sequence: ");
    for(int i = 0; i < GENOME_SIZE; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");
    
    return 0;
}