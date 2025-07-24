//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE '-'
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int minimax(char board[BOARD_SIZE][BOARD_SIZE], char player, int depth);
int evaluate(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player);

int main()
{
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                           {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                           {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};
    int turn_count = 0;
    char curr_player = PLAYER_X;
    int winner = 0;

    printf("Welcome to Tic Tac Toe!\n\n");

    while (turn_count < BOARD_SIZE*BOARD_SIZE && winner == 0)
    {
        print_board(board);
        int move;
        if (curr_player == PLAYER_X) // human player's turn
        {
            printf("It's your turn! Enter a number between 1-9 to place your X: ");
            while (1)
            {
                scanf("%d", &move);
                int row = (move - 1) / BOARD_SIZE;
                int col = (move - 1) % BOARD_SIZE;
                if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == EMPTY_SPACE)
                {
                        board[row][col] = curr_player;
                        turn_count++;
                        break;
                }
                else
                {
                    printf("Invalid move! Try again: ");
                }
            }
        }
        else // computer player's turn
        {
            printf("It's my turn! I'm thinking...\n\n");
            move = get_move(board, curr_player);
            int row = move / BOARD_SIZE;
            int col = move % BOARD_SIZE;
            board[row][col] = curr_player;
            turn_count++;
        }

        // see if there's a winner
        winner = evaluate(board);

        // switch turns
        if (curr_player == PLAYER_X)
        {
            curr_player = PLAYER_O;
        }
        else
        {
            curr_player = PLAYER_X;
        }
    }

    // print the final board and the winner (if any)
    print_board(board);
    if (winner == 1)
    {
        printf("\nCongratulations, human player! You win!\n");
    }
    else if (winner == -1)
    {
        printf("\nSorry, human player. The computer wins!\n");
    }
    else
    {
        printf("\nIt's a tie game!\n");
    }

    return 0;
}

// recursive function using minimax algorithm to determine optimal move
int minimax(char board[BOARD_SIZE][BOARD_SIZE], char player, int depth)
{
    int best_score = (player == PLAYER_X) ? -1 : 1;
    int curr_score;
    int winner = evaluate(board);

    if (winner != 0 || depth == 0)
    {
        return winner;
    }

    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
    {
        int row = i / BOARD_SIZE;
        int col = i % BOARD_SIZE;
        if (board[row][col] == EMPTY_SPACE)
        {
            board[row][col] = player;
            if (player == PLAYER_X)
            {
                curr_score = minimax(board, PLAYER_O, depth-1);
                if (curr_score > best_score)
                {
                    best_score = curr_score;
                }
            }
            else
            {
                curr_score = minimax(board, PLAYER_X, depth-1);
                if (curr_score < best_score)
                {
                    best_score = curr_score;
                }
            }
            board[row][col] = EMPTY_SPACE;
        }
    }

    return best_score;
}

// evaluate function to check if there's a winner
int evaluate(char board[BOARD_SIZE][BOARD_SIZE])
{
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] != EMPTY_SPACE && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] == PLAYER_X)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }

    // check columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] != EMPTY_SPACE && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] == PLAYER_X)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }

    // check diagonals
    if (board[0][0] != EMPTY_SPACE && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] == PLAYER_X)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if (board[0][2] != EMPTY_SPACE && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] == PLAYER_X)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    // check for tie
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPACE)
            {
                return 0;
            }
        }
    }

    return 2; // if all spaces are filled and nobody won, it's a tie
}

// function to print the current state of the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n   1   2   3\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE-1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE-1)
        {
            printf("  -----------\n");
        }
    }
    printf("\n");
}

// function to get the computer player's move using the minimax algorithm
int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    int best_score = (player == PLAYER_X) ? -1 : 1;
    int curr_score;
    int best_move = -1;

    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
    {
        int row = i / BOARD_SIZE;
        int col = i % BOARD_SIZE;
        if (board[row][col] == EMPTY_SPACE)
        {
            board[row][col] = player;
            if (player == PLAYER_X)
            {
                curr_score = minimax(board, PLAYER_O, 6); // depth of 6 for best performance
                if (curr_score > best_score)
                {
                    best_score = curr_score;
                    best_move = i;
                }
            }
            else
            {
                curr_score = minimax(board, PLAYER_X, 6);
                if (curr_score < best_score)
                {
                    best_score = curr_score;
                    best_move = i;
                }
            }
            board[row][col] = EMPTY_SPACE;
        }   
    }

    if (best_move == -1) // fallback in case no moves left
    {
        while (1)
        {
            int random_row = rand() % BOARD_SIZE;
            int random_col = rand() % BOARD_SIZE;
            if (board[random_row][random_col] == EMPTY_SPACE)
            {
                return random_row*BOARD_SIZE + random_col;
            }
        }
    }
    else
    {
        return best_move;
    }
}