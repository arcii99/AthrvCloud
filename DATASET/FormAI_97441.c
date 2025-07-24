//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Haunted House Simulator! \n");

    // Set up random seed
    srand(time(NULL));

    // List of spooky noises
    char* noises[3] = {"creeeeeaaaak", "oooooooohhhh", "yikes!"};

    // Variables to track player position
    int x_pos = 0;
    int y_pos = 0;

    // Display initial position
    printf("You are in room %d,%d\n", x_pos, y_pos);

    // Loop until player reaches end of the maze
    while (x_pos < 4 || y_pos < 4)
    {
        // Generate random noise
        int rand_index = rand() % 3;
        printf("%s\n", noises[rand_index]);

        // Prompt user for next move
        printf("Which direction would you like to go? (n/s/w/e): ");
        char move;
        scanf(" %c", &move);

        // Update player position based on move
        if (move == 'n')
        {
            y_pos++;
        }
        else if (move == 's')
        {
            y_pos--;
        }
        else if (move == 'w')
        {
            x_pos--;
        }
        else if (move == 'e')
        {
            x_pos++;
        }
        else
        {
            printf("Invalid move, try again\n");
            continue;
        }

        // Check if player is out of bounds
        if (x_pos < 0 || x_pos > 4 || y_pos < 0 || y_pos > 4)
        {
            printf("You hit a wall, try a different direction\n");

            // Reset player position back to previous state
            if (move == 'n')
            {
                y_pos--;
            }
            else if (move == 's')
            {
                y_pos++;
            }
            else if (move == 'w')
            {
                x_pos++;
            }
            else if (move == 'e')
            {
                x_pos--;
            }
        }
        else
        {
            // Display new position
            printf("You are in room %d,%d\n", x_pos, y_pos);
        }
    }

    // Player reached the end!
    printf("Congratulations, you made it out of the haunted house!\n");

    return 0;
}