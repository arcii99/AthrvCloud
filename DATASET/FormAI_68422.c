//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

struct gameBoard
{
    int board[SIZE][SIZE];
    int player;
};

void initializeBoard(struct gameBoard* board)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board->board[i][j] = -1;
        }
    }
    board->player = 0; // Player 1 goes first
}

void printBoard(struct gameBoard* board)
{
    printf("   0   1   2\n");

    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for(int j = 0; j < SIZE; j++)
        {
            if(board->board[i][j] == -1)
            {
                printf("  - ");
            }
            else if(board->board[i][j] == 0)
            {
                printf("  X ");
            }
            else if(board->board[i][j] == 1)
            {
                printf("  O ");
            }
        }
        printf("\n");
    }
}

bool makeMove(struct gameBoard* board, int row, int col)
{
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE)
    {
        return false;
    }
    else if(board->board[row][col] != -1)
    {
        return false;
    }

    board->board[row][col] = board->player; // Set the board position to the player's number
    board->player = !board->player; // Switch players

    return true;
}

bool isGameOver(struct gameBoard* board)
{
    // Check rows
    for(int i = 0; i < SIZE; i++)
    {
        bool rowEqual = true;
        for(int j = 1; j < SIZE; j++)
        {
            if(board->board[i][j] != board->board[i][0])
            {
                rowEqual = false;
            }
        }
        if(rowEqual && board->board[i][0] != -1)
        {
            return true;
        }
    }

    // Check columns
    for(int i = 0; i < SIZE; i++)
    {
        bool colEqual = true;
        for(int j = 1; j < SIZE; j++)
        {
            if(board->board[j][i] != board->board[0][i])
            {
                colEqual = false;
            }
        }
        if(colEqual && board->board[0][i] != -1)
        {
            return true;
        }
    }

    // Check diagonals
    bool diag1Equal = true;
    bool diag2Equal = true;
    for(int i = 1; i < SIZE; i++)
    {
        if(board->board[i][i] != board->board[0][0])
        {
            diag1Equal = false;
        }

        if(board->board[i][SIZE - 1 - i] != board->board[0][SIZE - 1])
        {
            diag2Equal = false;
        }
    }
    if(diag1Equal && board->board[0][0] != -1)
    {
        return true;
    }
    if(diag2Equal && board->board[0][SIZE - 1] != -1)
    {
        return true;
    }

    // Check if board is full
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board->board[i][j] == -1)
            {
                return false;
            }
        }
    }

    // If we get here, no winner and board is full
    return true;
}

int minimax(struct gameBoard* board, int depth, int alpha, int beta)
{
    if(isGameOver(board) || depth == 4)
    {
        // Evaluate static board score
        int score = 0;

        // Check rows
        for(int i = 0; i < SIZE; i++)
        {
            bool rowEqual = true;
            for(int j = 1; j < SIZE; j++)
            {
                if(board->board[i][j] != board->board[i][0])
                {
                    rowEqual = false;
                }
            }
            if(rowEqual)
            {
                if(board->board[i][0] == 1)
                {
                    score += 10;
                }
                else if(board->board[i][0] == 0)
                {
                    score -= 10;
                }
            }
        }

        // Check columns
        for(int i = 0; i < SIZE; i++)
        {
            bool colEqual = true;
            for(int j = 1; j < SIZE; j++)
            {
                if(board->board[j][i] != board->board[0][i])
                {
                    colEqual = false;
                }
            }
            if(colEqual)
            {
                if(board->board[0][i] == 1)
                {
                    score += 10;
                }
                else if(board->board[0][i] == 0)
                {
                    score -= 10;
                }
            }
        }

        // Check diagonals
        bool diag1Equal = true;
        bool diag2Equal = true;
        for(int i = 1; i < SIZE; i++)
        {
            if(board->board[i][i] != board->board[0][0])
            {
                diag1Equal = false;
            }

            if(board->board[i][SIZE - 1 - i] != board->board[0][SIZE - 1])
            {
                diag2Equal = false;
            }
        }
        if(diag1Equal)
        {
            if(board->board[0][0] == 1)
            {
                score += 10;
            }
            else if(board->board[0][0] == 0)
            {
                score -= 10;
            }
        }
        if(diag2Equal)
        {
            if(board->board[0][SIZE - 1] == 1)
            {
                score += 10;
            }
            else if(board->board[0][SIZE - 1] == 0)
            {
                score -= 10;
            }
        }

        return score;
    }

    if(board->player == 1)
    {
        // Maximizing
        int bestScore = -1000;
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(board->board[i][j] == -1)
                {
                    board->board[i][j] = 1;
                    board->player = 0;
                    int score = minimax(board, depth + 1, alpha, beta);
                    if(score > bestScore)
                    {
                        bestScore = score;
                    }
                    alpha = alpha > bestScore ? alpha : bestScore;
                    board->board[i][j] = -1;
                    board->player = 1;
                    if(beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
    else
    {
        // Minimizing
        int bestScore = 1000;
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(board->board[i][j] == -1)
                {
                    board->board[i][j] = 0;
                    board->player = 1;
                    int score = minimax(board, depth + 1, alpha, beta);
                    if(score < bestScore)
                    {
                        bestScore = score;
                    }
                    beta = beta < bestScore ? beta : bestScore;
                    board->board[i][j] = -1;
                    board->player = 0;
                    if(beta <= alpha)
                    {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
}

void makeAIMove(struct gameBoard* board)
{
    int bestRow = -1;
    int bestCol = -1;
    int bestScore = -1000;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board->board[i][j] == -1)
            {
                board->board[i][j] = 1;
                board->player = 0;
                int score = minimax(board, 0, -1000, 1000);
                if(score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
                board->board[i][j] = -1;
                board->player = 1;
            }
        }
    }

    board->board[bestRow][bestCol] = 1;
    board->player = 0;
}

int getUserMove(int* row, int* col)
{
    printf("Enter row and column to play (e.g. 0 2): ");
    int result = scanf("%d %d", row, col);
    while(result != 2 || *row < 0 || *row >= SIZE || *col < 0 || *col >= SIZE)
    {
        printf("Invalid input. Enter row and column to play (e.g. 0 2): ");
        while(getchar() != '\n'); // Clear input buffer
        result = scanf("%d %d", row, col);
    }

    return 0;
}

int main()
{
    struct gameBoard game;
    initializeBoard(&game);

    printf("Your marker is X. The computer's marker is O.\n");

    int row, col;
    while(!isGameOver(&game))
    {
        printBoard(&game);
        if(game.player == 0)
        {
            getUserMove(&row, &col);
            while(!makeMove(&game, row, col))
            {
                printf("Invalid move. Try again.\n");
                getUserMove(&row, &col);
            }
        }
        else
        {
            printf("Computer thinking...\n");
            makeAIMove(&game);
        }
    }

    printBoard(&game);
    if(minimax(&game, 0, -1000, 1000) > 0)
    {
        printf("You lost. Better luck next time.\n");
    }
    else
    {
        printf("Congratulations! You won!\n");
    }

    return 0;
}