//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUCLEOTIDES "ACGT"

int main() {
    srand(time(NULL)); // initialize random seed

    int genome_length;
    printf("Enter the length of the genome: ");
    scanf("%d", &genome_length);

    char *genome = malloc(sizeof(char) * (genome_length + 1)); // allocate memory for genome

    printf("Generating genome...");

    for (int i = 0; i < genome_length; i++) {
        int random_index = rand() % 4; // generate random index from 0 to 3 for A, C, G, or T
        genome[i] = NUCLEOTIDES[random_index];
    }

    genome[genome_length] = '\0'; // add null character to terminate string

    printf("Done!\n");

    printf("Genome sequence: %s\n", genome);

    free(genome); // free allocated memory

    return 0;
}