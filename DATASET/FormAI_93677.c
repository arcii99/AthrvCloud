//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEQ_LENGTH 100

char nucleotides[5] = {'A', 'C', 'G', 'T', 'X'};

// Function to generate a random string sequence of DNA
char *generate_sequence(int length)
{
    char *sequence = (char *)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++)
    {
        sequence[i] = nucleotides[rand() % 5];
    }
    return sequence;
}

// Function to simulate genome sequencing (adding errors)
void simulate_sequencing(char *sequence, int length, float error_rate)
{
    int i;
    for (i = 0; i < length; i++)
    {
        float rand_num = (float)rand() / RAND_MAX;
        if (rand_num < error_rate)
        {
            sequence[i] = nucleotides[rand() % 5];
        }
    }
}

int main()
{
    int seq_length = MAX_SEQ_LENGTH;
    char *sequence = generate_sequence(seq_length);

    float error_rate = 0.05;
    simulate_sequencing(sequence, seq_length, error_rate);

    printf("Original Sequence: %s\n", sequence);

    return 0;
}