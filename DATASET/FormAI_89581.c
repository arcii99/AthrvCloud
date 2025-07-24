//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>

int main()
{
    int dna_length = 1000;
    char dna_sequence[dna_length];

    // Simulate the process of DNA sequencing
    for (int i = 0; i < dna_length; i++)
    {
        int nucleotide = rand() % 4;
        switch (nucleotide)
        {
            case 0:
                dna_sequence[i] = 'A';
                break;
            case 1:
                dna_sequence[i] = 'C';
                break;
            case 2:
                dna_sequence[i] = 'G';
                break;
            case 3:
                dna_sequence[i] = 'T';
                break;
            default:
                break;
        }
    }

    // Print out the DNA sequence
    printf("DNA Sequence: ");
    for (int i = 0; i < dna_length; i++)
    {
        printf("%c", dna_sequence[i]);
    }
    printf("\n");

    return 0;
}