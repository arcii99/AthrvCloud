//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 30

int main()
{
    // Declare variables
    int i, j, player_position, bullet_position, enemy_position, score;
    char keyboard_input;
    char screen_buffer[MAX_HEIGHT][MAX_WIDTH];

    // Initialize game variables
    player_position = MAX_WIDTH / 2;
    bullet_position = -1;
    enemy_position = rand() % MAX_WIDTH;
    score = 0;

    // Initialize screen buffer
    for(i = 0; i < MAX_HEIGHT; i++)
    {
        for(j = 0; j < MAX_WIDTH; j++)
        {
            if(i == MAX_HEIGHT - 1) // Draw player at bottom row
            {
                if(j == player_position)
                {
                    screen_buffer[i][j] = '^';
                }
                else
                {
                    screen_buffer[i][j] = ' ';
                }
            }
            else if(i == 0 && j == enemy_position) // Draw enemy at top row
            {
                screen_buffer[i][j] = 'V';
            }
            else // Draw empty space
            {
                screen_buffer[i][j] = ' ';
            }
        }
    }

    // Main game loop
    while(1)
    {
        system("clear"); // Clear screen

        // Update player and bullet positions
        if(bullet_position >= 0) bullet_position--;
        if(keyboard_input == 'a' && player_position > 0) player_position--;
        if(keyboard_input == 'd' && player_position < MAX_WIDTH - 1) player_position++;
        if(keyboard_input == ' ' && bullet_position < 0) bullet_position = MAX_HEIGHT - 2;

        // Update enemy position and score
        if(enemy_position == MAX_WIDTH - 1)
        {
            enemy_position = 0;
            score++;
        }
        else
        {
            enemy_position++;
        }

        // Detect collision
        if(bullet_position == 0 && enemy_position == player_position)
        {
            score += 10;
            bullet_position = -1;
            enemy_position = rand() % MAX_WIDTH;
        }

        // Update screen buffer
        for(i = 0; i < MAX_HEIGHT; i++)
        {
            for(j = 0; j < MAX_WIDTH; j++)
            {
                if(i == MAX_HEIGHT - 1 && j == player_position) // Draw player
                {
                    screen_buffer[i][j] = '^';
                }
                else if(i == MAX_HEIGHT - 2 && j == bullet_position) // Draw bullet
                {
                    screen_buffer[i][j] = '*';
                }
                else if(i == 0 && j == enemy_position) // Draw enemy
                {
                    screen_buffer[i][j] = 'V';
                }
                else // Draw empty space
                {
                    screen_buffer[i][j] = ' ';
                }
            }
        }

        // Print screen
        for(i = 0; i < MAX_HEIGHT; i++)
        {
            for(j = 0; j < MAX_WIDTH; j++)
            {
                printf("%c", screen_buffer[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\n\n", score);

        // Wait for player input
        keyboard_input = getchar();
    }

    return 0;
}