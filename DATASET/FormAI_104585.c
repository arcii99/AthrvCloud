//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include<stdio.h>

int main()
{
    char genome[50];
    int i, j, count;
    printf("Enter the genome sequence: ");
    gets(genome);
    printf("Genome sequence entered: %s\n", genome);
    
    //counting the length of the genome sequence
    for(i=0; genome[i]!='\0'; i++);
    count = i;
    
    //generating random sequence of nucleotides
    char nucleotides[4] = {'A', 'T', 'C', 'G'};
    char sequence[count];
    for(i=0; i<count; i++)
    {
        j = rand()%4;
        sequence[i] = nucleotides[j];
    }
    printf("Random sequence generated: %s\n", sequence);
    
    //comparing the genome sequence with the random sequence
    int match=0, mismatch=0;
    for(i=0; i<count; i++)
    {
        if(genome[i] == sequence[i])
            match++;
        else
            mismatch++;
    }
    printf("Match: %d\n", match);
    printf("Mismatch: %d\n", mismatch);
    
    return 0;
}