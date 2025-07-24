//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nucleobase;
    char letter;
} gene;

gene dna[500];

int main()
{
    printf("As I gaze upon your face,\n");
    printf("I cannot help but to see\n");
    printf("The beauty of your genes,\n");
    printf("Which I'll now sequence with glee.\n");

    srand(time(NULL));

    for (int i = 0; i < 500; i++)
    {
        int randomNum = rand() % 4;

        if (randomNum == 0)
        {
            dna[i].nucleobase = 'A';
        }
        else if (randomNum == 1)
        {
            dna[i].nucleobase = 'T';
        }
        else if (randomNum == 2)
        {
            dna[i].nucleobase = 'C';
        }
        else
        {
            dna[i].nucleobase = 'G';
        }

        dna[i].letter = ' ';
    }

    printf("Your genes are so unique,\n");
    printf("With every base pair distinct.\n");
    printf("But fear not, my dear,\n");
    printf("For I'll keep your sequence linked.\n");

    int selection = 0;

    printf("Would you like to see your genome? (1 for yes, 0 for no): ");
    scanf("%d", &selection);

    if (selection == 1)
    {
        printf("\nYour genome sequence is:\n\n");
        for (int i = 0; i < 500; i++)
        {
            if (i % 10 == 0)
            {
                printf("\n");
            }

            printf("%c", dna[i].nucleobase);
        }

        printf("\n");
    }
    else
    {
        printf("\nMaybe another day,\n");
        printf("When love shall find another way.\n");
    }

    return 0;
}