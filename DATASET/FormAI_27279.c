//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

void printGenome(char genome[]);
void randomizeGenome(char genome[]);
void mutateGenome(char genome[]);
void replicateGenome(char originalGenome[], char newGenome[]);
int compareGenomes(char genome1[], char genome2[]);

int main(void)
{
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Initialize the original genome
    char originalGenome[GENOME_LENGTH];
    randomizeGenome(originalGenome);
    
    // Print the original genome
    printf("Original genome:\n");
    printGenome(originalGenome);
    printf("\n");
    
    // Replicate the original genome and introduce mutations
    char newGenome[GENOME_LENGTH];
    replicateGenome(originalGenome, newGenome);
    mutateGenome(newGenome);
    
    // Print the new genome
    printf("New genome:\n");
    printGenome(newGenome);
    printf("\n");
    
    // Compare the two genomes
    if(compareGenomes(originalGenome, newGenome) == 0)
    {
        printf("The genomes are identical.\n");
    }
    else
    {
        printf("The genomes are different.\n");
    }
    
    return 0;
}

void printGenome(char genome[])
{
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        printf("%c", genome[i]);
    }
}

void randomizeGenome(char genome[])
{
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        // Choose a random nucleotide
        int nucleotide = rand() % 4;
        switch(nucleotide)
        {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
}

void mutateGenome(char genome[])
{
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        // Determine if this nucleotide should be mutated
        if((double) rand() / (double) RAND_MAX < MUTATION_RATE)
        {
            // Choose a random nucleotide other than the current one
            char nucleotide;
            do
            {
                int index = rand() % 4;
                switch(index)
                {
                    case 0:
                        nucleotide = 'A';
                        break;
                    case 1:
                        nucleotide = 'C';
                        break;
                    case 2:
                        nucleotide = 'G';
                        break;
                    case 3:
                        nucleotide = 'T';
                        break;
                }
            } while(nucleotide == genome[i]);
            
            // Mutate the nucleotide
            genome[i] = nucleotide;
        }
    }
}

void replicateGenome(char originalGenome[], char newGenome[])
{
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        // Copy the original nucleotide to the new genome
        newGenome[i] = originalGenome[i];
    }
}

int compareGenomes(char genome1[], char genome2[])
{
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        if(genome1[i] != genome2[i])
        {
            return 1;
        }
    }
    return 0;
}