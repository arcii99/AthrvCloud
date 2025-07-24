//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char dna[100];
    int i;

    // Generate random DNA sequence
    for (i = 0; i < 100; i++)
    {
        int val = rand() % 4;
        if (val == 0)
            dna[i] = 'A';
        else if (val == 1)
            dna[i] = 'C';
        else if (val == 2)
            dna[i] = 'G';
        else
            dna[i] = 'T';
    }

    // Print out the DNA sequence
    for (i = 0; i < 100; i++)
    {
        printf("%c", dna[i]);
    }
    printf("\n");
    return 0;
}