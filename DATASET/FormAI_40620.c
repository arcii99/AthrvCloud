//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void displayBoard(int board[][BOARD_SIZE]);
void initializeBoard(int board[][BOARD_SIZE]);
void playerTurn(int board[][BOARD_SIZE], int player);
int checkWinCondition(int board[][BOARD_SIZE]);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int gameOver = 0;
    
    srand(time(NULL));
    
    // Initialize board
    initializeBoard(board);
    
    // Display empty board
    displayBoard(board);
    
    // Game loop
    while (!gameOver)
    {
        // Player's turn
        playerTurn(board, player);
        displayBoard(board);
        // Check win condition
        if (checkWinCondition(board))
        {
            printf("Player %d wins!", player);
            gameOver = 1;
        }
        // Switch player
        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}

void displayBoard(int board[][BOARD_SIZE])
{
    // Board colors: 0 - empty, 1 - player 1, 2 - player 2
    char colors[][10] = {"\033[0m", "\033[0;31m", "\033[0;32m"};
    
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%s %d %s", colors[board[i][j]], board[i][j], colors[0]);
        }
        printf("\n");
    }
    printf("\n");
}

void initializeBoard(int board[][BOARD_SIZE])
{
    // Fill board randomly with 0, 1, 2
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = rand() % 3;
        }
    }
}

void playerTurn(int board[][BOARD_SIZE], int player)
{
    int row, col;
    do
    {
        printf("Player %d's turn: ", player);
        scanf("%d %d", &row, &col);
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE);
    
    // Fill cell with player's number
    board[row][col] = player;
}

int checkWinCondition(int board[][BOARD_SIZE])
{
    // Check horizontal and vertical lines
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int horizontalCounter = 0;
        int verticalCounter = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            horizontalCounter += board[i][j];
            verticalCounter += board[j][i];
        }
        if (horizontalCounter == BOARD_SIZE || verticalCounter == BOARD_SIZE)
        {
            return 1;
        }
    }
    
    // Check diagonal lines
    int diagonalCounter = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        diagonalCounter += board[i][i];
    }
    if (diagonalCounter == BOARD_SIZE)
    {
        return 1;
    }
    
    diagonalCounter = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        diagonalCounter += board[i][BOARD_SIZE - 1 - i];
    }
    if (diagonalCounter == BOARD_SIZE)
    {
        return 1;
    }
    
    return 0;
}