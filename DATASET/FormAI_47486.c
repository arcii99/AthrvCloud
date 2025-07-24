//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

int main()
{
    // Seeding the random number generator
    srand(time(NULL));

    // Creating an array of DNA bases
    char dna_bases[] = {'A', 'C', 'G', 'T'};

    // Initializing the genome with random bases
    char genome[GENOME_LENGTH];
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        int base_index = rand()%4;
        genome[i] = dna_bases[base_index];
    }

    // Printing the generated genome
    printf("Generated Genome:\n");
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n\n");

    // Simulating Genome Sequencing
    // Performing 10 rounds of sequencing
    int num_rounds = 10;
    for(int round=1; round<=num_rounds; round++)
    {
        printf("Round %d:\n", round);

        // Creating a variable to keep track of the number of errors introduced
        int num_errors = 0;

        // Creating a copy of the original genome
        char genome_copy[GENOME_LENGTH];
        for(int i=0; i<GENOME_LENGTH; i++)
        {
            genome_copy[i] = genome[i];
        }

        // Introducing Errors
        for(int i=0; i<GENOME_LENGTH; i++)
        {
            // Generating a random number between 0 and 99
            int random_num = rand()%100;
            if(random_num < 10) // 10% chance of introducing an error
            {
                int base_index = rand()%3;
                genome_copy[i] = dna_bases[base_index];
                num_errors++;
            }
        }

        // Printing the number of errors introduced in this round
        printf("Number of Errors Introduced: %d\n", num_errors);

        // Printing the Sequenced Genome
        printf("Sequenced Genome:\n");
        for(int i=0; i<GENOME_LENGTH; i++)
        {
            printf("%c", genome_copy[i]);
        }
        printf("\n\n");
    }

    return 0;
}