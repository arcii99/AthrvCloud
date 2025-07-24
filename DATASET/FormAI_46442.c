//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 4
#define COLS 4
#define TILES 8

// Define functions
void populateBoard(int board[ROWS][COLS], int gameTiles[TILES]);
void printBoard(int board[ROWS][COLS], int guesses[ROWS][COLS]);
void clearScreen();

int main()
{
    // Initialize variables
    int board[ROWS][COLS] = {{0}};
    int gameTiles[TILES] = {1, 1, 2, 2, 3, 3, 4, 4};
    int guesses[ROWS][COLS] = {{0}};
    int count = 0, row1 = 0, col1 = 0, row2 = 0, col2 = 0;
    
    // Seed random number generator
    srand(time(NULL));

    // Populate game board
    populateBoard(board, gameTiles);

    // Game loop
    while(count < TILES)
    {
        // Print game board and user's guesses so far
        printBoard(board, guesses);

        // Prompt user for first tile
        printf("Enter row number and column number of first tile:\n");
        scanf("%d %d", &row1, &col1);

        // Check if first tile is valid
        while(row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS || guesses[row1-1][col1-1] == 1)
        {
            printf("Invalid tile entered. Enter row number and column number of first tile:\n");
            scanf("%d %d", &row1, &col1);
        }

        // Mark first tile as guessed
        guesses[row1-1][col1-1] = 1;

        // Print game board and user's guesses so far
        printBoard(board, guesses);

        // Prompt user for second tile
        printf("Enter row number and column number of second tile:\n");
        scanf("%d %d", &row2, &col2);

        // Check if second tile is valid
        while(row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS || guesses[row2-1][col2-1] == 1 || (row1 == row2 && col1 == col2))
        {
            printf("Invalid tile entered. Enter row number and column number of second tile:\n");
            scanf("%d %d", &row2, &col2);
        }

        // Mark second tile as guessed
        guesses[row2-1][col2-1] = 1;

        // If tiles match, increment counter
        if(board[row1-1][col1-1] == board[row2-1][col2-1])
        {
            printf("Nice! Tiles match.\n");
            count++;
        }
        else
        {
            printf("Oops! Tiles don't match. Try again.\n");
            guesses[row1-1][col1-1] = 0;
            guesses[row2-1][col2-1] = 0;
        }

        clearScreen();
        
    }

    printf("Congratulations! You won the game!\n");

    return 0;
}

void populateBoard(int board[ROWS][COLS], int gameTiles[TILES])
{
    int i = 0, j = 0;
    
    // Shuffle the game tiles array
    for(i = 0; i < TILES; i++)
    {
        int randomIndex = rand() % TILES;
        int temp = gameTiles[i];
        gameTiles[i] = gameTiles[randomIndex];
        gameTiles[randomIndex] = temp;
    }
    
    // Assign random tiles to board
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j] = gameTiles[i*ROWS+j];
        }
    }
}

void printBoard(int board[ROWS][COLS], int guesses[ROWS][COLS])
{
    int i = 0, j = 0;
    
    // Print column numbers
    printf("   ");
    for(j = 1; j <= COLS; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    
    // Print row numbers and tiles
    for(i = 0; i < ROWS; i++)
    {
        printf("%d  ", i+1);
        for(j = 0; j < COLS; j++)
        {
            if(guesses[i][j] == 1) // If tile is guessed, print tile value
            {
                printf("%d ", board[i][j]);
            }
            else // If tile is not guessed, print question mark
            {
                printf("? ");
            }
        }
        printf("\n");
    }
}

void clearScreen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif
    #ifdef _WIN32
    system("cls");
    #endif
}