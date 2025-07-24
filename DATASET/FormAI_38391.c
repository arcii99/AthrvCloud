//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Define global variables
char house[ROWS][COLS];
int row = ROWS / 2;
int col = COLS / 2;
bool flashlight = false;
bool key = false;

// Function prototypes
void generateHouse();
void printHouse();
void move(char direction);
void interact();
void endGame();

int main()
{
    // Generate and print the haunted house
    generateHouse();
    printHouse();

    // Listen for user input until game over
    while (true)
    {
        // Prompt user to move or interact
        printf("\nEnter 'w', 'a', 's', or 'd' to move.\nEnter 'e' to interact.\n");

        // Get user input
        char input;
        scanf(" %c", &input);

        // Move or interact based on input
        if (input == 'w' || input == 'a' || input == 's' || input == 'd')
        {
            move(input);
            printHouse();
        }
        else if (input == 'e')
        {
            interact();
            printHouse();

            // End the game if the player has the key and is at the exit
            if (key && row == 0 && col == COLS - 1)
            {
                endGame();
                return 0;
            }
        }
    }

    return 0;
}

// Function to generate the haunted house
void generateHouse()
{
    // Set all tiles to ' '
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            house[i][j] = ' ';
        }
    }

    // Create walls and doors
    for (int i = 0; i < ROWS; i++)
    {
        house[i][0] = '|';
        house[i][COLS - 1] = '|';
    }
    for (int j = 0; j < COLS; j++)
    {
        house[0][j] = '-';
        house[ROWS - 1][j] = '-';
    }
    house[row][col] = 'o';
    house[0][COLS - 1] = 'x';
    house[ROWS / 2][(COLS / 4) * 3] = '|';

    // Create objects
    house[ROWS / 4][(COLS / 4) * 3] = 't';
    house[(ROWS / 4) * 3][COLS / 4] = 'k';
}

// Function to print the haunted house
void printHouse()
{
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", house[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
void move(char direction)
{
    // Clear the player's current position
    house[row][col] = ' ';

    // Move the player in the direction
    if (direction == 'w' && row > 0 && house[row - 1][col] != '-')
    {
        row--;
    }
    else if (direction == 'a' && col > 0 && house[row][col - 1] != '|')
    {
        col--;
    }
    else if (direction == 's' && row < ROWS - 1 && house[row + 1][col] != '-')
    {
        row++;
    }
    else if (direction == 'd' && col < COLS - 1 && house[row][col + 1] != '|')
    {
        col++;
    }

    // Set the player's new position
    house[row][col] = 'o';
}

// Function to interact with the environment
void interact()
{
    // Determine if there is an object in front of the player
    char object;
    if (row > 0 && house[row - 1][col] != ' ')
    {
        object = house[row - 1][col];
    }
    else if (col > 0 && house[row][col - 1] != ' ')
    {
        object = house[row][col - 1];
    }
    else if (row < ROWS - 1 && house[row + 1][col] != ' ')
    {
        object = house[row + 1][col];
    }
    else if (col < COLS - 1 && house[row][col + 1] != ' ')
    {
        object = house[row][col + 1];
    }
    else
    {
        printf("\nThere is nothing here.\n");
        return;
    }

    // Interact with the object
    if (object == 't')
    {
        // Turn on the flashlight
        flashlight = true;
        printf("\nYou turned on the flashlight.\n");
    }
    else if (object == 'k')
    {
        // Pick up the key
        key = true;
        printf("\nYou picked up the key.\n");
        house[(ROWS / 4) * 3][COLS / 4] = ' ';
    }
    else if (object == '|')
    {
        // Open or close the door
        house[ROWS / 2][(COLS / 4) * 3] = house[ROWS / 2][(COLS / 4) * 3] == '|' ? ' ' : '|';
        printf("\nYou %s the door.\n", house[ROWS / 2][(COLS / 4) * 3] == '|' ? "opened" : "closed");
    }
    else if (object == ' ')
    {
        printf("\nThere is nothing here.\n");
    }
    else
    {
        printf("\nYou cannot interact with this object.\n");
    }
}

// Function to end the game
void endGame()
{
    printf("\nYou escaped the haunted house!\n");
    if (flashlight)
    {
        printf("You used the flashlight.\n");
    }
}