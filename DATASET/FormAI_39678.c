//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    char dna[] = {'A', 'C', 'G', 'T'};
    int num_bases = 100;
    
    printf("Generating random DNA sequence...\n");
    for(int i = 0; i < num_bases; i++)
    {
        int random_base = rand() % 4; //choose a random index from 0-3
        printf("%c", dna[random_base]); //print the corresponding base
    }
    printf("\n");
    
    return 0;
}