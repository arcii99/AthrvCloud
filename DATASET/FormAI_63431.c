//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random number within a given range
int randomNum(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to parse player input
int parseInput(char input[])
{
    if (strcmp(input, "north") == 0 || strcmp(input, "n") == 0)
        return 0;
    else if (strcmp(input, "east") == 0 || strcmp(input, "e") == 0)
        return 1;
    else if (strcmp(input, "south") == 0 || strcmp(input, "s") == 0)
        return 2;
    else if (strcmp(input, "west") == 0 || strcmp(input, "w") == 0)
        return 3;
    else
        return -1;
}

int main()
{
    printf("Welcome to Adventure Island!\n");
    printf("You have been stranded on an mysterious island. Your goal is to find a way off the island.\n");
    
    // Define player's starting position
    int x = 0, y = 0;
    
    // Define the island map
    const int ROWS = 10, COLS = 10;
    int map[ROWS][COLS];
    
    // Populate the island map with random terrain
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            map[i][j] = randomNum(0, 3);
        }
    }
    
    // Define game loop variables
    bool gameOver = false;
    char input[10];
    
    // Main game loop
    while (!gameOver)
    {
        printf("\nYour location: (%d, %d)\n", x, y);
        printf("What direction would you like to go? (north, south, east, west): ");
        scanf("%s", input);
        
        int direction = parseInput(input);
        if (direction == -1)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        // Move the player based on input direction
        switch (direction)
        {
            case 0: // North
                if (y == 0)
                    printf("You cannot go any further north.\n");
                else
                {
                    y--;
                    printf("You head north.\n");
                }
                break;
            case 1: // East
                if (x == COLS - 1)
                    printf("You cannot go any further east.\n");
                else
                {
                    x++;
                    printf("You head east.\n");
                }
                break;
            case 2: // South
                if (y == ROWS - 1)
                    printf("You cannot go any further south.\n");
                else
                {
                    y++;
                    printf("You head south.\n");
                }
                break;
            case 3: // West
                if (x == 0)
                    printf("You cannot go any further west.\n");
                else
                {
                    x--;
                    printf("You head west.\n");
                }
                break;
        }
        
        // Check if the player has reached the edge of the island
        if (x == 0 || x == COLS - 1 || y == 0 || y == ROWS - 1)
        {
            printf("\nYou have reached the edge of the island!\n");
            gameOver = true;
        }
        else
        {
            // Check the type of terrain the player is on
            switch (map[y][x])
            {
                case 0:
                    printf("You are walking on a sandy beach.\n");
                    break;
                case 1:
                    printf("You are walking through a dense forest.\n");
                    break;
                case 2:
                    printf("You are walking up a rocky hill.\n");
                    break;
                case 3:
                    printf("You are walking along a swampy marsh.\n");
                    break;
            }
        }
    }
    
    printf("\nCongratulations! You have successfully found your way off the island.\n");
    return 0;
}