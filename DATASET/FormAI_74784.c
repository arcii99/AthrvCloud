//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int kbhit();
void printGrid(char gameGrid[ROWS][COLUMNS]);
void updateGrid(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, int *points);
void movePlayer(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, char direction);
void moveInvaders(char gameGrid[ROWS][COLUMNS]);
void placeInvaders(char gameGrid[ROWS][COLUMNS], int n);
void shoot(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, int *points);

int main()
{
    // initialize game grid and variables
    char gameGrid[ROWS][COLUMNS] = {0};
    int playerX = 0, playerY = COLUMNS / 2 - 1, points = 0;

    // place player on grid
    gameGrid[playerX][playerY] = 'P';

    // place invaders on grid
    placeInvaders(gameGrid, ROWS / 2);

    // print initial game grid
    printGrid(gameGrid);

    while (1)
    {
        // check if player has been hit
        if (gameGrid[playerX][playerY] == 'I')
        {
            printf("\nYou lost! Final score: %d\n", points);
            return 0;
        }

        // check if all invaders have been defeated
        int invadersRemaining = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (gameGrid[i][j] == 'I')
                {
                    invadersRemaining = 1;
                    break;
                }
            }
        }
        if (!invadersRemaining)
        {
            printf("\nYou won! Final score: %d\n", points);
            return 0;
        }

        // check for user input
        if (kbhit())
        {
            char input = getchar();
            switch (input)
            {
            case 'a':
                movePlayer(gameGrid, &playerX, &playerY, 'l');
                break;
            case 'd':
                movePlayer(gameGrid, &playerX, &playerY, 'r');
                break;
            case ' ':
                shoot(gameGrid, &playerX, &playerY, &points);
                break;
            }
        }

        // update game grid and print new grid
        updateGrid(gameGrid, &playerX, &playerY, &points);
        printGrid(gameGrid);

        // wait before updating again
        usleep(100000);
    }
}

/**
 * Check if a key has been pressed.
 */
int kbhit()
{
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

/**
 * Print the game grid to the console.
 */
void printGrid(char gameGrid[ROWS][COLUMNS])
{
    system("clear");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", gameGrid[i][j]);
        }
        printf("\n");
    }
}

/**
 * Update the game grid based on player and invader movements.
 */
void updateGrid(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, int *points)
{
    // move invaders
    moveInvaders(gameGrid);

    // update player position
    gameGrid[*playerX][*playerY] = 'P';

    // check for invader hits
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (gameGrid[i][j] == '|')
            {
                gameGrid[i][j] = 0;
            }
            else if (gameGrid[i][j] == '-')
            {
                gameGrid[i][j] = 0;
            }
            else if (gameGrid[i][j] == 'X')
            {
                gameGrid[i][j] = 0;
            }
            else if (gameGrid[i][j] == 'I' && gameGrid[i + 1][j] == '|')
            {
                gameGrid[i + 1][j] = 'X';
                gameGrid[i][j] = 0;
                *points += 10;
            }
        }
    }

    // check for player hits
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (gameGrid[i][j] == 'X' && i == *playerX && j == *playerY)
            {
                gameGrid[i][j] = 0;
                gameGrid[*playerX][*playerY] = 'I';
                return;
            }
        }
    }
}

/**
 * Move the player left or right.
 */
void movePlayer(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, char direction)
{
    gameGrid[*playerX][*playerY] = 0;
    if (direction == 'l' && *playerY > 0)
    {
        (*playerY)--;
    }
    else if (direction == 'r' && *playerY < COLUMNS - 1)
    {
        (*playerY)++;
    }
    gameGrid[*playerX][*playerY] = 'P';
}

/**
 * Move the invaders.
 */
void moveInvaders(char gameGrid[ROWS][COLUMNS])
{
    // set up variables for determining invader movement direction
    static int direction = 1;
    static int count = 0;

    // move invaders
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (gameGrid[i][j] == 'I')
            {
                gameGrid[i][j] = 0;
                if (direction == 1)
                {
                    if (j < COLUMNS - 1)
                    {
                        gameGrid[i][j + 1] = 'I';
                    }
                    else
                    {
                        direction = -1;
                    }
                }
                else
                {
                    if (j > 0)
                    {
                        gameGrid[i][j - 1] = 'I';
                    }
                    else
                    {
                        direction = 1;
                    }
                }
            }
        }
    }

    // randomly fire shots
    srand(time(NULL));
    int fireChance = rand() % 100;
    if (fireChance < 10)
    {
        for (int i = 0; i < COLUMNS; i++)
        {
            if (gameGrid[ROWS - 1][i] == 'I')
            {
                gameGrid[ROWS - 1][i] = '|';
                break;
            }
        }
    }

    // move invaders' shots
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (gameGrid[i][j] == '|')
            {
                gameGrid[i][j] = '-';
                if (gameGrid[i + 1][j] == 'P')
                {
                    gameGrid[i + 1][j] = 'X';
                }
            }
            else if (gameGrid[i][j] == '-')
            {
                gameGrid[i][j] = 0;
                if (i + 1 < ROWS && gameGrid[i + 1][j] == 0)
                {
                    gameGrid[i + 1][j] = '-';
                }
            }
        }
    }
}

/**
 * Place invaders on the game grid.
 */
void placeInvaders(char gameGrid[ROWS][COLUMNS], int n)
{
    int placedInvaders = 0;
    srand(time(NULL));
    while (placedInvaders < n)
    {
        int x = rand() % ROWS;
        int y = rand() % COLUMNS;
        if (gameGrid[x][y] == 0)
        {
            gameGrid[x][y] = 'I';
            placedInvaders++;
        }
    }
}

/**
 * Shoot a shot from the player.
 */
void shoot(char gameGrid[ROWS][COLUMNS], int *playerX, int *playerY, int *points)
{
    for (int i = *playerX - 1; i >= 0; i--)
    {
        if (gameGrid[i][*playerY] == 'I')
        {
            gameGrid[i][*playerY] = 'X';
            *points += 10;
            return;
        }
        else if (gameGrid[i][*playerY] != 0)
        {
            return;
        }
        gameGrid[i][*playerY] = '|';
    }
}