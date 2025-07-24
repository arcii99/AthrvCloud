//FormAI DATASET v1.0 Category: Chess AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// headers for time
#include <time.h>

// constants
#define ROW 8
#define COL 8

// function prototypes
int evaluateBoard(int board[][COL], int player);
int minimax(int board[][COL], bool isMax, int depth, int alpha, int beta, int player);
bool isValidMove(int board[][COL], int row, int col, int player);
void makeMove(int board[][COL], int row, int col, int player);
void printBoard(int board[][COL]);

int main()
{
    srand(time(NULL)); // seed random number generator
    int board[ROW][COL] = {{0}}; // initialize board to all zeroes
    int turn = 1; // player 1 goes first
    bool gameRunning = true;
    int winner = 0;

    // print welcome message
    printf("Welcome to Energetic Chess AI!\n");

    while (gameRunning)
    {
        // print board
        printBoard(board);

        // check if any moves are possible
        bool noMovesPossible = true;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (isValidMove(board, i, j, turn))
                {
                    noMovesPossible = false;
                    break;
                }
            }
            if (!noMovesPossible)
            {
                break;
            }
        }

        if (noMovesPossible)
        {
            // no moves left, game over
            printf("Game over!\n");
            gameRunning = false;
            int player1Score = evaluateBoard(board, 1);
            int player2Score = evaluateBoard(board, 2);
            if (player1Score > player2Score)
            {
                winner = 1;
            }
            else if (player2Score > player1Score)
            {
                winner = 2;
            }
            else
            {
                winner = 0;
            }
            printf("Player %d wins with a score of %d to %d!\n", winner, player1Score, player2Score);
            break;
        }

        if (turn == 1)
        {
            // player 1's turn
            printf("Player 1's turn.\n");

            // get user input
            int row, col;
            printf("Enter row and column (e.g. '1 2'): ");
            scanf("%d %d", &row, &col);

            // check if move is valid
            if (isValidMove(board, row - 1, col - 1, turn))
            {
                // make move
                makeMove(board, row - 1, col - 1, turn);
            }
            else
            {
                // invalid move, try again
                printf("Invalid move. Try again.\n");
                continue;
            }
        }
        else
        {
            // player 2's turn
            printf("Player 2's turn.\n");

            // prompt AI to make a move
            printf("AI is thinking ...\n");

            // get best move for AI
            int bestScore = -1000;
            int bestRow = -1;
            int bestCol = -1;
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    if (isValidMove(board, i, j, turn))
                    {
                        // make move and evaluate board
                        int tempBoard[ROW][COL];
                        memcpy(tempBoard, board, ROW * COL * sizeof(int));
                        makeMove(tempBoard, i, j, turn);
                        int score = minimax(tempBoard, false, 3, -1000, 1000, turn);

                        // update best move
                        if (score > bestScore)
                        {
                            bestScore = score;
                            bestRow = i;
                            bestCol = j;
                        }
                    }
                }
            }

            // make best move
            makeMove(board, bestRow, bestCol, turn);
            printf("AI moved to row %d, column %d.\n", bestRow + 1, bestCol + 1);
        }

        // switch turns
        turn = (turn == 1) ? 2 : 1;
    }

    return 0;
}

// evaluate board for given player
int evaluateBoard(int board[][COL], int player)
{
    int score = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == player)
            {
                // add 1 for player's piece
                score++;
            }
            else if (board[i][j] != 0)
            {
                // subtract 1 for opponent's piece
                score--;
            }
        }
    }
    return score;
}

