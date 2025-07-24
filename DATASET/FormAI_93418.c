//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_SIZE 1000
#define MUTATION_PROBABILITY 0.01
#define ERROR_PROBABILITY 0.1

void mutate(char *genome, int size, float mutation_probability);
void add_error(char *genome, int size, float error_probability);
void print_genome(char *genome, int size);

int main()
{
    char genome[GENOME_SIZE];
    srand(time(0));
    
    //generate random genome
    for(int i=0; i<GENOME_SIZE; i++)
        genome[i] = rand() % 4; //A=0, C=1, G=2, T=3
        
    printf("Initial genome: ");
    print_genome(genome, GENOME_SIZE);
    
    //mutate genome
    mutate(genome, GENOME_SIZE, MUTATION_PROBABILITY);
    printf("Mutated genome: ");
    print_genome(genome, GENOME_SIZE);
    
    //add errors to genome
    add_error(genome, GENOME_SIZE, ERROR_PROBABILITY);
    printf("Genome with errors: ");
    print_genome(genome, GENOME_SIZE);
    
    return 0;
}

void mutate(char *genome, int size, float mutation_probability)
{
    for(int i=0; i<size; i++)
    {
        float r = ((float) rand() / (RAND_MAX));
        if(r < mutation_probability)
            genome[i] = rand() % 4; //A=0, C=1, G=2, T=3
    }
}

void add_error(char *genome, int size, float error_probability)
{
    for(int i=0; i<size; i++)
    {
        float r = ((float) rand() / (RAND_MAX));
        if(r < error_probability)
        {
            int e = rand() % 4; //add a random error
            if(e == genome[i]) //make sure it's not the same as the original nucleotide
                e = (e + 1) % 4;
            genome[i] = e;
        }
    }
}

void print_genome(char *genome, int size)
{
    for(int i=0; i<size; i++)
    {
        switch(genome[i])
        {
            case 0: printf("A"); break;
            case 1: printf("C"); break;
            case 2: printf("G"); break;
            case 3: printf("T"); break;
        }
    }
    printf("\n");
}