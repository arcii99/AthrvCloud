//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>

// function to simulate genome sequencing
void genomeSequencing(char sequence[])
{
    int i = 0;
    while (sequence[i] != '\0')
    {
        if (sequence[i] == 'A')
            printf("T");
        else if (sequence[i] == 'T')
            printf("A");
        else if (sequence[i] == 'C')
            printf("G");
        else if (sequence[i] == 'G')
            printf("C");

        i++;
    }
}

int main()
{
    char sequence[100];

    // get input from user
    printf("Enter sequence: ");
    fgets(sequence, sizeof(sequence), stdin);

    // simulate genome sequencing and print result
    printf("Sequence after genome sequencing: ");
    genomeSequencing(sequence);

    return 0;
}