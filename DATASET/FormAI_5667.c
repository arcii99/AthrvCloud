//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // Define length of genome sequence
#define MUTATION_PROBABILITY 0.01 // Define probability of mutation occurring

// Function to generate a random nucleotide
char generate_nucleotide()
{
    int random_num = rand() % 4;

    switch(random_num)
    {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator with current time

    char genome[GENOME_LENGTH]; // Define the genome sequence array
    int i;

    // Generate the initial genome sequence
    for(i = 0; i < GENOME_LENGTH; i++)
    {
        genome[i] = generate_nucleotide();
    }

    // Print the initial genome sequence
    printf("Initial genome sequence:\n");
    for(i = 0; i < GENOME_LENGTH; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n\n");

    // Simulate the sequencing process
    for(i = 0; i < GENOME_LENGTH; i++)
    {
        if(((double)rand() / RAND_MAX) < MUTATION_PROBABILITY)
        {
            // Generate a random nucleotide to replace the current one
            genome[i] = generate_nucleotide();
        }
    }

    // Print the final genome sequence after sequencing process
    printf("Final genome sequence:\n");
    for(i = 0; i < GENOME_LENGTH; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");

    return 0;
}