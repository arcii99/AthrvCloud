//FormAI DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define NUM_ENEMIES 4

// Function to clear the console screen
void clear_screen()
{
    system("clear || cls");
}

int main()
{
    // Initialize the game map
    char map[ROWS][COLS] = {
        "###################",
        "#                 #",
        "#   @             #",
        "#                 #",
        "#  # # # # # #    #",
        "#                 #",
        "#    # # #####    #",
        "#                 #",
        "#   #           E #",
        "###################",
    };

    // Initialize the player's position
    int player_row = 2;
    int player_col = 4;

    // Initialize the enemies' positions
    int enemy_rows[NUM_ENEMIES] = {5, 5, 7, 7};
    int enemy_cols[NUM_ENEMIES] = {12, 15, 5, 10};

    // Initialize the random number generator
    srand(time(NULL));

    // Game loop
    while (1)
    {
        // Clear the console screen
        clear_screen();

        // Display the game map
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        // Check if the player has reached the exit
        if (map[player_row][player_col] == 'E')
        {
            printf("\nCongratulations! You have reached the exit.\n");
            break;
        }

        // Move the enemies randomly
        for (int i = 0; i < NUM_ENEMIES; i++)
        {
            int move = rand() % 4;

            switch (move)
            {
                case 0:  // move up
                    if (map[enemy_rows[i] - 1][enemy_cols[i]] == ' ')
                    {
                        map[enemy_rows[i] - 1][enemy_cols[i]] = 'E';
                        map[enemy_rows[i]][enemy_cols[i]] = ' ';
                        enemy_rows[i]--;
                    }
                    break;
                case 1:  // move down
                    if (map[enemy_rows[i] + 1][enemy_cols[i]] == ' ')
                    {
                        map[enemy_rows[i] + 1][enemy_cols[i]] = 'E';
                        map[enemy_rows[i]][enemy_cols[i]] = ' ';
                        enemy_rows[i]++;
                    }
                    break;
                case 2:  // move left
                    if (map[enemy_rows[i]][enemy_cols[i] - 1] == ' ')
                    {
                        map[enemy_rows[i]][enemy_cols[i] - 1] = 'E';
                        map[enemy_rows[i]][enemy_cols[i]] = ' ';
                        enemy_cols[i]--;
                    }
                    break;
                case 3:  // move right
                    if (map[enemy_rows[i]][enemy_cols[i] + 1] == ' ')
                    {
                        map[enemy_rows[i]][enemy_cols[i] + 1] = 'E';
                        map[enemy_rows[i]][enemy_cols[i]] = ' ';
                        enemy_cols[i]++;
                    }
                    break;
            }
        }

        // Get player input and move the player accordingly
        char input;
        printf("\nUse WASD keys to move: ");
        scanf(" %c", &input);

        switch (input)
        {
            case 'w':  // move up
                if (map[player_row - 1][player_col] == ' ')
                {
                    map[player_row - 1][player_col] = '@';
                    map[player_row][player_col] = ' ';
                    player_row--;
                }
                break;
            case 's':  // move down
                if (map[player_row + 1][player_col] == ' ')
                {
                    map[player_row + 1][player_col] = '@';
                    map[player_row][player_col] = ' ';
                    player_row++;
                }
                break;
            case 'a':  // move left
                if (map[player_row][player_col - 1] == ' ')
                {
                    map[player_row][player_col - 1] = '@';
                    map[player_row][player_col] = ' ';
                    player_col--;
                }
                break;
            case 'd':  // move right
                if (map[player_row][player_col + 1] == ' ')
                {
                    map[player_row][player_col + 1] = '@';
                    map[player_row][player_col] = ' ';
                    player_col++;
                }
                break;
        }

        // Check if any enemy has caught the player
        for (int i = 0; i < NUM_ENEMIES; i++)
        {
            if (enemy_rows[i] == player_row && enemy_cols[i] == player_col)
            {
                printf("\nOh no! You have been caught by an enemy!\n");
                return 0;
            }
        }
    }

    return 0;
}