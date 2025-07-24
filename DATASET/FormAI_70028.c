//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void initialize_board(char board[3][3]);
void display_board(char board[3][3]);
bool make_move(char board[3][3], int row, int col, char player);
char get_winner(char board[3][3]);
int get_score(char board[3][3], int depth);
int minimax(char board[3][3], int depth, bool maximizing_player);
int find_best_move(char board[3][3]);

int main()
{
    // Initialize variables
    char board[3][3];
    int row, col;
    bool player_turn = true;

    // Initialize board
    initialize_board(board);
    display_board(board);

    // Main game loop
    while (true)
    {
        // Player's turn
        if (player_turn)
        {
            printf("Enter row and column to make move (player X): ");
            scanf("%d %d", &row, &col);

            // Make player move
            if (!make_move(board, row, col, 'X'))
            {
                printf("Invalid move! Try again.\n");
                continue;
            }
        }
        // AI's turn
        else
        {
            printf("AI making a move (player O)...\n");

            // Find best move and make it
            int best_move = find_best_move(board);
            row = best_move / 3;
            col = best_move % 3;
            make_move(board, row, col, 'O');
        }

        // Display board and check for winner
        display_board(board);
        char winner = get_winner(board);
        if (winner != ' ')
        {
            printf("%c wins!\n", winner);
            break;
        }

        // Toggle player turn
        player_turn = !player_turn;
    }

    return 0;
}

// Initialize board to empty spaces
void initialize_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Display board
void display_board(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
            if (j != 2) printf("|"); // Print vertical line except for last column
        }
        printf("\n");
        if (i != 2) printf("-+-+-\n"); // Print horizontal line except for last row
    }
    printf("\n");
}

// Check if move is valid and make move on board
bool make_move(char board[3][3], int row, int col, char player)
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        return false; // Move is out of bounds
    }
    if (board[row][col] != ' ')
    {
        return false; // Square is already occupied
    }
    board[row][col] = player;
    return true;
}

// Check for winner (returns ' ' if no winner)
char get_winner(char board[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }

    return ' '; // No winner
}

// Get score of board (for AI heuristic)
int get_score(char board[3][3], int depth)
{
    char winner = get_winner(board);
    if (winner == 'X') return -10 + depth; // Player X wins
    if (winner == 'O') return 10 - depth; // Player O wins
    return 0; // Tie game
}

// Minimax algorithm for AI move selection
int minimax(char board[3][3], int depth, bool maximizing_player)
{
    // Base case: board is terminal (there is a winner or tie)
    char winner = get_winner(board);
    if (winner != ' ') return get_score(board, depth);

    // Recursive case: board is not terminal
    int best_score;
    if (maximizing_player) // AI's turn (maximize score)
    {
        best_score = -1000; // Initialize to a very negative score
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    if (score > best_score)
                    {
                        best_score = score;
                    }
                }
            }
        }
    }
    else // Player's turn (minimize score)
    {
        best_score = 1000; // Initialize to a very positive score
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    if (score < best_score)
                    {
                        best_score = score;
                    }
                }
            }
        }
    }

    return best_score; // Return best score found for current player
}

// Find best AI move using minimax algorithm
int find_best_move(char board[3][3])
{
    int best_move = -1;
    int best_score = -1000; // Initialize to a very negative score
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int score = minimax(board, 0, false);
                board[i][j] = ' ';
                if (score > best_score)
                {
                    best_move = 3 * i + j; // Convert row and column to single integer for convenience
                    best_score = score;
                }
            }
        }
    }
    return best_move; // Return best move found using minimax algorithm
}