// recursive minimax function
int minimax(int board[][COL], bool isMax, int depth, int alpha, int beta, int player)
{
    // base case: depth limit reached or game over
    if (depth == 0 || evaluateBoard(board, 1) == 0 || evaluateBoard(board, 2) == 0)
    {
        return evaluateBoard(board, player);
    }

    // maximize the score for player 1 (AI)
    if (isMax)
    {
        int bestScore = -1000;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (isValidMove(board, i, j, 1))
                {
                    // make move and evaluate board
                    int tempBoard[ROW][COL];
                    memcpy(tempBoard, board, ROW * COL * sizeof(int));
                    makeMove(tempBoard, i, j, 1);
                    int score = minimax(tempBoard, false, depth - 1, alpha, beta, player);

                    // update best move
                    if (score > bestScore)
                    {
                        bestScore = score;
                    }

                    // update alpha value for pruning
                    alpha = (alpha > bestScore) ? alpha : bestScore;

                    // cut off branch if beta value is less than or equal to alpha value
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
    // minimize the score for player 2 (human)
    else
    {
        int bestScore = 1000;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (isValidMove(board, i, j, 2))
                {
                    // make move and evaluate board
                    int tempBoard[ROW][COL];
                    memcpy(tempBoard, board, ROW * COL * sizeof(int));
                    makeMove(tempBoard, i, j, 2);
                    int score = minimax(tempBoard, true, depth - 1, alpha, beta, player);

                    // update best move
                    if (score < bestScore)
                    {
                        bestScore = score;
                    }

                    // update beta value for pruning
                    beta = (beta < bestScore) ? beta : bestScore;

                    // cut off branch if beta value is less than or equal to alpha value
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
}

// check if given move is valid for given player
bool isValidMove(int board[][COL], int row, int col, int player)
{
    // must be an empty square
    if (board[row][col] != 0)
    {
        return false;
    }

    // check directions for opponent's pieces
    bool up = false, down = false, left = false, right = false;
    for (int i = row + 1; i < ROW; i++)
    {
        if (board[i][col] == player)
        {
            down = true;
            break;
        }
        else if (board[i][col] == 0)
        {
            break;
        }
    }
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == player)
        {
            up = true;
            break;
        }
        else if (board[i][col] == 0)
        {
            break;
        }
    }
    for (int j = col + 1; j < COL; j++)
    {
        if (board[row][j] == player)
        {
            right = true;
            break;
        }
        else if (board[row][j] == 0)
        {
            break;
        }
    }
    for (int j = col - 1; j >= 0; j--)
    {
        if (board[row][j] == player)
        {
            left = true;
            break;
        }
        else if (board[row][j] == 0)
        {
            break;
        }
    }

    // at least one direction must have opponent's piece
    if (!up && !down && !left && !right)
    {
        return false;
    }

    return true;
}

// make given move for given player
void makeMove(int board[][COL], int row, int col, int player)
{
    // place player's piece
    board[row][col] = player;

    // check directions for opponent's pieces
    bool up = false, down = false, left = false, right = false;
    for (int i = row + 1; i < ROW; i++)
    {
        if (board[i][col] == player)
        {
            down = true;
            break;
        }
        else if (board[i][col] == 0)
        {
            break;
        }
        else
        {
            board[i][col] = player;
        }
    }
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == player)
        {
            up = true;
            break;
        }
        else if (board[i][col] == 0)
        {
            break;
        }
        else
        {
            board[i][col] = player;
        }
    }
    for (int j = col + 1; j < COL; j++)
    {
        if (board[row][j] == player)
        {
            right = true;
            break;
        }
        else if (board[row][j] == 0)
        {
            break;
        }
        else
        {
            board[row][j] = player;
        }
    }
    for (int j = col - 1; j >= 0; j--)
    {
        if (board[row][j] == player)
        {
            left = true;
            break;
        }
        else if (board[row][j] == 0)
        {
            break;
        }
        else
        {
            board[row][j] = player;
        }
    }
}

// print current board state
void printBoard(int board[][COL])
{
    printf("    ");
    for (int j = 0; j < COL; j++)
    {
        printf("%d ", j + 1);
    }
    printf("\n");
    printf("  +");
    for (int j = 0; j < COL; j++)
    {
        printf("-+");
    }
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf(" %d|", i + 1);
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" |");
            }
            else if (board[i][j] == 1)
            {
                printf("X|");
            }
            else if (board[i][j] == 2)
            {
                printf("O|");
            }
        }
        printf("\n");
        printf("  +");
        for (int j = 0; j < COL; j++)
        {
            printf("-+");
        }
        printf("\n");
    }
}