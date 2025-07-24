//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100000 // Maximum genome size
#define MAX_MUTATIONS 1000 // Maximum number of mutations allowed
#define MUTATION_PROBABILITY 0.05f // Probability of a mutation occurring

typedef struct 
{
    int genome[GENOME_SIZE]; // The genome as an array of integers
    int num_mutations; // Number of mutations made so far
} Genome;

void generate_genome(Genome* genome)
{
    // Fill the genome with random numbers between 0 and 3
    srand(time(NULL));
    for (int i = 0; i < GENOME_SIZE; ++i) 
    {
        genome->genome[i] = rand() % 4;
    }
    genome->num_mutations = 0;
}

void mutate_genome(Genome* genome)
{
    // Check if a mutation should occur
    float mutation_chance = (float)rand() / (float)RAND_MAX;
    if (mutation_chance > MUTATION_PROBABILITY) return;

    // Choose a random position in the genome to mutate
    int mutation_pos = rand() % GENOME_SIZE;

    // Choose a random mutation type: deletion, insertion, or substitution
    int mutation_type = rand() % 3;

    // Perform the mutation
    switch (mutation_type) 
    {
        case 0: // Deletion
            if (mutation_pos < GENOME_SIZE - 1) 
            {
                for (int i = mutation_pos; i < GENOME_SIZE - 1; ++i) 
                {
                    genome->genome[i] = genome->genome[i+1];
                }
            }
            break;

        case 1: // Insertion
            if (mutation_pos < GENOME_SIZE - 1) 
            {
                for (int i = GENOME_SIZE - 1; i > mutation_pos; --i) 
                {
                    genome->genome[i] = genome->genome[i-1];
                }
                genome->genome[mutation_pos] = rand() % 4;
            }
            break;

        case 2: // Substitution
            genome->genome[mutation_pos] = rand() % 4;
            break;
    }

    // Update the number of mutations
    genome->num_mutations++;
}

int main()
{
    Genome genome;
    generate_genome(&genome);

    printf("Original genome:\n[ ");
    for (int i = 0; i < GENOME_SIZE; ++i) 
    {
        printf("%d ", genome.genome[i]);
    }
    printf("]\n");

    int num_mutations = rand() % (MAX_MUTATIONS + 1);
    for (int i = 0; i < num_mutations; ++i) 
    {
        mutate_genome(&genome);
    }

    printf("Mutated genome (with %d mutations):\n[ ", genome.num_mutations);
    for (int i = 0; i < GENOME_SIZE; ++i) 
    {
        printf("%d ", genome.genome[i]);
    }
    printf("]\n");

    return 0;
}