//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************
 * Function prototypes declaration *
 ***********************************/
void initializeBoard(int height, int width, char board[height][width]);
void printBoard(int height, int width, char board[height][width]);
void simulateMovement(int height, int width, char board[height][width], int *playerRow, int *playerCol, int *isRunning);

/******************************************
 * Main function implementation starts   *
 ******************************************/
int main(void)
{
    int height = 7;
    int width = 7;

    char board[height][width];

    int playerRow = 3;
    int playerCol = 3;

    int isRunning = 1;

    // Initialize the board with random values
    initializeBoard(height, width, board);

    // Set the seed for the random number generator
    srand(time(NULL));

    // Main game loop
    while (isRunning)
    {
        // Clear the screen
        system("clear");

        // Simulate the movement of the player
        simulateMovement(height, width, board, &playerRow, &playerCol, &isRunning);

        // Print the updated board
        printBoard(height, width, board);

        // Sleep for a short time
        usleep(100000);
    }

    // Print a game over message
    printf("Game Over!\n");

    return 0;
}

/***********************************
 * Function implementation details *
 ***********************************/
void initializeBoard(int height, int width, char board[height][width])
{
    int row, col;

    // Fill the board with random characters
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            // Randomly choose a character from a list of options
            switch (rand() % 5)
            {
                case 0:
                    board[row][col] = '.';
                    break;
                case 1:
                    board[row][col] = '#';
                    break;
                case 2:
                    board[row][col] = 'T';
                    break;
                case 3:
                    board[row][col] = 'S';
                    break;
                case 4:
                    board[row][col] = '?';
                    break;
            }
        }
    }

    // Place the player in the center of the board
    board[height/2][width/2] = 'P';
}

void printBoard(int height, int width, char board[height][width])
{
    int row, col;

    // Print the board
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void simulateMovement(int height, int width, char board[height][width], int *playerRow, int *playerCol, int *isRunning)
{
    int dx, dy;

    // Determine the destination row and column based on user input
    printf("Enter a direction (WASD): ");
    switch (getchar())
    {
        case 'W':
        case 'w':
            dx = -1;
            dy = 0;
            break;
        case 'A':
        case 'a':
            dx = 0;
            dy = -1;
            break;
        case 'S':
        case 's':
            dx = 1;
            dy = 0;
            break;
        case 'D':
        case 'd':
            dx = 0;
            dy = 1;
            break;
        default:
            dx = 0;
            dy = 0;
            break;
    }

    // Check if the player can move to the destination row and column
    if (*playerRow + dx < 0 || *playerRow + dx >= height || *playerCol + dy < 0 || *playerCol + dy >= width)
    {
        // Player cannot move off the board
    }
    else if (board[*playerRow + dx][*playerCol + dy] == '#')
    {
        // Player cannot move through walls
    }
    else if (board[*playerRow + dx][*playerCol + dy] == 'T')
    {
        // Player has encountered a trap
        printf("You fell into a trap!\n");
        *isRunning = 0;
    }
    else if (board[*playerRow + dx][*playerCol + dy] == 'S')
    {
        // Player has found a secret door
        printf("You found a secret door!\n");
        *isRunning = 0;
    }
    else if (board[*playerRow + dx][*playerCol + dy] == '?')
    {
        // Player has found a mystery item
        printf("You found a mysterious item!\n");
        *isRunning = 0;
    }
    else
    {
        // Player can move to the destination row and column
        board[*playerRow][*playerCol] = '.';
        *playerRow += dx;
        *playerCol += dy;
        board[*playerRow][*playerCol] = 'P';
    }

    // Consume any remaining input characters
    while (getchar() != '\n');
}