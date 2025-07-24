//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Board size
#define BOARD_SIZE 3

//AI Player and Human Player
#define AI_PLAYER 'O'
#define HUMAN_PLAYER 'X'

//Empty cell marker
#define EMPTY_CELL ' '

//Function prototypes
void drawBoard(char board[BOARD_SIZE][BOARD_SIZE]); //To print the game board
bool checkForWin(char board[BOARD_SIZE][BOARD_SIZE], char player); //To check for winning condition
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool isMaximizingPlayer);
int getBestMove(char board[BOARD_SIZE][BOARD_SIZE]);

//Main function
int main()
{
    //Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
        {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL}
    };

    //Variable declaration
    bool gameOver = false; //To check if game over
    bool isHumanTurn = true; //To check if it is human's turn
    int moveCount = 0; //To count moves played
    int rowIndex, colIndex; //To hold row and column index of input from human player

    printf("\nWelcome to Tic Tac Toe!\n\n");

    //Game loop
    while (!gameOver)
    {
        //Draw the board
        drawBoard(board);

        if (isHumanTurn)
        {
            //Human's turn
            printf("\nIt's your turn, please enter the row index (0-2): ");
            scanf("%d", &rowIndex);
            printf("\nPlease enter the col index (0-2): ");
            scanf("%d", &colIndex);

            //Validate input
            if (rowIndex < 0 || rowIndex > 2 || colIndex < 0 || colIndex > 2 || board[rowIndex][colIndex] != EMPTY_CELL)
            {
                printf("\nInvalid move! Please try again.\n");
                continue;
            }

            //Update board
            board[rowIndex][colIndex] = HUMAN_PLAYER;
            moveCount++;

            //Check for winning condition
            if (checkForWin(board, HUMAN_PLAYER))
            {
                drawBoard(board);
                printf("\nCongratulations! You have won the game!\n");
                gameOver = true;
            }
        }
        else
        {
            //AI's turn
            printf("\nAI is thinking...\n");
            int bestMove = getBestMove(board);

            //Update board
            rowIndex = bestMove / 3;
            colIndex = bestMove % 3;
            board[rowIndex][colIndex] = AI_PLAYER;
            moveCount++;

            //Check for winning condition
            if (checkForWin(board, AI_PLAYER))
            {
                drawBoard(board);
                printf("\nSorry, you have lost the game!\n");
                gameOver = true;
            }
        }

        //Check for tie condition
        if (moveCount == BOARD_SIZE * BOARD_SIZE && !gameOver)
        {
            drawBoard(board);
            printf("\nThe game is tied!\n");
            gameOver = true;
        }

        //Switch turn
        isHumanTurn = !isHumanTurn;
    }

    return 0;
}

/**
 * Function to draw the game board
 */
void drawBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\t    ");
        
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c", board[i][j]);
            
            if (j != BOARD_SIZE - 1)
            {
                printf("|");
            }
        }

        printf("\n");

        if (i != BOARD_SIZE - 1)
        {
            printf("\t    -----\n");
        }
    }

    printf("\n");
}

/**
 * Function to check for winning condition
 */
bool checkForWin(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    //Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    //Check columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    //Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

/**
 * Minimax algorithm
 */
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool isMaximizingPlayer)
{
    //Evaluate board
    if (checkForWin(board, AI_PLAYER))
    {
        return 10 - depth;
    }
    else if (checkForWin(board, HUMAN_PLAYER))
    {
        return depth - 10;
    }
    else if (depth == BOARD_SIZE * BOARD_SIZE)
    {
        return 0;
    }

    int minmaxValue;

    if (isMaximizingPlayer)
    {
        //Maximizing player (AI)
        minmaxValue = -1000;

        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY_CELL)
                {
                    board[i][j] = AI_PLAYER;
                    int currentValue = minimax(board, depth + 1, false);
                    board[i][j] = EMPTY_CELL;

                    if (currentValue > minmaxValue)
                    {
                        minmaxValue = currentValue;
                    }
                }
            }
        }
    }
    else
    {
        //Minimizing player (Human)
        minmaxValue = 1000;

        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY_CELL)
                {
                    board[i][j] = HUMAN_PLAYER;
                    int currentValue = minimax(board, depth + 1, true);
                    board[i][j] = EMPTY_CELL;

                    if (currentValue < minmaxValue)
                    {
                        minmaxValue = currentValue;
                    }
                }
            }
        }
    }

    return minmaxValue;
}

/**
 * Function to get the best move for AI player using minimax algorithm
 */
int getBestMove(char board[BOARD_SIZE][BOARD_SIZE])
{
    int bestValue = -1000;
    int bestMove = -1;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_CELL)
            {
                board[i][j] = AI_PLAYER;
                int currentValue = minimax(board, 0, false);
                board[i][j] = EMPTY_CELL;

                if (currentValue > bestValue)
                {
                    bestValue = currentValue;
                    bestMove = i * 3 + j;
                }
            }
        }
    }

    return bestMove;
}