//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASES "ATCG"

int main()
{
    int length, i, j;
    char *sequence;

    // Generate random length between 50 and 100
    srand(time(NULL));
    length = rand() % 51 + 50;

    // Allocate memory for sequence
    sequence = (char*) malloc((length + 1) * sizeof(char));

    if(sequence == NULL)
    {
        printf("Error: Unable to allocate memory.");
        exit(1);
    }

    // Generate random sequence
    printf("Generating random sequence...\n\n");

    for(i = 0; i < length; i++)
    {
        j = rand() % 4;
        sequence[i] = BASES[j];
    }

    sequence[length] = '\0';

    // Print sequence
    printf("Random Sequence: %s\n\n", sequence);

    // Print sequence in FASTA format
    printf(">Random Sequence\n%s\n\n", sequence);

    printf("Sequencing in progress...\n\n");

    // Print sequencing results
    for(i = 0; i < length; i++)
    {
        printf("%c", sequence[i]);

        if(i % 10 == 9)
        {
            printf(" ");
        }

        if(i % 50 == 49)
        {
            printf("\n");
        }
    }

    printf("\n\nSequencing Complete!");

    // Free memory
    free(sequence);

    return 0;
}