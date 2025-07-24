//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 10
#define NUM_BASES 4

char generateRandomBase()
{
    char bases[] = {'A', 'C', 'G', 'T'};
    int randomIndex = rand() % NUM_BASES;
    return bases[randomIndex];
}

void generateSequence(char sequence[])
{
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        sequence[i] = generateRandomBase();
    }
    sequence[SEQUENCE_LENGTH] = '\0';
}

void printSequence(char sequence[])
{
    printf("%s\n", sequence);
}

void mutateSequence(char sequence[])
{
    int numMutations = rand() % SEQUENCE_LENGTH;
    for (int i = 0; i < numMutations; i++)
    {
        int index = rand() % SEQUENCE_LENGTH;
        sequence[index] = generateRandomBase();
    }
}

int main()
{
    srand(time(NULL));
    
    char sequence[SEQUENCE_LENGTH + 1];
    generateSequence(sequence);
    printf("Original sequence: ");
    printSequence(sequence);
    
    mutateSequence(sequence);
    printf("Mutated sequence: ");
    printSequence(sequence);
    
    return 0;
}