//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

void displayIntroduction();
void displayHelpInfo();
void playGame();

const char* directions[] = { "north", "south", "east", "west" };
const int roomDirections[] = { 2, 3, 0, 1 };
const char* roomNames[] = { "starting room", "dark room", "creepy room", "treasure room" };

int main()
{
    displayIntroduction();

    char input[MAX_INPUT_LENGTH];

    while (1)
    {
        // Prompt user for input
        printf("\nEnter your command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Convert input to lowercase for ease of matching
        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }

        // Parse input
        if (strcmp(input, "help\n") == 0)
        {
            displayHelpInfo();
        }
        else if (strcmp(input, "play\n") == 0)
        {
            playGame();
        }
        else if (strcmp(input, "quit\n") == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }
        else
        {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}

void displayIntroduction()
{
    printf("\nWelcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will explore a series of rooms to find treasure.\n");
    printf("Type 'help' for a list of commands.\n");
}

void displayHelpInfo()
{
    printf("\nCommands:\n");
    printf("'play' - start playing the game.\n");
    printf("'help' - display this help information.\n");
    printf("'quit' - quit the game.\n");
}

void playGame()
{
    int currentRoom = 0;

    // Loop until the player reaches the treasure room
    while (currentRoom != 3)
    {
        // Display current room information
        printf("\nYou are in the %s.\n", roomNames[currentRoom]);
        printf("There are exits to the %s, %s, %s, and %s.\n", directions[roomDirections[currentRoom]],
               directions[(roomDirections[currentRoom] + 1) % 4], directions[(roomDirections[currentRoom] + 2) % 4],
               directions[(roomDirections[currentRoom] + 3) % 4]);
        printf("Which direction do you want to go? ");

        char input[MAX_INPUT_LENGTH];
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Convert input to lowercase for ease of matching
        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }

        // Determine which direction the player wants to go in
        if (strcmp(input, "north\n") == 0)
        {
            currentRoom = roomDirections[currentRoom];
        }
        else if (strcmp(input, "east\n") == 0)
        {
            currentRoom = roomDirections[(currentRoom + 1) % 4];
        }
        else if (strcmp(input, "south\n") == 0)
        {
            currentRoom = roomDirections[(currentRoom + 2) % 4];
        }
        else if (strcmp(input, "west\n") == 0)
        {
            currentRoom = roomDirections[(currentRoom + 3) % 4];
        }
        else
        {
            printf("Invalid direction. Please enter 'north', 'south', 'east', or 'west'.\n");
        }
    }

    // Player has reached the treasure room!
    printf("\nCongratulations! You have found the treasure!\n");
}