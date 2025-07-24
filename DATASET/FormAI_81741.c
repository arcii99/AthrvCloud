//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 3
#define COL 3

char board[ROW][COL];
char human_char = 'X';
char ai_char = 'O';

void initialize_board();
void display_board();
bool is_move_valid(int row, int col);
void human_move();
void ai_move();
char check_winner();
int minmax(bool maximizing_player);

int main()
{
    initialize_board();
    display_board();

    while (true)
    {
        human_move();
        display_board();
        if (check_winner() != '\0')
        {
            printf("Human wins!\n");
            break;
        }

        ai_move();
        display_board();
        if (check_winner() != '\0')
        {
            printf("AI wins!\n");
            break;
        }
    }

    return 0;
}

void initialize_board()
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            board[i][j] = '-';
        }
    }
}

void display_board()
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_move_valid(int row, int col)
{
    if (row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col] != '-')
    {
        return false;
    }
    return true;
}

void human_move()
{
    int row, col;

    printf("Human move:\n");
    printf("Row: ");
    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &col);

    while (!is_move_valid(row, col))
    {
        printf("Invalid move! Try again.\n");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
    }

    board[row][col] = human_char;
}

void ai_move()
{
    int i, j, max_score = -1000, score, row, col;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = ai_char;
                score = minmax(false);
                board[i][j] = '-';
                if (score > max_score)
                {
                    max_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = ai_char;
    printf("AI move: row = %d, column = %d\n", row, col);
}

char check_winner()
{
    int i, j;

    // Check rows
    for (i = 0; i < ROW; i++)
    {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Check columns
    for (j = 0; j < COL; j++)
    {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }

    // Check for tie
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (board[i][j] == '-')
            {
                return '\0';
            }
        }
    }

    return 'T';
}

int minmax(bool maximizing_player)
{
    char winner = check_winner();
    if (winner == ai_char)
    {
        return 10;
    }
    if (winner == human_char)
    {
        return -10;
    }
    if (winner == 'T')
    {
        return 0;
    }

    int i, j, score;
    if (maximizing_player)
    {
        int max_score = -1000;
        for (i = 0; i < ROW; i++)
        {
            for (j = 0; j < COL; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = ai_char;
                    score = minmax(false);
                    board[i][j] = '-';
                    if (score > max_score)
                    {
                        max_score = score;
                    }
                }
            }
        }
        return max_score;
    }
    else
    {
        int min_score = 1000;
        for (i = 0; i < ROW; i++)
        {
            for (j = 0; j < COL; j++)
            {
                if (board[i][j] == '-')
                {
                    board[i][j] = human_char;
                    score = minmax(true);
                    board[i][j] = '-';
                    if (score < min_score)
                    {
                        min_score = score;
                    }
                }
            }
        }
        return min_score;
    }
}