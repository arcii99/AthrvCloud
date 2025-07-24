//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

int main()
{
    srand(time(NULL));

    char genome[GENOME_LENGTH];

    // Generate random DNA sequence
    for(int i = 0; i < GENOME_LENGTH; i++)
    {
        int random_num = rand() % 4;

        switch(random_num)
        {
            case 0:
                genome[i] = 'A';
                break;

            case 1:
                genome[i] = 'C';
                break;

            case 2:
                genome[i] = 'G';
                break;

            case 3:
                genome[i] = 'T';
                break;
        }
    }

    // Print DNA sequence
    printf("Original Genome:\n%s\n\n", genome);

    // Simulate genome sequencing
    int read_length = 50;
    int num_reads = GENOME_LENGTH / read_length;

    char reads[num_reads][read_length + 1];

    for(int i = 0; i < num_reads; i++)
    {
        int start_pos = i * read_length;

        for(int j = 0; j < read_length; j++)
        {
            reads[i][j] = genome[start_pos + j];
        }

        reads[i][read_length] = '\0'; // Null-terminate string
    }

    // Print sequencing results
    printf("Sequencing Results:\n");

    for(int i = 0; i < num_reads; i++)
    {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }

    return 0;
}