//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100

char nucleotides[] = {'A', 'C', 'G', 'T'};

void generate_sequence(char sequence[], int length)
{
    if(length == 0) // base case to end the recursion
        return;
    
    int random_index = rand() % 4; // generate a random index to pick a nucleotide
    sequence[MAX_SEQUENCE_LENGTH - length] = nucleotides[random_index]; // add the nucleotide to the sequence
    
    generate_sequence(sequence, length - 1); // make the recursive call to generate the rest of the sequence
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    int sequence_length;
    printf("Enter the length of the sequence: ");
    scanf("%d", &sequence_length);
    
    if(sequence_length <= 0 || sequence_length > MAX_SEQUENCE_LENGTH) // handle input validation
    {
        printf("Invalid sequence length!\n");
        return 1; // return with exit status 1 to indicate error
    }
    
    char sequence[MAX_SEQUENCE_LENGTH + 1]; // create a character array to store the sequence (+1 for the null terminator)
    
    generate_sequence(sequence, sequence_length); // generate the sequence recursively
    
    sequence[sequence_length] = '\0'; // add a null terminator to the end of the sequence
    
    printf("Generated sequence: %s\n", sequence); // print the generated sequence
    
    return 0; // return with exit status 0 to indicate success
}