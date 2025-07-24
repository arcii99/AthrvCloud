//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENOME_SIZE 1000

char nucleotides[] = {'A', 'C', 'G', 'T'};

int main() {
    int genome_size;
    char genome[MAX_GENOME_SIZE];

    // Prompt user for genome size
    printf("Enter genome size:");
    scanf("%d", &genome_size);

    // Generate random genome
    for(int i=0; i<genome_size; i++) {
        genome[i] = nucleotides[rand()%4];
    }

    // Print generated genome
    printf("Generated genome:\n");
    for(int i=0; i<genome_size; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // Simulate noise in genome
    int num_noise;
    printf("Enter number of noise values to simulate:");
    scanf("%d", &num_noise);

    for(int i=0; i<num_noise; i++) {
        int rand_idx = rand()%genome_size;
        genome[rand_idx] = nucleotides[rand()%4];
    }

    // Print genome after noise simulation
    printf("Genome after noise simulation:\n");
    for(int i=0; i<genome_size; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}