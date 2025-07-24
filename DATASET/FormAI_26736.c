//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize the random number generator
    srand((unsigned int) time(NULL));

    // Define the genome sequence
    char* genome_sequence = "ATCG";

    // Define the length of the genome sequence
    int genome_length = 1000;

    // Create the genome array
    char genome[genome_length + 1];

    // Generate the genome sequence
    for (int i = 0; i < genome_length; i++)
    {
        int rand_num = rand() % 4;
        genome[i] = genome_sequence[rand_num];
    }

    // Terminate the genome string
    genome[genome_length] = '\0';

    // Print the genome sequence
    printf("Genome Sequence:\n%s\n", genome);

    return 0;
}