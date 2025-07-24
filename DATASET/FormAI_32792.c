//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Define the four nucleotides
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    
    // Define the length of the genome
    int genome_length = 100;
    
    // Generate the random genome
    char genome[genome_length];
    for (int i = 0; i < genome_length; i++) {
        int random_index = rand() % 4;
        genome[i] = nucleotides[random_index];
    }
    
    // Print the genome
    printf("Genome: ");
    for (int i = 0; i < genome_length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // Define the number of reads to simulate
    int num_reads = 10;
    
    // Define the length of each read
    int read_length = 10;
    
    // Simulate the reads
    for (int i = 0; i < num_reads; i++) {
        // Generate a random start index for the read
        int start_index = rand() % (genome_length - read_length + 1);
        
        // Print the read
        printf("Read %d: ", i + 1);
        for (int j = 0; j < read_length; j++) {
            printf("%c", genome[start_index + j]);
        }
        printf("\n");
    }
    
    return 0;
}