//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to print Tic-Tac-Toe board
void printBoard(char board[][COLS])
{
    printf("\n");

    for(int i = 0; i < ROWS; i++)
    {
        printf("\t\t\t");

        for(int j = 0; j < COLS; j++)
        {
            printf(" %c ", board[i][j]);

            if (j < 2)
            {
                printf("|");
            }
        }

        if(i < 2)
        {
            printf("\n\t\t\t-----------");
        }

        printf("\n");
    }
}

// Function to check if move is valid
int isValidMove(char board[][COLS], int row, int col)
{
    if(board[row][col] == ' ')
    {
        return 1;
    }

    printf("\t\t\tInvalid move! Please enter a valid move.\n");

    return 0;
}

// Function to check if game has been won
int hasWon(char board[][COLS], char player)
{
    for(int i = 0; i < ROWS; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    for(int i = 0; i < COLS; i++)
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

// Function to get the best possible move for the computer
void findBestMove(char board[][COLS], int *row, int *col)
{
    int bestScore = -1000;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == ' ')
            {
                board[i][j] = 'O';

                int score = minimax(board, 0, 0);

                board[i][j] = ' ';

                if(score > bestScore)
                {
                    bestScore = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}


// Function for Minimax algorithm
int minimax(char board[][COLS], int depth, int isMax)
{
    int score = evaluate(board);

    if(score == 10)
    {
        return score - depth;
    }

    if(score == -10)
    {
        return score + depth;
    }

    if(isMovesLeft(board) == 0)
    {
        return 0;
    }

    if(isMax)
    {
        int bestScore = -1000;

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'O';

                    bestScore = max(bestScore, minimax(board, depth+1, !isMax));

                    board[i][j] = ' ';
                }
            }
        }

        return bestScore;
    }
    else
    {
        int bestScore = 1000;

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = 'X';

                    bestScore = min(bestScore, minimax(board, depth+1, !isMax));

                    board[i][j] = ' ';
                }
            }
        }

        return bestScore;
    }
}

// Function to evaluate score of board
int evaluate(char board[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == 'O')
            {
                return 10;
            }
            else if(board[i][0] == 'X')
            {
                return -10;
            }
        }
    }

    for(int i = 0; i < COLS; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == 'O')
            {
                return 10;
            }
            else if(board[0][i] == 'X')
            {
                return -10;
            }
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == 'O')
        {
            return 10;
        }
        else if(board[0][0] == 'X')
        {
            return -10;
        }
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] == 'O')
        {
            return 10;
        }
        else if(board[0][2] == 'X')
        {
            return -10;
        }
    }

    return 0;
}

// Function to check if there are any moves left
int isMovesLeft(char board[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] == ' ')
            {
                return 1;
            }
        }
    }

    return 0;
}

//Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//Function to calculate the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}


int main()
{
    char board[ROWS][COLS] = { {' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '} };

    int row, col;

    srand(time(NULL));

    printf("\t\t\tWelcome to Tic-Tac-Toe!\n");
    printf("\t\t\t-----------------------\n");

    printBoard(board);

    // Randomly choose who will go first
    int first = rand() % 2;

    if(first == 0)
    {
        printf("\n\t\t\tYou will go first!\n");
    }
    else
    {
        printf("\n\t\t\tComputer will go first.\n");

        findBestMove(board, &row, &col);

        board[row][col] = 'O';

        printBoard(board);
    }

    int move = 1;

    while(isMovesLeft(board))
    {

        // Check if user's turn
        if(move % 2 == 1 && first == 0 || move % 2 == 0 && first == 1)
        {
            printf("\n\t\t\tYour Turn (X): ");
            scanf("%d %d", &row, &col);

            if(isValidMove(board, row, col))
            {
                board[row][col] = 'X';

                printBoard(board);

                move++;

                if(hasWon(board, 'X'))
                {
                    printf("\n\t\tCongratulations! You have won!\n");
                    return 0;
                }
            }
        }
        // Computer's turn
        else
        {
            printf("\n\t\t\tComputer's Turn (O):\n");

            findBestMove(board, &row, &col);

            board[row][col] = 'O';

            printBoard(board);

            move++;

            if(hasWon(board, 'O'))
            {
                printf("\n\t\t\tThe Computer has won! Better luck next time.\n");
                return 0;
            }
        }
    }

    printf("\n\t\t\tIt's a draw! Thanks for playing.\n");

    return 0;
}