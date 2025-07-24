//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Setting up the house
    int house[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Setting initial player position
    int player_x = 1;
    int player_y = 1;

    // Main game loop
    while (1)
    {
        system("clear"); // Clear console screen

        // Print out house with player position
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (player_x == x && player_y == y)
                    printf("P ");
                else if (house[y][x] == 0)
                    printf("# ");
                else
                    printf(". ");
            }
            printf("\n");
        }

        // Check win condition
        if (player_x == 3 && player_y == 3)
        {
            printf("Congratulations! You escaped the haunted house!\n");
            break;
        }

        // Ask player for movement input
        printf("Use WASD to move: ");
        char input = getchar();

        // Move player based on input
        if (input == 'w' && house[player_y-1][player_x] == 1)
            player_y--;
        else if (input == 'a' && house[player_y][player_x-1] == 1)
            player_x--;
        else if (input == 's' && house[player_y+1][player_x] == 1)
            player_y++;
        else if (input == 'd' && house[player_y][player_x+1] == 1)
            player_x++;

        getchar(); // Discard enter key
    }

    return 0;
}