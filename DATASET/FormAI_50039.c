//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char* subjects[] = {"The Illuminati", "NASA", "The Freemasons", "The Government", "Big Pharma", "The Media", "The Education System"};
    char* verbs[] = {"is controlling", "is manipulating", "is hiding", "is planning", "is brainwashing", "is infiltrating", "is conspiring with"};
    char* objects[] = {"the weather", "our minds", "the economy", "the election", "the stock market", "the internet", "the food supply"};

    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    // Get user input for number of theories they want to hear
    int num_theories;
    printf("How many conspiracy theories would you like to hear? ");
    scanf("%d", &num_theories);
    printf("\n");

    // Generate and print out random theories
    for(int i = 0; i < num_theories; i++)
    {
        int sub_index = rand() % 7;
        int verb_index = rand() % 7;
        int obj_index = rand() % 7;

        // Print out theory sentence
        printf("Theory #%d: %s %s %s.\n\n", i+1, subjects[sub_index], verbs[verb_index], objects[obj_index]);
    }

    printf("Thank you for using the Random Conspiracy Theory Generator! Stay woke.\n");

    return 0;
}