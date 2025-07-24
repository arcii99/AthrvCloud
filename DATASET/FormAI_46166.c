//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int genome_length = 100000;
    int base_count[4] = {0}; // A, T, C, G
    char bases[4] = {'A', 'T', 'C', 'G'};
    char *genome = (char*)malloc(sizeof(char)*genome_length);
    
    // Generate random genome
    srand(time(NULL));
    for (int i = 0; i < genome_length; i++)
    {
        int rand_int = rand() % 4; // Generate random integer from 0 to 3
        genome[i] = bases[rand_int]; // Assign base to genome
        base_count[rand_int]++; // Record base count
    }
    
    // Print genome and base count
    for (int i = 0; i < genome_length; i++)
    {
        printf("%c", genome[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%c: %d\n", bases[i], base_count[i]);
    }
    
    // Free memory
    free(genome);
    
    return 0;
}