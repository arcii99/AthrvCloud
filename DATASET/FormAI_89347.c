//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); // seeding random number generator with current time

    // declaring variables
    int genome_length = 1000;
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    char genome[1000];

    // generating random genome sequence
    for(int i = 0; i < genome_length; i++){
        int random_index = rand() % 4; // generating random index between 0 to 3
        char nucleotide = nucleotides[random_index];
        genome[i] = nucleotide;
    }

    // printing original genome sequence
    printf("Original genome sequence: ");
    for(int i = 0; i < genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    // simulating mutations in the genome sequence
    int num_mutations = 5;
    for(int i = 0; i < num_mutations; i++){
        int random_index = rand() % genome_length; // generating random index between 0 to 999
        int random_nucleotide = rand() % 4; // generating random nucleotide between 0 to 3
        char mutated_nucleotide = nucleotides[random_nucleotide];
        genome[random_index] = mutated_nucleotide;
    }

    // printing mutated genome sequence
    printf("Mutated genome sequence: ");
    for(int i = 0; i < genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}