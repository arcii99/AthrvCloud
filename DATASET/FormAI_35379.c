//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void clearScreen();
int rollDice();
void printBoard(char board[][COLS], int playerLoc);
void printGhosts(int ghostLoc1, int ghostLoc2);
void updateBoard(char board[][COLS], int playerLoc);
bool isGameOver(int playerLoc, int ghostLoc1, int ghostLoc2);
void printGameOver();

int main()
{
    char board[ROWS][COLS];
    int playerLoc = 0;
    int ghostLoc1 = 99;
    int ghostLoc2 = 99;
    int playerRoll = 0;
    
    // populate board with empty spaces
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
    
    // add ghost and player to board
    board[ROWS - 1][0] = 'P';
    board[0][COLS - 1] = 'G';
    
    // seed random number generator
    srand(time(NULL));
    
    // game loop
    while(!isGameOver(playerLoc, ghostLoc1, ghostLoc2))
    {
        // clear screen and print board
        clearScreen();
        printBoard(board, playerLoc);
        
        // roll dice and update player location
        playerRoll = rollDice();
        playerLoc += playerRoll;
        if(playerLoc >= ROWS * COLS)
        {
            playerLoc = ROWS * COLS - 1;
        }
        
        // update ghost locations
        ghostLoc1 -= (playerRoll / 2 + rollDice() % 2);
        if(ghostLoc1 < 0)
        {
            ghostLoc1 = 0;
        }
        ghostLoc2 -= (playerRoll / 3 + rollDice() % 2);
        if(ghostLoc2 < 0)
        {
            ghostLoc2 = 0;
        }
        
        // update board with new positions
        updateBoard(board, playerLoc);
        
        // print ghost positions
        printGhosts(ghostLoc1, ghostLoc2);
        
        // wait for user input before continuing
        printf("\nPress Enter to continue");
        getchar();
    }
    
    // print game over message
    clearScreen();
    printGameOver();
    
    return 0;
}

void clearScreen()
{
    system("clear"); // for Unix-based systems
}

int rollDice()
{
    return rand() % 6 + 1;
}

void printBoard(char board[][COLS], int playerLoc)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i * COLS + j == playerLoc)
            {
                printf("@");
            }
            else
            {
                printf("%c", board[i][j]);
            }
            
            printf("|");
        }
        printf("\n");
    }
}

void printGhosts(int ghostLoc1, int ghostLoc2)
{
    printf("\nGhost 1 is %d spaces away\n", ghostLoc1);
    printf("Ghost 2 is %d spaces away\n", ghostLoc2);
}

void updateBoard(char board[][COLS], int playerLoc)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i * COLS + j == playerLoc)
            {
                board[i][j] = 'P';
            }
            else if(board[i][j] != 'G')
            {
                board[i][j] = ' ';
            }
        }
    }
}

bool isGameOver(int playerLoc, int ghostLoc1, int ghostLoc2)
{
    return playerLoc == ROWS * COLS - 1 || playerLoc == ghostLoc1 || playerLoc == ghostLoc2;
}

void printGameOver()
{
    printf("GAME OVER\n");
    printf("You were unable to escape the haunted house\n");
    printf("Better luck next time!\n");
}