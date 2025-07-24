//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LEN 1000
#define MAX_MUTATION 5

char dna[DNA_LEN];
char mutated_dna[DNA_LEN];
char bases[] = {'A', 'C', 'G', 'T'};

// Function to generate random DNA sequence
void generate_dna()
{
    int i;
    for(i=0; i<DNA_LEN; i++)
        dna[i] = bases[rand()%4];
}

// Function to mutate DNA sequence
void mutate_dna()
{
    int i, count, idx, mut;
    for(i=0; i<DNA_LEN; i++)
        mutated_dna[i] = dna[i];
    
    count = rand()%(MAX_MUTATION+1);
    for(i=0; i<count; i++)
    {
        idx = rand()%DNA_LEN;
        mut = rand()%4;
        mutated_dna[idx] = bases[mut];
    }
}

int main()
{
    srand(time(0));
    generate_dna();
    printf("Original DNA sequence: %s\n", dna);
    
    mutate_dna();
    printf("Mutated DNA sequence: %s\n", mutated_dna);

    return 0;
}