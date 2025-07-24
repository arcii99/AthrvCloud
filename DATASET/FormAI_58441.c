//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with current time
    
    int genome_length = 100;
    int max_nucleotide = 4;
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    
    // dynamically allocate memory for genome sequence
    char *genome = (char*) malloc(sizeof(char) * genome_length);
    
    // generate random genome sequence
    for(int i=0; i<genome_length; i++)
    {
        int index = rand() % max_nucleotide;
        genome[i] = nucleotides[index];
    }
    
    // print the genome sequence
    printf("Genome Sequence: ");
    for(int i=0; i<genome_length; i++)
        printf("%c ", genome[i]);
    printf("\n");
    
    // free the dynamically allocated memory
    free(genome);
    
    return 0;
}