//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with time

    // Welcome message and instructions on how to play the game
    printf("Welcome to The Mysterious Island!\n\n");
    printf("You find yourself stranded on a deserted island, with no memory of how you got there. ");
    printf("Your goal is to make it off the island alive.\n\n");
    printf("You will encounter various obstacles and challenges along the way. ");
    printf("To navigate through the island, you must make choices and type in your responses.\n\n");
    printf("Let's begin...\n\n");

    // Initialize game variables
    int health = 100;
    int hunger = 50;
    int thirst = 50;

    // Main game loop
    while (health > 0 && hunger > 0 && thirst > 0)
    {
        // Display current status
        printf("Health: %d\n", health);
        printf("Hunger: %d\n", hunger);
        printf("Thirst: %d\n", thirst);

        // Prompt user for input
        printf("\nWhat would you like to do? ");
        char userInput[20];
        fgets(userInput, sizeof(userInput), stdin);

        // Remove newline character from user input
        userInput[strcspn(userInput, "\n")] = 0;

        // Generate a random event
        int event = rand() % 3;

        if (strcmp(userInput, "explore") == 0)
        {
            switch (event)
            {
                case 0:
                    printf("You find a source of fresh water. Your thirst decreases.\n");
                    thirst += 20;
                    break;

                case 1:
                    printf("You stumble upon a fruit tree. Your hunger decreases.\n");
                    hunger += 20;
                    break;

                case 2:
                    printf("You come across a dangerous animal. Your health decreases.\n");
                    health -= 20;
                    break;

                default:
                    printf("Oops, something went wrong.\n");
                    break;
            }
        }
        else if (strcmp(userInput, "drink") == 0)
        {
            printf("You drink some water.\n");
            thirst += 10;
        }
        else if (strcmp(userInput, "eat") == 0)
        {
            printf("You eat some fruit.\n");
            hunger += 10;
        }
        else if (strcmp(userInput, "rest") == 0)
        {
            printf("You take a nap.\n");
            health += 10;
        }
        else if (strcmp(userInput, "quit") == 0)
        {
            printf("Thanks for playing!\n");
            exit(0);
        }
        else
        {
            printf("Sorry, I didn't understand that.\n");
        }

        // Update status
        hunger -= 10;
        thirst -= 10;
        health += 5;
    }

    // Game over
    printf("Game over!\n");
    if (health <= 0)
    {
        printf("You died.\n");
    }
    else
    {
        printf("Congratulations, you made it off the island alive!\n");
    }

    return 0;
}