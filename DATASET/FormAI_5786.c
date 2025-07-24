//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random nucleotide from {A,C,G,T}
char generate_nucleotide()
{
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int random_index = rand() % 4;
    return nucleotides[random_index];
}

int main()
{
    // Get user input for size of genome sequence
    int sequence_size;
    printf("Enter size of genome sequence: ");
    scanf("%d", &sequence_size);
    
    // Allocate memory for the genome sequence
    char* genome_sequence = (char*) malloc(sequence_size * sizeof(char));
    
    // Generate random nucleotides and append to genome sequence
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < sequence_size; i++)
    {
        genome_sequence[i] = generate_nucleotide();
    }
    
    // Print the genome sequence
    printf("Genome Sequence: ");
    for (int i = 0; i < sequence_size; i++)
    {
        printf("%c", genome_sequence[i]);
    }
    
    // Free memory allocated for genome sequence
    free(genome_sequence);
    
    return 0;
}