//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a random nucleotide generator
char rand_nucleotide(){
    char nucleotide[4] = {'A', 'T', 'C', 'G'};
    int rand_num = rand() % 4;
    return nucleotide[rand_num];
}

int main(){
    // Seed the random generator
    srand(time(NULL));

    // Define the length of the genome and allocate memory
    int genome_length = 1000000;
    char* genome = (char*) malloc(genome_length * sizeof(char));

    // Generate the genome
    for (int i = 0; i < genome_length; i++){
        genome[i] = rand_nucleotide();
    }

    // Print the first 100 nucleotides
    printf("First 100 nucleotides: ");
    for (int i = 0; i < 100; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    // Print the last 100 nucleotides
    printf("Last 100 nucleotides: ");
    for (int i = genome_length-100; i < genome_length; i++){
        printf("%c", genome[i]);
    }
    printf("\n");

    // Free the memory used by the genome
    free(genome);

    return 0;
}