//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    printf("Welcome to the Gene Pool!\n");

    // Create organism with random genetic traits
    int organism[23];
    printf("Creating organism with random genetic traits...\n");
    for(int i=0; i<23; i++)
    {
        organism[i] = rand() % 2;
    }

    // Display organism's traits
    printf("Organism's Traits: ");
    for(int i=0; i<23; i++)
    {
        printf("%d ", organism[i]);
    }
    printf("\n");

    // Check for mutations
    int mutation = rand() % 100;
    if(mutation < 10)
    {
        printf("Mutation Detected!\n");

        // Generate new trait
        int newTrait = rand() % 2;

        // Select random trait to mutate
        int traitToMutate = rand() % 23;

        // Mutate the organism
        organism[traitToMutate] = newTrait;

        // Display newly mutated traits
        printf("Newly Mutated Traits: ");
        for(int i=0; i<23; i++)
        {
            printf("%d ", organism[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No mutation detected. The gene pool remains unchanged.\n");
    }

    // End program
    printf("Thank you for using the Gene Pool!\n");
    return 0;
}