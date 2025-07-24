//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
// Welcome to the C Genome Sequencing Simulator!

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define GENOME_SIZE 100 // Define genome size

char nucleotides[] = {'A','C','G','T'}; // Define array of nucleotides

int main()
{
    srand(time(NULL)); // Initialize random number generator

    char genome[GENOME_SIZE + 1]; // Create genome array to store nucleotides
    genome[GENOME_SIZE] = '\0'; // Add null terminator to end of genome string

    printf("Generating random genome sequence...\n");

    for(int i = 0; i < GENOME_SIZE; i++)
    {
        int index = rand() % 4; // Randomly select nucleotide index
        genome[i] = nucleotides[index]; // Add selected nucleotide to genome array
    }

    printf("Genome sequence generated!\n\n");

    printf("Genome sequence: %s\n\n",genome); // Print generated genome sequence

    // Add mutation(s) to genome sequence
    int numMutations = rand() % 3 + 1; // Randomly select number of mutations to add

    printf("Adding %d mutation(s) to genome sequence...\n",numMutations);

    for(int i = 0; i < numMutations; i++)
    {
        int mutationIndex = rand() % GENOME_SIZE; // Randomly select index to mutate

        int newIndex = rand() % 4; // Randomly select new nucleotide index
        while(nucleotides[newIndex] == genome[mutationIndex]) // Make sure new nucleotide is different than old nucleotide
        {
            newIndex = rand() % 4;
        }

        genome[mutationIndex] = nucleotides[newIndex]; // Replace old nucleotide with new nucleotide
    }

    printf("Mutation(s) added!\n\n");

    printf("Mutated genome sequence: %s\n\n",genome); // Print mutated genome sequence

    // Search for specific sequence in mutated genome
    char searchSequence[] = {'A','G','T','C'}; // Define specific sequence to search for
    int searchSequenceSize = sizeof(searchSequence)/sizeof(searchSequence[0]); // Calculate size of specific sequence array

    printf("Searching for specific sequence in mutated genome sequence...\n");

    for(int i = 0; i < GENOME_SIZE - searchSequenceSize; i++) // Loop through genome sequence
    {
        int found = 1; // Assume specific sequence is found
        for(int j = 0; j < searchSequenceSize; j++) // Loop through specific sequence array
        {
            if(genome[i + j] != searchSequence[j]) // If characters do not match, specific sequence is not found
            {
                found = 0;
                break;
            }
        }
        if(found == 1) // If specific sequence is found, print message and break loop
        {
            printf("Specific sequence found at index %d in mutated genome sequence!\n\n",i);
            break;
        }
    }

    printf("Simulation complete!\n");

    return 0;
}