//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// The size of the board
#define BOARD_SIZE 3

// The empty position on the board
#define EMPTY_POSITION -1

// The player tokens
#define PLAYER_ONE_TOKEN 'X'
#define PLAYER_TWO_TOKEN 'O'

// The minimax algorithm constants
#define MAX_DEPTH INT_MAX
#define INITIAL_ALPHA INT_MIN
#define INITIAL_BETA INT_MAX

// The game board
int board[BOARD_SIZE][BOARD_SIZE];

// The AI move coordinates
int ai_move_row;
int ai_move_col;

// The function to print the board
void print_board()
{
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            switch(board[i][j]) 
            {
                case EMPTY_POSITION:
                    printf("[ ]");
                    break;
                case PLAYER_ONE_TOKEN:
                    printf("[X]");
                    break;
                case PLAYER_TWO_TOKEN:
                    printf("[O]");
                    break;
            }
        }
        printf("\n");
    }
}

// The function to check if the board position is available
bool is_position_available(int row, int col)
{
    return board[row][col] == EMPTY_POSITION;
}

// The function to get the available moves
bool get_available_moves(int available_moves[BOARD_SIZE * BOARD_SIZE][2], int *num_available_moves)
{
    *num_available_moves = 0;

    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (is_position_available(i, j)) 
            {
                available_moves[*num_available_moves][0] = i;
                available_moves[*num_available_moves][1] = j;
                (*num_available_moves)++;
            }
        }
    }

    return (*num_available_moves) > 0;
}

// The function to evaluate the game board for the minimax algorithm
int evaluate_board(int player)
{
    if (player == PLAYER_ONE_TOKEN) 
    {
        // Count the number of rows, columns and diagonals with two Xs and one empty position
        int two_x_one_empty_count = 0;

        for (int i = 0; i < BOARD_SIZE; i++) 
        {
            // Rows
            if ((board[i][0] == PLAYER_ONE_TOKEN && board[i][1] == PLAYER_ONE_TOKEN && board[i][2] == EMPTY_POSITION) ||
                (board[i][0] == EMPTY_POSITION && board[i][1] == PLAYER_ONE_TOKEN && board[i][2] == PLAYER_ONE_TOKEN) ||
                (board[i][0] == PLAYER_ONE_TOKEN && board[i][1] == EMPTY_POSITION && board[i][2] == PLAYER_ONE_TOKEN)) 
            {
                two_x_one_empty_count++;
            }

            // Columns
            if ((board[0][i] == PLAYER_ONE_TOKEN && board[1][i] == PLAYER_ONE_TOKEN && board[2][i] == EMPTY_POSITION) ||
                (board[0][i] == EMPTY_POSITION && board[1][i] == PLAYER_ONE_TOKEN && board[2][i] == PLAYER_ONE_TOKEN) ||
                (board[0][i] == PLAYER_ONE_TOKEN && board[1][i] == EMPTY_POSITION && board[2][i] == PLAYER_ONE_TOKEN)) 
            {
                two_x_one_empty_count++;
            }
        }

        // Diagonals
        if ((board[0][0] == PLAYER_ONE_TOKEN && board[1][1] == PLAYER_ONE_TOKEN && board[2][2] == EMPTY_POSITION) ||
            (board[0][0] == EMPTY_POSITION && board[1][1] == PLAYER_ONE_TOKEN && board[2][2] == PLAYER_ONE_TOKEN) ||
            (board[0][0] == PLAYER_ONE_TOKEN && board[1][1] == EMPTY_POSITION && board[2][2] == PLAYER_ONE_TOKEN)) 
        {
            two_x_one_empty_count++;
        }

        if ((board[0][2] == PLAYER_ONE_TOKEN && board[1][1] == PLAYER_ONE_TOKEN && board[2][0] == EMPTY_POSITION) ||
            (board[0][2] == EMPTY_POSITION && board[1][1] == PLAYER_ONE_TOKEN && board[2][0] == PLAYER_ONE_TOKEN) ||
            (board[0][2] == PLAYER_ONE_TOKEN && board[1][1] == EMPTY_POSITION && board[2][0] == PLAYER_ONE_TOKEN)) 
        {
            two_x_one_empty_count++;
        }

        return two_x_one_empty_count;
    }
    else if (player == PLAYER_TWO_TOKEN) 
    {
        // Count the number of rows, columns and diagonals with two Os and one empty position
        int two_o_one_empty_count = 0;

        for (int i = 0; i < BOARD_SIZE; i++) 
        {
            // Rows
            if ((board[i][0] == PLAYER_TWO_TOKEN && board[i][1] == PLAYER_TWO_TOKEN && board[i][2] == EMPTY_POSITION) ||
                (board[i][0] == EMPTY_POSITION && board[i][1] == PLAYER_TWO_TOKEN && board[i][2] == PLAYER_TWO_TOKEN) ||
                (board[i][0] == PLAYER_TWO_TOKEN && board[i][1] == EMPTY_POSITION && board[i][2] == PLAYER_TWO_TOKEN)) 
            {
                two_o_one_empty_count++;
            }

            // Columns
            if ((board[0][i] == PLAYER_TWO_TOKEN && board[1][i] == PLAYER_TWO_TOKEN && board[2][i] == EMPTY_POSITION) ||
                (board[0][i] == EMPTY_POSITION && board[1][i] == PLAYER_TWO_TOKEN && board[2][i] == PLAYER_TWO_TOKEN) ||
                (board[0][i] == PLAYER_TWO_TOKEN && board[1][i] == EMPTY_POSITION && board[2][i] == PLAYER_TWO_TOKEN)) 
            {
                two_o_one_empty_count++;
            }
        }

        // Diagonals
        if ((board[0][0] == PLAYER_TWO_TOKEN && board[1][1] == PLAYER_TWO_TOKEN && board[2][2] == EMPTY_POSITION) ||
            (board[0][0] == EMPTY_POSITION && board[1][1] == PLAYER_TWO_TOKEN && board[2][2] == PLAYER_TWO_TOKEN) ||
            (board[0][0] == PLAYER_TWO_TOKEN && board[1][1] == EMPTY_POSITION && board[2][2] == PLAYER_TWO_TOKEN)) 
        {
            two_o_one_empty_count++;
        }

        if ((board[0][2] == PLAYER_TWO_TOKEN && board[1][1] == PLAYER_TWO_TOKEN && board[2][0] == EMPTY_POSITION) ||
            (board[0][2] == EMPTY_POSITION && board[1][1] == PLAYER_TWO_TOKEN && board[2][0] == PLAYER_TWO_TOKEN) ||
            (board[0][2] == PLAYER_TWO_TOKEN && board[1][1] == EMPTY_POSITION && board[2][0] == PLAYER_TWO_TOKEN)) 
        {
            two_o_one_empty_count++;
        }

        return two_o_one_empty_count;
    }

    return 0;
}

