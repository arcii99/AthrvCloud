//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    int genome_length = 1000; // length of the genome sequence
    char genome[genome_length+1]; // genome sequence string
    genome[genome_length] = '\0'; // end the string with '\0'

    // Seed the random number generator
    srand(time(NULL));

    // Generate the genome sequence
    for (int i=0; i<genome_length; i++) {
        int random_index = rand() % 4; // pick a random nucleotide
        genome[i] = nucleotides[random_index]; // add it to the genome sequence
    }

    // Print the genome sequence
    printf("Genome Sequence:\n%s\n", genome);

    return 0;
}