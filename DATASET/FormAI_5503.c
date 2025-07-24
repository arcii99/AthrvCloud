//FormAI DATASET v1.0 Category: Chess AI ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define K 10000000

int evaluateBoard(int board[][8]);
int evaluatePiece(int piece, int row, int col);
int minimax(int depth, int alpha, int beta, int maximisingPlayer, int board[][8]);
void printBoard(int board[][8]);
void copyBoard(int from[][8], int to[][8]);

int main()
{
    int board[8][8] = {
        {-6, -5, -4, -3, -2, -4, -5, -6},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {6, 5, 4, 3, 2, 4, 5, 6}
    };

    printBoard(board);

    int bestMove[4];
    int score = minimax(3, INT_MIN, INT_MAX, 0, board);
    printf("Score: %d\n", score);
    printf("Best move: %d%d%d%d\n", bestMove[0], bestMove[1], bestMove[2], bestMove[3]);

    return 0;
}

// Evaluate the score of the board for the current player
int evaluateBoard(int board[][8])
{
    int score = 0;
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            score += evaluatePiece(board[row][col], row, col);
        }
    }
    return score;
}

// Evaluate the score of an individual piece based on its type and position
int evaluatePiece(int piece, int row, int col)
{
    switch(piece)
    {
        case -6:    // Black King
            return -K + row*8 + col;

        case -5:    // Black Queen
            return -900 + row*8 + col;

        case -4:    // Black Rook
            return -500 + row*8 + col;

        case -3:    // Black Bishop
            return -330 + row*8 + col;

        case -2:    // Black Knight
            return -320 + row*8 + col;

        case -1:    // Black Pawn
            return -100 + row*8 + col;

        case 0:     // Empty Space
            return 0;

        case 1:     // White Pawn
            return 100 + (7-row)*8 + col;

        case 2:     // White Knight
            return 320 + (7-row)*8 + col;

        case 3:     // White Bishop
            return 330 + (7-row)*8 + col;

        case 4:     // White Rook
            return 500 + (7-row)*8 + col;

        case 5:     // White Queen
            return 900 + (7-row)*8 + col;

        case 6:     // White King
            return K + (7-row)*8 + col;

        default:
            return 0;
    }
}

// Use the minimax algorithm to calculate the best move to make
int minimax(int depth, int alpha, int beta, int maximisingPlayer, int board[][8])
{
    if(depth == 0)
    {
        return evaluateBoard(board);
    }

    int bestScore;
    int bestMove[4];
    if(maximisingPlayer)
    {
        bestScore = INT_MIN;
        for(int row = 0; row < 8; row++)
        {
            for(int col = 0; col < 8; col++)
            {
                if(board[row][col] > 0)
                {
                    for(int destRow = 0; destRow < 8; destRow++)
                    {
                        for(int destCol = 0; destCol < 8; destCol++)
                        {
                            int destPiece = board[destRow][destCol];
                            int piece = board[row][col];
                            if(destPiece <= 0 && piece > 0)
                            {
                                // Temporary move
                                int tempBoard[8][8];
                                copyBoard(board, tempBoard);
                                tempBoard[destRow][destCol] = piece;
                                tempBoard[row][col] = 0;

                                int score = minimax(depth-1, alpha, beta, 0, tempBoard);
                                if(score > bestScore)
                                {
                                    bestScore = score;
                                    bestMove[0] = row;
                                    bestMove[1] = col;
                                    bestMove[2] = destRow;
                                    bestMove[3] = destCol;
                                }
                                alpha = alpha > score ? alpha : score;
                                if(beta <= alpha)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        bestScore = INT_MAX;
        for(int row = 0; row < 8; row++)
        {
            for(int col = 0; col < 8; col++)
            {
                if(board[row][col] < 0)
                {
                    for(int destRow = 0; destRow < 8; destRow++)
                    {
                        for(int destCol = 0; destCol < 8; destCol++)
                        {
                            int destPiece = board[destRow][destCol];
                            int piece = board[row][col];
                            if(destPiece >= 0 && piece < 0)
                            {
                                // Temporary move
                                int tempBoard[8][8];
                                copyBoard(board, tempBoard);
                                tempBoard[destRow][destCol] = piece;
                                tempBoard[row][col] = 0;

                                int score = minimax(depth-1, alpha, beta, 1, tempBoard);
                                if(score < bestScore)
                                {
                                    bestScore = score;
                                    bestMove[0] = row;
                                    bestMove[1] = col;
                                    bestMove[2] = destRow;
                                    bestMove[3] = destCol;
                                }
                                beta = beta < score ? beta : score;
                                if(beta <= alpha)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Return the best move
    for(int i = 0; i < 4; i++)
    {
        bestMove[i] += 1;
    }
    printf("Best move: %d%d%d%d\n", bestMove[0], bestMove[1], bestMove[2], bestMove[3]);
    return bestScore;
}

// Print the chess board
void printBoard(int board[][8])
{
    printf("  ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c ", 'a'+i);
    }
    printf("\n");
    for(int row = 0; row < 8; row++)
    {
        printf("%d ", 8-row);
        for(int col = 0; col < 8; col++)
        {
            switch(board[row][col])
            {
                case -6:
                    printf("K ");
                    break;
                case -5:
                    printf("Q ");
                    break;
                case -4:
                    printf("R ");
                    break;
                case -3:
                    printf("B ");
                    break;
                case -2:
                    printf("N ");
                    break;
                case -1:
                    printf("P ");
                    break;
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("p ");
                    break;
                case 2:
                    printf("n ");
                    break;
                case 3:
                    printf("b ");
                    break;
                case 4:
                    printf("r ");
                    break;
                case 5:
                    printf("q ");
                    break;
                case 6:
                    printf("k ");
                    break;
            }
        }
        printf("%d\n", 8-row);
    }
    printf("  ");
    for(int i = 0; i < 8; i++)
    {
        printf("%c ", 'a'+i);
    }
    printf("\n");
}

// Copy the contents of one board to another board
void copyBoard(int from[][8], int to[][8])
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            to[row][col] = from[row][col];
        }
    }
}