// The minimax algorithm function
int minimax(int depth, int alpha, int beta, int player)
{
    // Check if the game is over
    int available_moves[BOARD_SIZE * BOARD_SIZE][2];
    int num_available_moves;

    if (!get_available_moves(available_moves, &num_available_moves)) 
    {
        return evaluate_board(PLAYER_TWO_TOKEN) - evaluate_board(PLAYER_ONE_TOKEN);
    }

    // Recursively explore the game tree
    if (depth == 0) 
    {
        return evaluate_board(PLAYER_TWO_TOKEN) - evaluate_board(PLAYER_ONE_TOKEN);
    }

    if (player == PLAYER_ONE_TOKEN) 
    {
        for (int i = 0; i < num_available_moves; i++) 
        {
            int row = available_moves[i][0];
            int col = available_moves[i][1];
            board[row][col] = player;
            int score = minimax(depth - 1, alpha, beta, PLAYER_TWO_TOKEN);
            board[row][col] = EMPTY_POSITION;
            if (score > alpha) 
            {
                alpha = score;
                if (depth == MAX_DEPTH) 
                {
                    ai_move_row = row;
                    ai_move_col = col;
                }
            }
            if (alpha >= beta) 
            {
                break;
            }
        }

        return alpha;
    }
    else if (player == PLAYER_TWO_TOKEN) 
    {
        for (int i = 0; i < num_available_moves; i++) 
        {
            int row = available_moves[i][0];
            int col = available_moves[i][1];
            board[row][col] = player;
            int score = minimax(depth - 1, alpha, beta, PLAYER_ONE_TOKEN);
            board[row][col] = EMPTY_POSITION;
            if (score < beta) 
            {
                beta = score;
            }
            if (alpha >= beta) 
            {
                break;
            }
        }

        return beta;
    }

    return 0;
}

// The function to make the AI move
void make_ai_move()
{
    ai_move_row = -1;
    ai_move_col = -1;

    minimax(MAX_DEPTH, INITIAL_ALPHA, INITIAL_BETA, PLAYER_ONE_TOKEN);

    board[ai_move_row][ai_move_col] = PLAYER_ONE_TOKEN;
    printf("\nThe AI moved to row %d, col %d.\n", ai_move_row + 1, ai_move_col + 1);
}

// The function for the main game loop
void game_loop()
{
    int current_player_token = PLAYER_ONE_TOKEN;

    while (true)
    {
        printf("Player %c's turn.\n", current_player_token);

        // Player's turn
        if (current_player_token == PLAYER_ONE_TOKEN) 
        {
            int row, col;
            do {
                printf("Enter the row and column of your move (e.g. 1 2): ");
                scanf("%d %d", &row, &col);
                row--;
                col--;
            } while (!is_position_available(row, col));

            board[row][col] = current_player_token;
        }
        // AI's turn
        else if (current_player_token == PLAYER_TWO_TOKEN) 
        {
            make_ai_move();
        }

        print_board();

        // Check if the game is over
        int available_moves[BOARD_SIZE * BOARD_SIZE][2];
        int num_available_moves;

        if (!get_available_moves(available_moves, &num_available_moves)) 
        {
            printf("The game is over.\n");
            return;
        }

        // Switch the current player token
        current_player_token = (current_player_token == PLAYER_ONE_TOKEN) ? PLAYER_TWO_TOKEN : PLAYER_ONE_TOKEN;
    }
}

// The main function
int main()
{
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            board[i][j] = EMPTY_POSITION;
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    game_loop();

    return 0;
}