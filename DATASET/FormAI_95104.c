//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LENGTH 10000
#define MUTATION_RATE 0.001

char nucleotides[] = {'A', 'C', 'G', 'T'};

char* generateRandomGenome() {
    char* genome = malloc((GENOME_LENGTH+1) * sizeof(char));
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        int index = rand() % 4;
        genome[i] = nucleotides[index];
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

void mutateGenome(char* genome) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        double mutationChance = (double)rand() / RAND_MAX;
        if (mutationChance < MUTATION_RATE) {
            int index = rand() % 4;
            genome[i] = nucleotides[index];
        }
    }
}

int main() {
    srand(time(NULL));
    char* originalGenome = generateRandomGenome();
    char* mutatedGenome = malloc((GENOME_LENGTH+1) * sizeof(char));
    strcpy(mutatedGenome, originalGenome);
    mutateGenome(mutatedGenome);
    
    printf("Original Genome:\n%s\n\n", originalGenome);
    printf("Mutated Genome:\n%s\n", mutatedGenome);
    
    free(originalGenome);
    free(mutatedGenome);
    
    return 0;
}