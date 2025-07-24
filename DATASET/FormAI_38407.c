//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
int playerMove, computerMove;
char playerSymbol = 'x', computerSymbol = 'o';

void initializeBoard();
void displayBoard();
void getMoveFromPlayer();
void makeMove();
int isWinner(char symbol);
int minimax(int depth, int isMaximizing);
int getBestMove();

int main()
{
    printf("Welcome to Cyber Tic Tac Toe!\n");
    initializeBoard();
    displayBoard();
    while (1)
    {
        getMoveFromPlayer();
        makeMove();
        displayBoard();
        if (isWinner(playerSymbol))
        {
            printf("Congratulations, you won!\n");
            break;
        }
        if (isWinner(computerSymbol))
        {
            printf("Sorry, the computer won!\n");
            break;
        }
        computerMove = getBestMove();
        printf("The computer chooses position %d %d.\n", computerMove / 3, computerMove % 3);
        board[computerMove / 3][computerMove % 3] = computerSymbol;
        displayBoard();
        if (isWinner(playerSymbol))
        {
            printf("Congratulations, you won!\n");
            break;
        }
        if (isWinner(computerSymbol))
        {
            printf("Sorry, the computer won!\n");
            break;
        }
    }
    return 0;
}

void initializeBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

void displayBoard()
{
    int i, j;
    printf("   0 1 2\n");
    for (i = 0; i < 3; i++)
    {
        printf("%d  ", i);
        for (j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void getMoveFromPlayer()
{
    printf("Enter your move coordinates (row column): ");
    scanf("%d %d", &playerMove, &computerMove);
}

void makeMove()
{
    if (board[playerMove][computerMove] == '-')
    {
        board[playerMove][computerMove] = playerSymbol;
    }
}

int isWinner(char symbol)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return 1;
        }
    }
    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return 1;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return 1;
    }
    return 0;
}

int minimax(int depth, int isMaximizing)
{
    int i, j, score, bestScore;
    if (isWinner(playerSymbol))
    {
        return -10 + depth;
    }
    if (isWinner(computerSymbol))
    {
        return 10 - depth;
    }
    if (depth == 9)
    {
        return 0;
    }
    if (isMaximizing)
    {
        bestScore = -1000000;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = computerSymbol;
                    score = minimax(depth + 1, 0);
                    board[i][j] = '-';
                    if (score > bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
    else
    {
        bestScore = 1000000;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = playerSymbol;
                    score = minimax(depth + 1, 1);
                    board[i][j] = '-';
                    if (score < bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

int getBestMove()
{
    int i, j, score, bestScore = -1000000, bestMove = -1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = computerSymbol;
                score = minimax(0, 0);
                board[i][j] = '-';
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = 3 * i + j;
                }
            }
        }
    }
    return bestMove;
}