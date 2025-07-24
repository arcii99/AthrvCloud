//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_SEQ 150
#define NUCLEO_A 'A'
#define NUCLEO_C 'C'
#define NUCLEO_G 'G'
#define NUCLEO_T 'T'

char generate_nucleotide()
{
    char nucleotide = 0;
    int random_number = rand() % 4;
    
    switch(random_number)
    {
        case 0:
            nucleotide = NUCLEO_A;
            break;
        case 1:
            nucleotide = NUCLEO_C;
            break;
        case 2:
            nucleotide = NUCLEO_G;
            break;
        case 3:
            nucleotide = NUCLEO_T;
            break;
        default:
            break;
    }

    return nucleotide;
}

void generate_sequence(char* sequence)
{
    int i;
    for (i = 0; i < DNA_SEQ; i++)
    {
        sequence[i] = generate_nucleotide();
    }
    sequence[i] = '\0';
}

void compare_sequences(const char* sequence1, const char* sequence2)
{
    printf("Comparing sequences...\n");

    int i, differences = 0;
    for (i = 0; i < DNA_SEQ; i++)
    {
        if(sequence1[i] != sequence2[i])
        {
            printf("Nucleotide %d differs: %c vs %c\n", i+1, sequence1[i], sequence2[i]);
            differences++;
        }
    }

    if(differences == 0)
    {
        printf("Sequences match! 100%% similarity.\n");
    }
    else
    {
        float similarity = 100 - ((float) differences / DNA_SEQ * 100);
        printf("Sequences are %f%% similar.\n", similarity);
    }
}

int main()
{
    srand(time(NULL));

    char sequence1[DNA_SEQ + 1], sequence2[DNA_SEQ + 1];

    printf("Generating first sequence...\n");
    generate_sequence(sequence1);
    printf("First sequence generated: %s\n", sequence1);

    printf("Generating second sequence...\n");
    generate_sequence(sequence2);
    printf("Second sequence generated: %s\n", sequence2);

    compare_sequences(sequence1, sequence2);
    
    return 0;
}