//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int checkWin(char board[SIZE][SIZE], char player);
int evaluateBoard(char board[SIZE][SIZE], char player);
int minimax(char board[SIZE][SIZE], int depth, int isMaximizer, char player, int alpha, int beta);
void printBoard(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int move, char player);

int main()
{
    char board[SIZE][SIZE] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    int move;
    char player = 'X';

    while (1)
    {   
        printBoard(board);
        
        if (player == 'X')
        {
            printf("It's your turn, player %c. Enter a move (1-9): ", player);
            scanf("%d", &move);
            makeMove(board, move, player);
        }
        else
        {
            printf("It's the computer's turn. \n");
            move = minimax(board, 0, 1, player, -1000000, 1000000);
            makeMove(board, move, player);
        }

        if (checkWin(board, player))
        {
            printBoard(board);
            printf("Player %c has won!\n", player);
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';

        if (board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' &&
            board[1][0] != '_' && board[1][1] != '_' && board[1][2] != '_' &&
            board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_')
        {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

int checkWin(char board[SIZE][SIZE], char player)
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int evaluateBoard(char board[SIZE][SIZE], char player)
{
    int i, j, score = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == player)
            {
                if (i == 1 && j == 1)
                    score += 3;
                else if ((i == 0 && j == 0) || (i == 2 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 2))
                    score += 2;
                else
                    score += 1;
            }
        }
    }

    return score;
}

int minimax(char board[SIZE][SIZE], int depth, int isMaximizer, char player, int alpha, int beta)
{
    int i, j, score, maxScore = -1000, minScore = 1000, bestMove = -1;

    if (checkWin(board, 'X'))
        return -10;
    else if (checkWin(board, 'O'))
        return 10;
    else if (board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' &&
             board[1][0] != '_' && board[1][1] != '_' && board[1][2] != '_' &&
             board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_')
        return 0;
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                if (isMaximizer)
                {
                    board[i][j] = player;
                    score = minimax(board, depth + 1, !isMaximizer, player, alpha, beta);
                    board[i][j] = '_';
                    if (score > maxScore)
                    {   
                        maxScore = score;
                        bestMove = i * SIZE + j + 1;
                    }
                    alpha = alpha > maxScore ? alpha : maxScore;
                    if (beta <= alpha)
                        break;
                }
                else
                {
                    board[i][j] = player == 'X' ? 'O' : 'X';
                    score = minimax(board, depth + 1, !isMaximizer, player, alpha, beta);
                    board[i][j] = '_';
                    if (score < minScore)
                    {   
                        minScore = score;
                        bestMove = i * SIZE + j + 1;
                    }
                    beta = beta < minScore ? beta : minScore; 
                    if (beta <= alpha)
                        break;   
                }
            }
        }
    }

    if (isMaximizer)
        return bestMove;
    else
        return (player == 'X') ? minScore : maxScore;
}

void printBoard(char board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void makeMove(char board[SIZE][SIZE], int move, char player)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;

    board[row][col] = player;
}