//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000 // length of genome
#define NUCLEOTIDE_NUM 4
#define MUTATION_RATE 0.01 // probability of mutation

char nucleotides[NUCLEOTIDE_NUM] = {'A', 'C', 'G', 'T'};

int main()
{
    srand(time(NULL)); // seed the random number generator

    char genome[LENGTH];

    // generate random genome sequence
    for (int i = 0; i < LENGTH; i++)
    {
        int rand_index = rand() % NUCLEOTIDE_NUM; // generate random nucleotide index
        genome[i] = nucleotides[rand_index]; // insert random nucleotide into genome
    }

    printf("Original genome sequence:\n");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%c", genome[i]); // print original genome sequence
    }
    printf("\n");

    // simulate mutations in genome sequence
    for (int i = 0; i < LENGTH; i++)
    {
        double rand_num = (double)rand() / RAND_MAX; // generate random number between 0 and 1
        
        if (rand_num < MUTATION_RATE)
        {
            int rand_index = rand() % NUCLEOTIDE_NUM; // generate random nucleotide index
            genome[i] = nucleotides[rand_index]; // mutate nucleotide in genome
        }
    }

    printf("Mutated genome sequence:\n");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%c", genome[i]); // print mutated genome sequence
    }
    printf("\n");

    return 0;
}