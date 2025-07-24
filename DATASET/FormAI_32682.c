//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 20
#define MAX_MUTATIONS 3

/* Function to Generate Random DNA Sequence */
void generateSequence(char sequence[])
{
    char nucleotides[] = "ATCG";
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[SEQUENCE_LENGTH] = '\0';
}

/* Function to Mutate DNA Sequence Randomly */
void mutateSequence(char sequence[], int mutations)
{
    int mutatedIndexes[MAX_MUTATIONS];
    for (int i = 0; i < mutations; i++)
    {
        int index = rand() % SEQUENCE_LENGTH;
        mutatedIndexes[i] = index;
        char currentNucleotide = sequence[index];
        switch (currentNucleotide)
        {
            case 'A': sequence[index] = 'T'; break;
            case 'T': sequence[index] = 'A'; break;
            case 'C': sequence[index] = 'G'; break;
            case 'G': sequence[index] = 'C'; break;
        }
    }
    printf("Mutated indexes: ");
    for (int i = 0; i < mutations; i++)
    {
        printf("%d ", mutatedIndexes[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // Setting seed for random number generation

    char sequence[SEQUENCE_LENGTH + 1];
    generateSequence(sequence);
    printf("Original Sequence: %s\n", sequence);

    int mutations = rand() % (MAX_MUTATIONS + 1); // Generating random number of mutations
    if (mutations > 0)
    {
        mutateSequence(sequence, mutations);
        printf("Mutated Sequence: %s\n", sequence);
    }
    else
    {
        printf("No mutations.\n");
    }

    return 0;
}