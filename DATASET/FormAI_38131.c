//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GENOME_SIZE 10000
#define NUM_BASES 4
#define MUTATION_RATE 0.05

int randint(int min, int max){
    return rand() % (max - min + 1) + min;
}

char random_base(){
    char bases[NUM_BASES] = {'A', 'C', 'G', 'T'};
    return bases[randint(0, NUM_BASES - 1)];
}

void generate_random_genome(char genome[GENOME_SIZE]){
    for(int i=0; i < GENOME_SIZE; i++){
        genome[i] = random_base();
    }
}

void print_genome(char genome[GENOME_SIZE]){
    for(int i=0; i < GENOME_SIZE; i++){
        printf("%c", genome[i]);
    }
}

void mutate_genome(char genome[GENOME_SIZE]){
    for(int i=0; i < GENOME_SIZE; i++){
        double r = (double)rand() / RAND_MAX;
        if(r < MUTATION_RATE){
            genome[i] = random_base();
        }
    }
}

int main(){
    srand(time(NULL));
    
    char original_genome[GENOME_SIZE];
    generate_random_genome(original_genome);
    printf("Original Genome: ");
    print_genome(original_genome);
    printf("\n");
    
    char mutated_genome[GENOME_SIZE];
    memcpy(mutated_genome, original_genome, GENOME_SIZE);
    mutate_genome(mutated_genome);
    printf("Mutated Genome:  ");
    print_genome(mutated_genome);
    printf("\n");
    
    return 0;
}