//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000

char nucleotides[] = {'A', 'C', 'G', 'T'};

int main()
{
    srand(time(NULL));   // seeding random number generator
    
    char genome[GENOME_LENGTH];
    
    // generating random genome sequence
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        genome[i] = nucleotides[rand() % 4];
    }

    // printing the genome sequence
    for(int i=0; i<GENOME_LENGTH; i++)
    {
        printf("%c", genome[i]);
    }
    
    // generating random subsequence to match in genome
    int subseq_length = rand() % 100 + 50;   // subsequence length of 50 to 150 nucleotides
    char subseq[subseq_length];
    
    for(int i=0; i<subseq_length; i++)
    {
        subseq[i] = nucleotides[rand() % 4];
    }
    
    // printing the subsequence to match
    printf("\n\nSubsequence to match: ");
    for(int i=0; i<subseq_length; i++)
    {
        printf("%c", subseq[i]);
    }
    printf("\n\n");
    
    // matching the subsequence in genome
    int match_start = -1;
    for(int i=0; i<GENOME_LENGTH-subseq_length+1; i++)
    {
        int j;
        for(j=0; j<subseq_length; j++)
        {
            if(genome[i+j] != subseq[j])
            {
                break;
            }
        }
        
        if(j == subseq_length)
        {
            match_start = i;
            break;
        }
    }
    
    // printing the match result
    if(match_start != -1)
    {
        printf("Subsequence match found at position %d in genome.", match_start+1);
    }
    else
    {
        printf("Subsequence match not found in genome.");
    }
    
    return 0;
}