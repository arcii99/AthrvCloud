//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9

int evaluate(char board[BOARD_SIZE][BOARD_SIZE])
{
    // TODO: Implement evaluation function to determine the score of the board state
    return 0;
}

int get_best_move(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing)
{
    int best_score = is_maximizing ? -1000 : 1000;
    int best_move = -1;

    // Check if the game is over or the maximum depth has been reached
    int score = evaluate(board);
    if (score != 0 || depth == MAX_DEPTH)
    {
        return score;
    }

    // Loop through all possible moves and evaluate them recursively
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        int row = i / BOARD_SIZE;
        int col = i % BOARD_SIZE;

        if (board[row][col] == ' ')
        {
            board[row][col] = is_maximizing ? 'x' : 'o';
            int move_score = get_best_move(board, depth + 1, !is_maximizing);
            board[row][col] = ' ';

            if (is_maximizing && move_score > best_score)
            {
                best_score = move_score;
                best_move = i;
            }
            else if (!is_maximizing && move_score < best_score)
            {
                best_score = move_score;
                best_move = i;
            }
        }
    }

    return best_move;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1)
        {
            printf("-+-+-\n");
        }
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int turn = 0;
    while (turn < BOARD_SIZE * BOARD_SIZE)
    {
        print_board(board);
        int move;
        if (turn % 2 == 0)
        {
            printf("Enter move (0-8): ");
            scanf("%d", &move);
            int row = move / BOARD_SIZE;
            int col = move % BOARD_SIZE;
            if (board[row][col] == ' ')
            {
                board[row][col] = 'x';
                turn++;
            }
            else
            {
                printf("Invalid move.\n");
            }
        }
        else
        {
            printf("AI is thinking...\n");
            move = get_best_move(board, 0, 0);
            int row = move / BOARD_SIZE;
            int col = move % BOARD_SIZE;
            board[row][col] = 'o';
            turn++;
        }

        // Check if the game is over
        int score = evaluate(board);
        if (score == 10)
        {
            printf("You win!\n");
            break;
        }
        else if (score == -10)
        {
            printf("AI wins!\n");
            break;
        }
        else if (turn == BOARD_SIZE * BOARD_SIZE)
        {
            printf("Tie game.\n");
            break;
        }
    }

    return 0;
}