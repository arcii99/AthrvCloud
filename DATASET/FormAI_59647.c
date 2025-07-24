//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Constants
#define ROWS 3
#define COLUMNS 3
#define PLAYER_TOKEN 'X'
#define AI_TOKEN 'O'
#define EMPTY_SLOT '-'

// Function prototypes
void create_board(char board[][COLUMNS]);
void display_board(char board[][COLUMNS]);
int check_win(char board[][COLUMNS], char token);
int check_horizontal(char board[][COLUMNS], char token);
int check_vertical(char board[][COLUMNS], char token);
int check_diagonal(char board[][COLUMNS], char token);
int minimax(char board[][COLUMNS], int depth, int alpha, int beta, int is_maximizing);
int get_best_move(char board[][COLUMNS]);
int get_player_move(char board[][COLUMNS]);

// Main function
int main()
{
    char board[ROWS][COLUMNS];
    int game_over = 0;
    int player_turn = 1;

    create_board(board);

    while (!game_over)
    {
        display_board(board);

        if (player_turn)
        {
            int player_move = get_player_move(board);
            board[player_move / COLUMNS][player_move % COLUMNS] = PLAYER_TOKEN;

            if (check_win(board, PLAYER_TOKEN))
            {
                printf("Player wins!\n");
                game_over = 1;
            }

            player_turn = 0;
        }
        else
        {
            int ai_move = get_best_move(board);
            board[ai_move / COLUMNS][ai_move % COLUMNS] = AI_TOKEN;

            if (check_win(board, AI_TOKEN))
            {
                printf("AI wins!\n");
                game_over = 1;
            }

            player_turn = 1;
        }

        // Check for tie
        int empty_spots = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] == EMPTY_SLOT)
                {
                    empty_spots++;
                }
            }
        }

        if (empty_spots == 0)
        {
            printf("Tie game!\n");
            game_over = 1;
        }
    }

    display_board(board);

    return 0;
}

// Function to create new board
void create_board(char board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = EMPTY_SLOT;
        }
    }
}

// Function to display board
void display_board(char board[][COLUMNS])
{
    printf("-------------\n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("| ");
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }

    printf("-------------\n");
}

// Function to check for a win
int check_win(char board[][COLUMNS], char token)
{
    if (check_horizontal(board, token) || check_vertical(board, token) || check_diagonal(board, token))
    {
        return 1;
    }

    return 0;
}

// Function to check for a horizontal win
int check_horizontal(char board[][COLUMNS], char token)
{
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == token && board[i][1] == token && board[i][2] == token)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check for a vertical win
int check_vertical(char board[][COLUMNS], char token)
{
    for (int i = 0; i < COLUMNS; i++)
    {
        if (board[0][i] == token && board[1][i] == token && board[2][i] == token)
        {
            return 1;
        }
    }

    return 0;
}

// Function to check for a diagonal win
int check_diagonal(char board[][COLUMNS], char token)
{
    if (board[0][0] == token && board[1][1] == token && board[2][2] == token)
    {
        return 1;
    }

    if (board[0][2] == token && board[1][1] == token && board[2][0] == token)
    {
        return 1;
    }

    return 0;
}

// Function implementing minimax algorithm
int minimax(char board[][COLUMNS], int depth, int alpha, int beta, int is_maximizing)
{
    if (check_win(board, AI_TOKEN))
    {
        return 10 - depth;
    }

    if (check_win(board, PLAYER_TOKEN))
    {
        return depth - 10;
    }

    // Check for tie
    int empty_spots = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == EMPTY_SLOT)
            {
                empty_spots = 1;
            }
        }
    }

    if (!empty_spots)
    {
        return 0;
    }

    if (is_maximizing)
    {
        int best_score = -1000;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] == EMPTY_SLOT)
                {
                    board[i][j] = AI_TOKEN;
                    int score = minimax(board, depth + 1, alpha, beta, 0);
                    board[i][j] = EMPTY_SLOT;
                    if (score > best_score)
                    {
                        best_score = score;
                    }
                    if (score > alpha)
                    {
                        alpha = score;
                    }
                    if (alpha >= beta)
                    {
                        return best_score;
                    }
                }
            }
        }

        return best_score;
    }
    else
    {
        int best_score = 1000;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] == EMPTY_SLOT)
                {
                    board[i][j] = PLAYER_TOKEN;
                    int score = minimax(board, depth + 1, alpha, beta, 1);
                    board[i][j] = EMPTY_SLOT;
                    if (score < best_score)
                    {
                        best_score = score;
                    }
                    if (score < beta)
                    {
                        beta = score;
                    }
                    if (alpha >= beta)
                    {
                        return best_score;
                    }
                }
            }
        }

        return best_score;
    }
}

// Function to get AI's best move using minimax algorithm
int get_best_move(char board[][COLUMNS])
{
    int best_move = -1;
    int best_score = -1000;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == EMPTY_SLOT)
            {
                board[i][j] = AI_TOKEN;
                int score = minimax(board, 0, -1000, 1000, 0);
                board[i][j] = EMPTY_SLOT;
                if (score > best_score)
                {
                    best_score = score;
                    best_move = i * COLUMNS + j;
                }
            }
        }
    }

    return best_move;
}

// Function to get player's move
int get_player_move(char board[][COLUMNS])
{
    int move = -1;

    while (move < 0 || move > 8 || board[move / COLUMNS][move % COLUMNS] != EMPTY_SLOT)
    {
        printf("Enter your move (0-8): ");
        scanf("%d", &move);
    }

    return move;
}