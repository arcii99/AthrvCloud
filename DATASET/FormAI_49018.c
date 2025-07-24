//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    char nucleotides[] = {'A', 'C', 'G', 'T'}; // array of possible nucleotides
    int sequence_length = 100; // specify desired sequence length
    char sequence[sequence_length + 1]; // initialize char array for sequence

    for (int i = 0; i < sequence_length; i++)
    {
        int random_index = rand() % 4; // select random index from 0-3
        sequence[i] = nucleotides[random_index]; // add corresponding nucleotide to sequence
    }

    sequence[sequence_length] = '\0'; // add null terminator to end of sequence

    printf("Generated sequence: %s\n", sequence); // print generated sequence

    return 0;
}