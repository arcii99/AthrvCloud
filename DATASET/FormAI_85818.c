//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main()
{
    srand(time(NULL));
    int score = 0;
    int delay = 500;
    bool gameOver = false;

    char board[ROWS][COLS] = {
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}
    };
    
    while (!gameOver)
    {
        system("clear"); // clear console screen
        printf("Score: %d\n", score);

        // print board
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // move invader
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == 'X')
                {
                    board[i][j] = ' ';
                    if (j == 0)
                    {
                        gameOver = true;
                        break;
                    }
                    board[i][j-1] = 'X';
                }
            }
        }

        // move player
        int playerCol;
        printf("Enter column to move player (0-9): ");
        scanf("%d", &playerCol);
        getchar(); // flush newline character
        board[ROWS-1][playerCol] = 'O';

        // check for collision
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == 'X' && board[i][j+1] == 'O')
                {
                    score++;
                    board[i][j] = ' ';
                    board[i][j+1] = ' ';
                }
            }
        }

        // add new invader
        int randomRow = rand() % ROWS;
        board[randomRow][COLS-1] = 'X';

        // delay
        struct timespec ts = {(delay / 1000), (delay % 1000) * 1000000};
        nanosleep(&ts, NULL);
    }

    printf("Game Over. Final Score: %d\n", score);

    return 0;
}