//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Minesweeper game - data mining edition

// We're going to create a slightly different version of Minesweeper, where the user has to identify 'bomb'
// squares based purely on statistical data. This is where we use Data Mining techniques to get the job done.

// Constants
#define HEIGHT 10
#define WIDTH 20
#define NUM_BOMBS 15

// Global variables
char board[HEIGHT][WIDTH];
bool bombs[HEIGHT][WIDTH];
bool revealed[HEIGHT][WIDTH];

// Function prototypes
void generateBoard();
void layBombs();
void printBoard(bool showBombs);
void revealSquare(int row, int col);
bool isBomb(int row, int col);
int countAdjacentBombs(int row, int col);
bool isSafe(int row, int col);

int main()
{
    char choice;
    bool gameOver = false, gameWon = false;
    int remainingSquares = HEIGHT * WIDTH - NUM_BOMBS;
    int row, col;

    // Data Mining Section
    printf("\n\n*** Welcome to Data Mining: Bomb Identification edition! ***\n");
    printf("\n\nIn this game, you must identify where the bombs are using only statistical data.\n" );
    printf("\nThe board has %d hidden bombs. You need to identify them all to win the game.\n", NUM_BOMBS);

    generateBoard();
    layBombs();
    
    // Game loop
    do
    {
        printBoard(false);
        printf("\nEnter the coordinates of the square you want to check (row, col): ");
        scanf("%d %d", &row, &col);

        if (isBomb(row, col))
        {
            printf("\nOops! You have stepped on a bomb. Game over!\n");
            gameOver = true;
        }
        else if (revealed[row][col])
        {
            printf("\nYou have already checked this square. Please choose another.\n");
        }
        else
        {
            revealSquare(row, col);
            remainingSquares--;
            if (remainingSquares == 0)
            {
                gameWon = true;
                gameOver = true;
            }
            else
            {
                printf("\nYou have revealed %d squares. %d squares left to go!\n", (HEIGHT * WIDTH) - remainingSquares, remainingSquares);
            }
        }
    } while (!gameOver);

    printBoard(true);
    if (gameWon)
    {
        printf("\nCONGRATULATIONS! You have identified all the bombs. You are a Data Mining superstar!\n");
    }
    else
    {
        printf("\nGAME OVER! Better luck next time.\n");
    }

    return 0;
}

/**
 * @brief Generates a blank board.
 * 
 */
void generateBoard()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = '-';
        }
    }
}

/**
 * @brief Lays bombs randomly on the board.
 * 
 */
void layBombs()
{
    int bombsLaid = 0;
    int row, col;

    while (bombsLaid < NUM_BOMBS)
    {
        row = rand() % HEIGHT;
        col = rand() % WIDTH;

        if (!bombs[row][col])
        {
            bombs[row][col] = true;
            bombsLaid++;
        }
    }
}

/**
 * @brief Prints the current state of the board.
 * 
 * @param showBombs True if all bombs should be revealed.
 */
void printBoard(bool showBombs)
{
    printf("\n\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (bombs[i][j] && showBombs)
            {
                printf("B ");
            }
            else if (revealed[i][j])
            {
                printf("%d ", countAdjacentBombs(i, j));
            }
            else
            {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Recursively reveals adjacent squares until we hit a bomb or a square with adjacent bombs.
 * 
 * @param row Row number of the square to be revealed.
 * @param col Column number of the square to be revealed.
 */
void revealSquare(int row, int col)
{
    if (row < 0 || col < 0 || row >= HEIGHT || col >= WIDTH || revealed[row][col] || isBomb(row, col))
    {
        return;
    }

    revealed[row][col] = true;
    if (countAdjacentBombs(row, col) == 0)
    {
        revealSquare(row - 1, col - 1);
        revealSquare(row - 1, col);
        revealSquare(row - 1, col + 1);
        revealSquare(row, col - 1);
        revealSquare(row, col + 1);
        revealSquare(row + 1, col - 1);
        revealSquare(row + 1, col);
        revealSquare(row + 1, col + 1);
    }
}

/**
 * @brief Checks if the given square is a bomb.
 * 
 * @param row Row number of the square to be checked.
 * @param col Column number of the square to be checked.
 * @return True if the square contains a bomb, otherwise false.
 */
bool isBomb(int row, int col)
{
    return bombs[row][col];
}

/**
 * @brief Counts the number of bombs adjacent to the given square.
 * 
 * @param row Row number of the square to be checked.
 * @param col Column number of the square to be checked.
 * @return The number of bombs adjacent to the given square.
 */
int countAdjacentBombs(int row, int col)
{
    int count = 0;

    if (row > 0)
    {
        if (col > 0 && bombs[row - 1][col - 1])
        {
            count++;
        }
        if (bombs[row - 1][col])
        {
            count++;
        }
        if (col < WIDTH - 1 && bombs[row - 1][col + 1])
        {
            count++;
        }
    }

    if (col > 0 && bombs[row][col - 1])
    {
        count++;
    }
    if (col < WIDTH - 1 && bombs[row][col + 1])
    {
        count++;
    }

    if (row < HEIGHT - 1)
    {
        if (col > 0 && bombs[row + 1][col - 1])
        {
            count++;
        }
        if (bombs[row + 1][col])
        {
            count++;
        }
        if (col < WIDTH - 1 && bombs[row + 1][col + 1])
        {
            count++;
        }
    }

    return count;
}

/**
 * @brief Checks if the given square is safe to reveal.
 * 
 * @param row Row number of the square to be checked.
 * @param col Column number of the square to be checked.
 * @return True if the square is safe, otherwise false.
 */
bool isSafe(int row, int col)
{
    if (row < 0 || col < 0 || row >= HEIGHT || col >= WIDTH)
    {
        return false;
    }

    return !bombs[row][col] && !revealed[row][col];
}