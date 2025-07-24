//FormAI DATASET v1.0 Category: Chess AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#define BLACK 1
#define WHITE 0

int board[8][8] = {
    {-1, -2, -3, -4, -5, -3, -2, -1},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {6, 6, 6, 6, 6, 6, 6, 6},
    {1, 2, 3, 4, 5, 3, 2, 1}
};

int player = WHITE;
int maxDepth = 3;

int evaluateBoard()
{
    int i, j, score = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                score += 1;
            }
            else if (board[i][j] == 2)
            {
                score += 3;
            }
            else if (board[i][j] == 3 || board[i][j] == 5)
            {
                score += 3;
            }
            else if (board[i][j] == 4)
            {
                score += 5;
            }
            else if (board[i][j] == 6)
            {
                score += 9;
            }
            else if (board[i][j] == -1)
            {
                score -= 1;
            }
            else if (board[i][j] == -2)
            {
                score -= 3;
            }
            else if (board[i][j] == -3 || board[i][j] == -5)
            {
                score -= 3;
            }
            else if (board[i][j] == -4)
            {
                score -= 5;
            }
            else if (board[i][j] == -6)
            {
                score -= 9;
            }
        }
    }
    return score;
}

int miniMax(int depth, int alpha, int beta)
{
    if (depth == 0)
    {
        return evaluateBoard();
    }
    int i, j, currentScore, bestScore;
    if (player == WHITE)
    {
        bestScore = -9999;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (board[i][j] >= 0)
                {
                    continue;
                }
                if (board[i][j] == -6)
                {
                    printf("White King at: %d, %d\n", i, j);
                }
                int initial = board[i][j];
                board[i][j] = 0;
                if (board[i-1][j+1] >= 0)
                {
                    currentScore = miniMax(depth-1, alpha, beta);
                    if (currentScore > bestScore)
                    {
                        bestScore = currentScore;
                    }
                    if (bestScore > alpha)
                    {
                        alpha = bestScore;
                    }
                }
                board[i][j] = initial;
                if (beta <= alpha)
                {
                    return bestScore;
                }
            }
        }
    }
    else
    {
        bestScore = 9999;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (board[i][j] <= 0)
                {
                    continue;
                }
                if (board[i][j] == 6)
                {
                    printf("Black King at: %d, %d\n", i, j);
                }
                int initial = board[i][j];
                board[i][j] = 0;
                if (board[i+1][j+1] <= 0)
                {
                    currentScore = miniMax(depth-1, alpha, beta);
                    if (currentScore < bestScore)
                    {
                        bestScore = currentScore;
                    }
                    if (bestScore < beta)
                    {
                        beta = bestScore;
                    }
                }
                board[i][j] = initial;
                if (beta <= alpha)
                {
                    return bestScore;
                }
            }
        }
    }
    return bestScore;
}

int main()
{
    int i, j, bestScore, currentScore, initialX = -1, initialY = -1, finalX = -1, finalY = -1;
    printf("Board:\n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    while (1)
    {
        printf("Enter initial x: ");
        scanf("%d", &initialX);
        printf("Enter initial y: ");
        scanf("%d", &initialY);
        printf("Enter final x: ");
        scanf("%d", &finalX);
        printf("Enter final y: ");
        scanf("%d", &finalY);
        int initial = board[initialX][initialY];
        if (initial == 0)
        {
            printf("There is no piece at that position. Try again.\n");
            continue;
        }
        if ((initial > 0 && player == BLACK) || (initial < 0 && player == WHITE))
        {
            printf("That is not your piece. Try again.\n");
            continue;
        }
        int destination = board[finalX][finalY];
        if (destination > 0 && player == WHITE)
        {
            printf("That is your own piece. Try again.\n");
            continue;
        }
        if (destination < 0 && player == BLACK)
        {
            printf("That is your own piece. Try again.\n");
            continue;
        }
        if (abs(initial) == 1)
        {
            if (player == WHITE && finalX == initialX-1 && (finalY == initialY+1 || finalY == initialY-1))
            {
                board[finalX][finalY] = initial;
                board[initialX][initialY] = 0;
                player = BLACK;
            }
            else if (player == BLACK && finalX == initialX+1 && (finalY == initialY+1 || finalY == initialY-1))
            {
                board[finalX][finalY] = initial;
                board[initialX][initialY] = 0;
                player = WHITE;
            }
            else
            {
                printf("Invalid move. Try again.\n");
                continue;
            }
        }
        else if (abs(initial) == 2)
        {
            // Code for pawn moving two spaces
        }
        else if (abs(initial) == 3)
        {
            // Code for bishop
        }
        else if (abs(initial) == 4)
        {
            // Code for rook
        }
        else if (abs(initial) == 5)
        {
            // Code for queen
        }
        else if (abs(initial) == 6)
        {
            // Code for king
        }
        if (player == BLACK)
        {
            bestScore = miniMax(maxDepth, -9999, 9999);
            printf("Black's score: %d\n", bestScore);
            for (i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    if (board[i][j] <= 0)
                    {
                        continue;
                    }
                    if (board[i][j] == 6)
                    {
                        printf("Black King at: %d, %d\n", i, j);
                    }
                    int initial = board[i][j];
                    board[i][j] = 0;
                    if (board[i+1][j+1] <= 0)
                    {
                        currentScore = miniMax(maxDepth-1, -9999, 9999);
                        if (currentScore < bestScore)
                        {
                            bestScore = currentScore;
                            initialX = i;
                            initialY = j;
                            finalX = i+1;
                            finalY = j+1;
                        }
                    }
                    board[i][j] = initial;
                }
            }
            printf("Black's move: %d, %d to %d, %d\n", initialX, initialY, finalX, finalY);
            board[finalX][finalY] = board[initialX][initialY];
            board[initialX][initialY] = 0;
            player = WHITE;
        }
    }
    return 0;
}