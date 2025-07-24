//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>

int board[3][3]; // 2D array to store the current state of the game board
int ai = 1; // The marker for the AI, 1 for X and 2 for O
int human = 2; // The marker for the human, opposite of AI's marker
int game_over = 0; // Flag to check if the game is over or not

/**
 * Displays the game board
 */
void print_board()
{
    printf("-------------\n");
    for(int i = 0; i < 3; i++)
    {
        printf("| ");
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                printf("  ");
            }
            else if(board[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("O ");
            }
            printf("| ");
        }
        printf("\n");
        printf("-------------\n");
    }
}

/**
 * Checks if the game is over by checking if the current board state has a winner or if the board is full
 * Returns 1 if game is over and 0 if game is not yet over
 */
int check_game_over()
{
    // Check rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
        {
            return 1;
        }
    }

    // Check columns
    for(int j = 0; j < 3; j++)
    {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != 0)
        {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
    {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
    {
        return 1;
    }

    // Check if board is full
    int full = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                full = 0;
                break;
            }
        }
        if(full == 0)
        {
            break;
        }
    }
    if(full == 1)
    {
        return 1;
    }

    return 0;
}

/**
 * Recursive function to simulate the AI's move
 * Uses the minimax algorithm to choose the best move for the AI
 * Returns the score for the current board state
 * Also updates the move array with the index of the best move
 */
int minimax(int depth, int player, int *move)
{
    // Check if game is over or if max depth has been reached
    if(check_game_over() == 1 || depth == 0)
    {
        int score = 0;
        if(check_game_over() == 1)
        {
            if(player == ai)
            {
                score = -10;
            }
            else
            {
                score = 10;
            }
        }
        return score;
    }

    int best_score;
    if(player == ai)
    {
        best_score = -100;
    }
    else
    {
        best_score = 100;
    }

    // Iterate over all possible moves
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                // Make the move
                board[i][j] = player;

                // Calculate the score for the move
                int score = minimax(depth - 1, 3 - player, move);

                // Undo the move
                board[i][j] = 0;

                // Update the best score based on player and depth level
                if(player == ai && score > best_score)
                {
                    best_score = score;
                    *move = i * 3 + j;
                }
                else if(player == human && score < best_score)
                {
                    best_score = score;
                }
            }
        }
    }

    return best_score;
}

/**
 * Gets the move from the human player and updates the board state
 */
void human_move()
{
    int row, col;
    printf("Your move! Enter row (1-3) and column (1-3): ");
    scanf("%d %d", &row, &col);
    while(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0)
    {
        printf("Invalid move! Enter row (1-3) and column (1-3): ");
        scanf("%d %d", &row, &col);
    }
    board[row-1][col-1] = human;
}

/**
 * The main game loop that alternates between human and AI moves until the game is over
 */
void play_game()
{
    print_board();
    while(game_over == 0)
    {
        if(ai == 1)
        {
            int move = -1;
            printf("AI thinking...\n");
            minimax(6, ai, &move);
            board[move/3][move%3] = ai;
            printf("AI moved to row %d, column %d\n", move/3+1, move%3+1);
            print_board();
        }
        else
        {
            human_move();
            print_board();
        }

        if(check_game_over() == 1)
        {
            game_over = 1;
            printf("Game over!\n");
        }

        // Switch turn between player and AI
        ai = 3 - ai;
        human = 3 - human;
    }
}

int main()
{
    printf("Welcome to Tic Tac Toe C AI Example Program!\n");
    play_game();
    return 0;
}