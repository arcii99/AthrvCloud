//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define PLAYER 0
#define AI 1

#define EMPTY ' '
#define PLAYER_SYMBOL 'X'
#define AI_SYMBOL 'O'

void draw_board(char board[3][3]);
int is_game_over(char board[3][3]);
int evaluate(char board[3][3]);
int minimax(char board[3][3], int depth, int maximizing_player);
void ai_move(char board[3][3]);

int main()
{
    char board[3][3] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};

    while (!is_game_over(board))
    {
        // player move
        draw_board(board);

        int row, col;
        printf("Enter row and column (separated by space): ");
        scanf("%d %d", &row, &col);

        if (board[row][col] != EMPTY)
        {
            printf("Invalid move!\n");
            continue;
        }

        board[row][col] = PLAYER_SYMBOL;

        if (is_game_over(board))
        {
            draw_board(board);
            break;
        }

        // AI move
        ai_move(board);

        if (is_game_over(board))
        {
            draw_board(board);
            break;
        }
    }

    return 0;
}

void draw_board(char board[3][3])
{
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);

        if (i != 2)
            printf("\n---|---|---\n");
    }

    printf("\n");
}

int is_game_over(char board[3][3])
{   
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            printf("%c wins!\n", board[i][0]);
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            printf("%c wins!\n", board[0][i]);
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        printf("%c wins!\n", board[0][0]);
        return 1;
    }

    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        printf("%c wins!\n", board[0][2]);
        return 1;
    }

    // check for draw
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return 0;

    printf("Draw!\n");
    return 1;
}

int evaluate(char board[3][3])
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == AI_SYMBOL)
                return 1;
            else
                return -1;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == AI_SYMBOL)
                return 1;
            else
                return -1;
        }
    }

    // check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == AI_SYMBOL)
            return 1;
        else
            return -1;
    }

    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == AI_SYMBOL)
            return 1;
        else
            return -1;
    }

    return 0;
}

int minimax(char board[3][3], int depth, int maximizing_player)
{
    int score = evaluate(board);

    // if the current board is a terminal board, return the score
    if (score != 0 || depth == 0)
        return score;

    // if the AI is maximizing
    if (maximizing_player)
    {
        int best_score = -1000;

        // try every possible move and take the best score
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = AI_SYMBOL;
                    int new_score = minimax(board, depth - 1, PLAYER);
                    board[i][j] = EMPTY;
                    if (new_score > best_score)
                        best_score = new_score;
                }
            }
        }

        return best_score;
    }
    // if the player is maximizing
    else
    {
        int best_score = 1000;

        // try every possible move and take the best score
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = PLAYER_SYMBOL;
                    int new_score = minimax(board, depth - 1, AI);
                    board[i][j] = EMPTY;
                    if (new_score < best_score)
                        best_score = new_score;
                }
            }
        }

        return best_score;
    }
}

void ai_move(char board[3][3])
{
    int best_score = -1000;
    int best_move_row, best_move_col;

    // try every possible move and take the best one
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = AI_SYMBOL;
                int new_score = minimax(board, 2, PLAYER);
                board[i][j] = EMPTY;
                if (new_score > best_score)
                {
                    best_score = new_score;
                    best_move_row = i;
                    best_move_col = j;
                }
            }
        }
    }

    board[best_move_row][best_move_col] = AI_SYMBOL;
}