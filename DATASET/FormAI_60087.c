//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random DNA sequence of given length
char *generateSequence(int length)
{
    char *sequence = (char *)malloc(length + 1);

    // generate random DNA sequence
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++)
    {
        int randomIndex = rand() % 4;
        sequence[i] = nucleotides[randomIndex];
    }
    sequence[length] = '\0';
    return sequence;
}

// function to print DNA sequence
void printSequence(char *sequence)
{
    printf("%s\n", sequence);
}

int main()
{
    srand(time(NULL));

    int length = 10;

    // generate two random DNA sequences
    char *sequence1 = generateSequence(length);
    char *sequence2 = generateSequence(length);

    // print the generated DNA sequences
    printf("Sequence 1: ");
    printSequence(sequence1);
    printf("Sequence 2: ");
    printSequence(sequence2);

    // free memory used by DNA sequences
    free(sequence1);
    free(sequence2);

    return 0;
}