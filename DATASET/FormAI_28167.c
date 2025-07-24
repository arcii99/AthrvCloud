//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21 // number of rows
#define COLS 21 // number of columns

// function prototypes
void initializeBoard(char board[][COLS], int *pacmanX, int *pacmanY);
void printBoard(char board[][COLS]);
void updateBoard(char board[][COLS], int pacmanX, int pacmanY, int *score);
void movePacman(char board[][COLS], int *pacmanX, int *pacmanY, char input, int *score);

int main()
{
    char board[ROWS][COLS]; // game board
    int pacmanX, pacmanY; // pacman's coordinates
    int score = 0; // current score
    char input; // user input

    srand(time(NULL)); // initialize random seed

    initializeBoard(board, &pacmanX, &pacmanY); // initialize board

    // game loop
    while (1)
    {
        printBoard(board); // print current board
        printf("\nScore: %d\n", score); // print score

        printf("\nEnter direction (w,a,s,d): ");
        scanf(" %c", &input); // take user input

        movePacman(board, &pacmanX, &pacmanY, input, &score); // move pacman
        updateBoard(board, pacmanX, pacmanY, &score); // update board
    }

    return 0;
}

// initializes the game board and pacman's position
void initializeBoard(char board[][COLS], int *pacmanX, int *pacmanY)
{
    int i, j;

    // initialize board with dots and walls
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) // add walls
                board[i][j] = '#';
            else
                board[i][j] = '.'; // add dots
        }
    }

    // randomly place pacman on the board
    do {
        *pacmanX = rand() % ROWS;
        *pacmanY = rand() % COLS;
    } while (board[*pacmanX][*pacmanY] == '#');

    board[*pacmanX][*pacmanY] = 'C'; // add pacman to board
}

// prints the current game board
void printBoard(char board[][COLS])
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

// updates the game board based on pacman's movement and current score
void updateBoard(char board[][COLS], int pacmanX, int pacmanY, int *score)
{
    if (board[pacmanX][pacmanY] == '.') // if pacman is on a dot
    {
        *score += 10; // increase score
        board[pacmanX][pacmanY] = 'C'; // update board
    }
    else if (board[pacmanX][pacmanY] == '#') // if pacman hits a wall
    {
        printf("\nGame Over! Final Score: %d\n", *score); // end game
        exit(0);
    }
    else // pacman is on an already eaten dot or pacman
    {
        board[pacmanX][pacmanY] = 'C'; // update board
    }
}

// moves pacman in the input direction and updates its coordinates and current score
void movePacman(char board[][COLS], int *pacmanX, int *pacmanY, char input, int *score)
{
    int tempX = *pacmanX, tempY = *pacmanY;

    switch (input)
    {
        case 'w':
            tempX--;
            break;
        case 'a':
            tempY--;
            break;
        case 's':
            tempX++;
            break;
        case 'd':
            tempY++;
            break;
        default:
            printf("\nInvalid input! Try again.\n");
            break;
    }

    // check if move is valid
    if (board[tempX][tempY] != '#')
    {
        board[*pacmanX][*pacmanY] = '.'; // remove pacman from previous position
        *pacmanX = tempX; // update coordinates
        *pacmanY = tempY;
    }
}