//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LEN 1000
#define NUCLEOTIDES "ACTG"

int main()
{
    srand(time(NULL));

    char genome[GENOME_LEN+1] = {'\0'};

    // Generate a random genome sequence of length GENOME_LEN
    for(int i=0; i<GENOME_LEN; i++)
        genome[i] = NUCLEOTIDES[rand()%4];

    printf("Generated genome sequence: %s\n\n", genome);

    int freq[4] = {0}; // Frequency of each nucleotide (A, C, T, G)

    // Count the frequency of each nucleotide in the genome sequence
    for(int i=0; i<GENOME_LEN; i++)
    {
        switch(genome[i])
        {
            case 'A': freq[0]++; break;
            case 'C': freq[1]++; break;
            case 'T': freq[2]++; break;
            case 'G': freq[3]++; break;
            default: break;
        }
    }

    // Calculate the percentage of each nucleotide in the genome sequence
    float pct[4] = {0};
    for(int i=0; i<4; i++)
        pct[i] = (float)freq[i] / (float)GENOME_LEN * 100;

    // Print the frequency and percentage of each nucleotide
    printf("Nucleotide\tFrequency\tPercentage\n");
    printf("A\t\t%d\t\t%.2f%%\n", freq[0], pct[0]);
    printf("C\t\t%d\t\t%.2f%%\n", freq[1], pct[1]);
    printf("T\t\t%d\t\t%.2f%%\n", freq[2], pct[2]);
    printf("G\t\t%d\t\t%.2f%%\n", freq[3], pct[3]);

    return 0;
}