//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define GENOME_LENGTH 10
#define MUTATION_PROBABILITY 0.005

// Function to randomly generate nucleotide bases
char generate_nucleotide()
{
    int r = rand() % 4; // generate random number between 0 and 3
    switch(r)
    {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return '\0';
    }
}

// Function to simulate mutations
char mutate_nucleotide(char original_base)
{
    if((double)rand() / RAND_MAX < MUTATION_PROBABILITY) // if random number is less than the mutation probability
    {
        // randomly change the nucleotide base
        char new_base = generate_nucleotide();
        while(new_base == original_base) // make sure the new base is different from the original base
            new_base = generate_nucleotide();
        return new_base;
    }
    else // otherwise, keep the original base
        return original_base;
}

int main()
{
    srand(time(NULL)); // initialize random seed

    char genome[GENOME_LENGTH]; // initialize genome sequence

    // generate initial genome sequence
    for(int i = 0; i < GENOME_LENGTH; i++)
        genome[i] = generate_nucleotide();

    // output initial genome sequence
    printf("Initial Genome Sequence:\n");
    for(int i = 0; i < GENOME_LENGTH; i++)
        printf("%c ", genome[i]);
    printf("\n");

    // simulate mutations
    for(int i = 0; i < GENOME_LENGTH; i++)
        genome[i] = mutate_nucleotide(genome[i]);

    // output mutated genome sequence
    printf("Mutated Genome Sequence:\n");
    for(int i = 0; i < GENOME_LENGTH; i++)
        printf("%c ", genome[i]);
    printf("\n");

    return 0;
}