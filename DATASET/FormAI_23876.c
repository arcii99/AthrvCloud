//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ROWS 3
#define COLUMNS 3
#define MAX_DEPTH 9

char board[ROWS][COLUMNS];

enum GameStatus {ongoing, x_wins, o_wins, draw};

//Initialization of board with empty spaces
void initializeBoard()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            board[i][j] = '-';
        }
    }
}

//Function to print the board to the console
void printBoard()
{
    for(int i=0; i<ROWS; i++)
    {
        printf("| ");
        for(int j=0; j<COLUMNS; j++)
        {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if a field is empty
bool isEmpty(int row, int column)
{
    if(board[row][column] == '-')
    {
        return true;
    }
    return false;
}

//Function to check if the board is full
bool isFull()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

//Function to check if a player has won
bool checkWin(char player)
{
    //Check rows
    for(int i=0; i<ROWS; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    //Check columns
    for(int j=0; j<COLUMNS; j++)
    {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    //Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

//Function to check the status of the game
enum GameStatus checkGameStatus()
{
    if(checkWin('X'))
    {
        return x_wins;
    }
    if(checkWin('O'))
    {
        return o_wins;
    }
    if(isFull())
    {
        return draw;
    }
    return ongoing;
}

//Function to generate a random move for the computer
int getRandomNumber()
{
    srand(time(NULL));
    int randomNumber = rand() % 3;
    return randomNumber;
}

//Function to calculate the score of the board
int calculateScore()
{
    if(checkWin('X'))
    {
        return 10;
    }

    if(checkWin('O'))
    {
        return -10;
    }

    return 0;
}

//Function to make a move on the board
void makeMove(int row, int column, char player)
{
    board[row][column] = player;
}

//Function to undo a move on the board
void undoMove(int row, int column)
{
    board[row][column] = '-';
}

//Function to find the best move for the computer
int findBestMove(int depth, char player, int alpha, int beta)
{
    int bestScore;
    int row = -1;
    int column = -1;

    if(depth == MAX_DEPTH || checkGameStatus() != ongoing)
    {
        return calculateScore();
    }

    if(player == 'X')
    {
        bestScore = -100;

        for(int i=0; i<ROWS; i++)
        {
            for(int j=0; j<COLUMNS; j++)
            {
                if(isEmpty(i, j))
                {
                    makeMove(i, j, player);
                    int score = findBestMove(depth+1, 'O', alpha, beta);
                    undoMove(i, j);

                    if(score > bestScore)
                    {
                        bestScore = score;
                        row = i;
                        column = j;
                    }

                    if(bestScore > alpha)
                    {
                        alpha = bestScore;
                    }

                    if(beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
    }
    else
    {
        bestScore = 100;

        for(int i=0; i<ROWS; i++)
        {
            for(int j=0; j<COLUMNS; j++)
            {
                if(isEmpty(i,j))
                {
                    makeMove(i, j, player);
                    int score = findBestMove(depth+1, 'X', alpha, beta);
                    undoMove(i, j);

                    if(score < bestScore)
                    {
                        bestScore = score;
                        row = i;
                        column = j;
                    }

                    if(bestScore < beta)
                    {
                        beta = bestScore;
                    }

                    if(beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
    }

    if(depth == 0)
    {
        makeMove(row, column, player);
    }

    return bestScore;
}

//Function for the computer move
void computerMove()
{
    int bestScore = -1000;
    int row = -1;
    int column = -1;

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(isEmpty(i, j))
            {
                makeMove(i, j, 'X');
                int score = findBestMove(0, 'O', -1000, 1000);
                undoMove(i, j);

                if(score > bestScore)
                {
                    bestScore = score;
                    row = i;
                    column = j;
                }
            }
        }
    }

    makeMove(row, column, 'X');
    printf("Computer has made its move: \n");
    sleep(2);
}

//Main function to run the game
int main()
{   
    initializeBoard();

    while(checkGameStatus() == ongoing)
    {
        printf("Current board status: \n");
        printBoard();

        int row, column;
        printf("Enter row and column for your move (ex: 2 1): ");
        scanf("%d%d", &row, &column);

        while(row<1 || row>3 || column<1 || column>3 || !isEmpty(row-1,column-1))
        {
            printf("Invalid move! Enter row and column again: ");
            scanf("%d%d", &row, &column);
        }
        makeMove(row-1, column-1, 'O');

        if(checkGameStatus() != ongoing)
        {
            break;
        }

        computerMove();
    }

    printf("Final board status: \n");
    printBoard();

    if(checkGameStatus() == x_wins)
    {
        printf("Computer wins!\n");
    }
    else if(checkGameStatus() == o_wins)
    {
        printf("You win!\n");
    }
    else
    {
        printf("Draw!\n");
    }

    return 0;
}