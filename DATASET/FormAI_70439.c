//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20

int main()
{
    srand(time(NULL));
    char gameBoard[ROWS][COLUMNS];
    int playerRow = ROWS - 1; // player starting position
    int playerColumn = COLUMNS / 2; // player starting position
    int score = 0;

    // initialize game board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            gameBoard[i][j] = '-';
        }
    }

    // display initial game board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }

    // main game loop
    bool gameOver = false;
    while (!gameOver)
    {
        // move player
        char userInput = toupper(getchar());
        if (userInput == 'A' && playerColumn > 0)
        {
            playerColumn--;
        }
        else if (userInput == 'D' && playerColumn < COLUMNS - 1)
        {
            playerColumn++;
        }

        // move aliens
        for (int i = ROWS - 2; i >= 0; i--)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (gameBoard[i][j] == 'O')
                {
                    gameBoard[i][j] = '-';
                    if (i == ROWS - 2)
                    {
                        gameOver = true; // aliens reached player
                    }
                    else
                    {
                        if (j > 0 && gameBoard[i + 1][j - 1] == '-')
                        {
                            gameBoard[i + 1][j - 1] = 'O';
                        }
                        if (j < COLUMNS - 1 && gameBoard[i + 1][j + 1] == '-')
                        {
                            gameBoard[i + 1][j + 1] = 'O';
                        }
                    }
                }
            }
        }

        // add new alien in random column
        if (rand() % 100 < 5)
        {
            int alienColumn = rand() % COLUMNS;
            gameBoard[0][alienColumn] = 'O';
        }

        // check for collision
        if (gameBoard[playerRow][playerColumn] == 'O')
        {
            gameOver = true;
        }

        // update player position on board
        gameBoard[playerRow][playerColumn] = 'X';

        // display game board
        system("clear"); // clear screen
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                printf("%c", gameBoard[i][j]);
            }
            printf("\n");
        }

        // update score
        score += 10;

        // check for win
        bool win = true;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (gameBoard[i][j] == 'O')
                {
                    win = false;
                }
            }
        }
        if (win)
        {
            gameOver = true;
            printf("Congratulations, you've won!\n");
        }
    }

    printf("GAME OVER! Your score: %d\n", score);
    return 0;
}