//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define PACMAN '@'
#define GHOST 'G'
#define DOT '.'

// Function prototypes
void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void displayBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void spawnEntities(char board[BOARD_HEIGHT][BOARD_WIDTH], int numGhosts);
void movePacman(char board[BOARD_HEIGHT][BOARD_WIDTH], int x, int y);
void moveGhosts(char board[BOARD_HEIGHT][BOARD_WIDTH], int numGhosts);

int main()
{
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int numGhosts = 4;

    initializeBoard(board);
    spawnEntities(board, numGhosts);

    // Game loop
    while (true)
    {
        displayBoard(board);

        int x, y;
        printf("Enter x and y coordinates for Pac-Man (separated by a space): ");
        scanf("%d %d", &x, &y);
        movePacman(board, x, y);

        moveGhosts(board, numGhosts);
    }

    return 0;
}

void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    // Set the entire board to dots
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            board[i][j] = DOT;
        }
    }
}

void displayBoard(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    printf("\n");

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

void spawnEntities(char board[BOARD_HEIGHT][BOARD_WIDTH], int numGhosts)
{
    // Spawn Pac-Man in the center of the board
    int pacx = BOARD_WIDTH / 2;
    int pacy = BOARD_HEIGHT / 2;
    board[pacy][pacx] = PACMAN;

    // Spawn ghosts randomly
    srand(time(NULL));

    for (int i = 0; i < numGhosts; i++)
    {
        int ghostx = rand() % BOARD_WIDTH;
        int ghosty = rand() % BOARD_HEIGHT;
        board[ghosty][ghostx] = GHOST;
    }
}

void movePacman(char board[BOARD_HEIGHT][BOARD_WIDTH], int x, int y)
{
    // Move Pac-Man to the new position
    board[y][x] = PACMAN;

    // Remove Pac-Man from the old position
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            if (board[i][j] == PACMAN && (i != y || j != x))
            {
                board[i][j] = DOT;
            }
        }
    }
}

void moveGhosts(char board[BOARD_HEIGHT][BOARD_WIDTH], int numGhosts)
{
    // Move each ghost randomly
    for (int i = 0; i < numGhosts; i++)
    {
        int ghostx, ghosty;

        // Find the position of the current ghost
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            for (int k = 0; k < BOARD_WIDTH; k++)
            {
                if (board[j][k] == GHOST)
                {
                    ghostx = k;
                    ghosty = j;
                }
            }
        }

        // Choose a random direction
        srand(time(NULL));
        int direction = rand() % 4;

        // Move the ghost in the chosen direction
        switch (direction)
        {
            case 0: // Up
                if (ghosty > 0)
                {
                    board[ghosty][ghostx] = DOT;
                    board[ghosty-1][ghostx] = GHOST;
                }
                break;

            case 1: // Down
                if (ghosty < BOARD_HEIGHT-1)
                {
                    board[ghosty][ghostx] = DOT;
                    board[ghosty+1][ghostx] = GHOST;
                }
                break;

            case 2: // Left
                if (ghostx > 0)
                {
                    board[ghosty][ghostx] = DOT;
                    board[ghosty][ghostx-1] = GHOST;
                }
                break;

            case 3: // Right
                if (ghostx < BOARD_WIDTH-1)
                {
                    board[ghosty][ghostx] = DOT;
                    board[ghosty][ghostx+1] = GHOST;
                }
                break;
        }
    }
}