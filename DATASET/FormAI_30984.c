//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5
#define PLAYER_SYMBOL 'P'
#define ENEMY_SYMBOL 'E'
#define BULLET_SYMBOL '*'
#define EMPTY_SYMBOL ' '

// Function declarations
void initBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
void placePlayer(char board[ROWS][COLS], int *playerRow, int *playerCol);
void movePlayer(char board[ROWS][COLS], int *playerRow, int *playerCol, char move);
bool moveEnemies(char board[ROWS][COLS]);
void placeBullet(char board[ROWS][COLS], int playerRow, int playerCol);
bool moveBullet(char board[ROWS][COLS], int *bulletRow, int *bulletCol);
bool checkCollision(char board[ROWS][COLS], int row, int col, char symbol);
bool gameWon(char board[ROWS][COLS]);
bool gameLost(char board[ROWS][COLS]);

int main()
{
    char board[ROWS][COLS];
    int playerRow, playerCol;
    char move;
    bool gameOver = false;

    srand(time(NULL));

    // Initialize game board and place player
    initBoard(board);
    placePlayer(board, &playerRow, &playerCol);

    // Loop for gameplay
    while (!gameOver)
    {
        // Print game board and get player move
        printBoard(board);
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        // Move player
        movePlayer(board, &playerRow, &playerCol, move);

        // Move enemies and check for collisions
        if (moveEnemies(board))
        {
            gameOver = true;
            printf("Game over! You lose.\n");
            break;
        }

        // Place bullet and move it, check for collisions
        placeBullet(board, playerRow, playerCol);
        if (moveBullet(board, &playerRow, &playerCol))
        {
            gameOver = true;
            printf("Congratulations! You win!\n");
            break;
        }

        // Check for win or loss
        if (gameWon(board))
        {
            gameOver = true;
            printf("Congratulations! You win!\n");
        }
        else if (gameLost(board))
        {
            gameOver = true;
            printf("Game over! You lose.\n");
        }
    }

    return 0;
}

/*
 * Function to initialize game board with enemies and empty spaces
 */
void initBoard(char board[ROWS][COLS])
{
    int i, j;

    // Fill board with empty spaces
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = EMPTY_SYMBOL;
        }
    }

    // Add enemies randomly to board
    for (i = 0; i < ROWS; i++)
    {
        int randIndex = rand() % COLS;
        board[i][randIndex] = ENEMY_SYMBOL;
    }
}

/*
 * Function to print game board to console
 */
void printBoard(char board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function to place player on game board at random location
 */
void placePlayer(char board[ROWS][COLS], int *playerRow, int *playerCol)
{
    int randRow = rand() % ROWS;
    int randCol = rand() % COLS;

    // Check if player location is already occupied by enemy
    while (board[randRow][randCol] == ENEMY_SYMBOL)
    {
        randRow = rand() % ROWS;
        randCol = rand() % COLS;
    }

    board[randRow][randCol] = PLAYER_SYMBOL;
    *playerRow = randRow;
    *playerCol = randCol;
}

/*
 * Function to move player on game board
 */
void movePlayer(char board[ROWS][COLS], int *playerRow, int *playerCol, char move)
{
    int newRow = *playerRow;
    int newCol = *playerCol;

    switch (move)
    {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
    }

    // Check if new position is within bounds
    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS)
    {
        return;
    }

    // Check if new position is already occupied by enemy
    if (board[newRow][newCol] == ENEMY_SYMBOL)
    {
        return;
    }

    // Move player and update board
    board[*playerRow][*playerCol] = EMPTY_SYMBOL;
    *playerRow = newRow;
    *playerCol = newCol;
    board[*playerRow][*playerCol] = PLAYER_SYMBOL;
}

/*
 * Function to move enemies on game board
 */
bool moveEnemies(char board[ROWS][COLS])
{
    int i, j;
    bool gameOver = false;

    for (i = ROWS - 1; i >= 0; i--)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == ENEMY_SYMBOL)
            {
                // Clear old position
                board[i][j] = EMPTY_SYMBOL;

                // Check if enemy collided with player
                if (i == ROWS - 1)
                {
                    gameOver = true;
                }
                else
                {
                    // Move enemy down
                    board[i+1][j] = ENEMY_SYMBOL;
                }
            }
        }
    }

    return gameOver;
}

/*
 * Function to place bullet on game board
 */
void placeBullet(char board[ROWS][COLS], int playerRow, int playerCol)
{
    int upRow = playerRow - 1;
    int bulletCol = playerCol;

    // Check if space above player is empty
    if (board[upRow][playerCol] == EMPTY_SYMBOL)
    {
        board[upRow][playerCol] = BULLET_SYMBOL;
    }
}

/*
 * Function to move bullet on game board
 */
bool moveBullet(char board[ROWS][COLS], int *bulletRow, int *bulletCol)
{
    // Check if bullet is off the board
    if (*bulletRow < 0)
    {
        return true;
    }

    // Check for enemy collision
    if (checkCollision(board, *bulletRow, *bulletCol, ENEMY_SYMBOL))
    {
        board[*bulletRow][*bulletCol] = EMPTY_SYMBOL;
        return true;
    }

    // Move bullet and update board
    board[*bulletRow][*bulletCol] = EMPTY_SYMBOL;
    (*bulletRow)--;
    board[*bulletRow][*bulletCol] = BULLET_SYMBOL;

    return false;
}

/*
 * Function to check if symbol collides with game board at specified row and column
 */
bool checkCollision(char board[ROWS][COLS], int row, int col, char symbol)
{
    if (board[row][col] == symbol)
    {
        return true;
    }

    return false;
}

/*
 * Function to check if player has won the game
 */
bool gameWon(char board[ROWS][COLS])
{
    int i;

    // Check if all enemies have been destroyed
    for (i = 0; i < COLS; i++)
    {
        if (board[0][i] == ENEMY_SYMBOL)
        {
            return false;
        }
    }

    return true;
}

/*
 * Function to check if player has lost the game
 */
bool gameLost(char board[ROWS][COLS])
{
    int i;

    // Check if any enemies have reached bottom of board
    for (i = 0; i < COLS; i++)
    {
        if (board[ROWS-1][i] == ENEMY_SYMBOL)
        {
            return true;
        }
    }

    return false;
}