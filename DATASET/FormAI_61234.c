//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQ_LEN 100 // Length of genome sequence
#define MUT_RATE 0.05 // Mutation rate for genome sequence

void generate_sequence(char *sequence);
void mutate_sequence(char *sequence, double mut_rate);
void print_sequence(char *sequence);

int main()
{
    srand(time(NULL)); // Seed the random number generator

    char genome_sequence[SEQ_LEN + 1]; // Add one for null character

    generate_sequence(genome_sequence);
    printf("Generated genome sequence:\n");
    print_sequence(genome_sequence);

    mutate_sequence(genome_sequence, MUT_RATE);
    printf("Mutated genome sequence:\n");
    print_sequence(genome_sequence);

    return 0;
}

// Generates a random DNA sequence
void generate_sequence(char *sequence)
{
    const char dna[] = "ATCG";
    int i;

    for (i = 0; i < SEQ_LEN; i++)
    {
        int rand_index = rand() % 4;
        sequence[i] = dna[rand_index];
    }

    sequence[SEQ_LEN] = '\0';
}

// Randomly mutates the genome sequence
void mutate_sequence(char *sequence, double mut_rate)
{
    int i;

    for (i = 0; i < SEQ_LEN; i++)
    {
        double rand_num = ((double) rand() / RAND_MAX);

        if (rand_num < mut_rate)
        {
            switch (sequence[i])
            {
                case 'A':
                    sequence[i] = 'T';
                    break;
                case 'T':
                    sequence[i] = 'A';
                    break;
                case 'C':
                    sequence[i] = 'G';
                    break;
                case 'G':
                    sequence[i] = 'C';
                    break;
            }
        }
    }
}

// Prints the genome sequence
void print_sequence(char *sequence)
{
    int i;

    for (i = 0; i < SEQ_LEN; i++)
    {
        printf("%c", sequence[i]);
    }

    printf("\n");
}