//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length = 100;
    char genome[length];
    int nucleotide_counts[4] = {0};
    char nucleotides[] = {'A', 'C', 'G', 'T'};

    srand(time(NULL));

    // Generate random genome using A, C, G, T nucleotides
    for (int i = 0; i < length; i++)
    {
        int rand_num = rand() % 4;
        genome[i] = nucleotides[rand_num];
        printf("%c", genome[i]);

        // Keep track of nucleotide counts
        switch (genome[i])
        {
            case 'A':
                nucleotide_counts[0]++;
                break;
            case 'C':
                nucleotide_counts[1]++;
                break;
            case 'G':
                nucleotide_counts[2]++;
                break;
            case 'T':
                nucleotide_counts[3]++;
                break;
        }
    }

    printf("\nNucleotide Counts\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%c: %d\n", nucleotides[i], nucleotide_counts[i]);
    }

    return 0;
}