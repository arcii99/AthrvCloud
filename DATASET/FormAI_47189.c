//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define MAX_MUTATIONS 10
#define MUTATION_PROBABILITY 0.1

// function prototypes
void generateSequence(char sequence[]);
void printSequence(char sequence[]);
void mutateSequence(char sequence[], int numMutations);
char randomBase();

// main function
int main()
{
    char sequence[SEQUENCE_LENGTH]; // initialize empty sequence
    srand(time(NULL)); // seed RNG with current time

    // generate and print original sequence
    generateSequence(sequence);
    printf("Original sequence:\n");
    printSequence(sequence);

    // randomly mutate sequence and print
    int numMutations = rand() % (MAX_MUTATIONS + 1); // up to MAX_MUTATIONS mutations allowed
    mutateSequence(sequence, numMutations);
    printf("Mutated sequence (with %d mutations):\n", numMutations);
    printSequence(sequence);

    return 0;
}

// function to generate a random DNA sequence
void generateSequence(char sequence[])
{
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        sequence[i] = randomBase(); // randomly select A, T, C, or G for each base
    }
}

// function to print a DNA sequence
void printSequence(char sequence[])
{
    for (int i = 0; i < SEQUENCE_LENGTH; i++)
    {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// function to randomly mutate a DNA sequence
void mutateSequence(char sequence[], int numMutations)
{
    for (int i = 0; i < numMutations; i++)
    {
        int index = rand() % SEQUENCE_LENGTH; // select a random base to mutate
        if ((double) rand() / RAND_MAX < MUTATION_PROBABILITY)
        {
            sequence[index] = randomBase(); // randomly select a new base to replace the original
        }
    }
}

// function to randomly select a base (A, T, C, or G)
char randomBase()
{
    int randNum = rand() % 4;
    switch (randNum)
    {
        case 0:
            return 'A';
        case 1:
            return 'T';
        case 2:
            return 'C';
        case 3:
            return 'G';
        default:
            return 'N'; // in case something goes wrong
    }
}