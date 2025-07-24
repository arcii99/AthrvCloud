//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_GENOME_LENGTH 1000
#define DNA_BASES "ACGT"

int main() {
    char genome[MAX_GENOME_LENGTH];
    int genome_length, i, j;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate genome length randomly between 500 and 1000
    genome_length = rand() % 501 + 500;

    // Generate genome sequence randomly using DNA bases: A, C, G, T
    for(i = 0; i < genome_length; i++) {
        // Select random DNA base
        j = rand() % 4;
        genome[i] = DNA_BASES[j];
    }

    // Print genome sequence
    printf("Generated Genome Sequence: \n%s\n", genome);

    // Simulate genome sequencing process
    int read_length = 100;
    int coverage = 10;
    int num_reads = (genome_length * coverage) / read_length;

    // Allocate memory for read sequences
    char** reads = malloc(num_reads * sizeof(char*));
    for(i = 0; i < num_reads; i++) {
        reads[i] = malloc((read_length + 1) * sizeof(char));
    }

    int starting_pos, k;
    for(i = 0; i < num_reads; i++) {
        // Select random starting position in genome
        starting_pos = rand() % (genome_length - read_length + 1);
        for(k = 0; k < read_length; k++) {
            reads[i][k] = genome[starting_pos + k];
        }
        reads[i][read_length] = '\0';
    }

    // Print reads
    printf("\nGenerated Reads: \n");
    for(i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    // Free memory
    for(i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}