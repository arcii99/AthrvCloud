//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // define the nucleotides in DNA
    char nucleotides[] = {'A', 'C', 'G', 'T'};

    // set the length of DNA sequence
    int length = 1000;

    // create a random DNA sequence of given length
    char sequence[length];
    for(int i = 0; i < length; i++)
    {
        int rand_num = rand() % 4;
        sequence[i] = nucleotides[rand_num];
    }

    // print the DNA sequence
    printf("DNA Sequence: ");
    for(int i = 0; i < length; i++)
    {
        printf("%c", sequence[i]);
    }
    printf("\n");

    // simulate genome sequencing
    int num_reads = length / 100;
    char reads[num_reads][101];  // each read is of length 100 with a null terminator
    for(int i = 0; i < num_reads; i++)
    {
        int index = i * 100;
        for(int j = 0; j < 100; j++)
        {
            reads[i][j] = sequence[index + j];
        }
        reads[i][100] = '\0';  // add the null terminator
    }

    // print the reads
    printf("Reads:\n");
    for(int i = 0; i < num_reads; i++)
    {
        printf("%d: %s\n", i + 1, reads[i]);
    }

    return 0;
}