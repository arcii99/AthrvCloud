//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void display_board()
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int check_win()
{
    int i;

    // Check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return 1;
    }

    return 0;
}

int minimax(int depth, int is_max)
{
    int i, j, score, best_score;
    char player, opponent;

    if (check_win())
    {
        if (is_max)
        {
            return -10 + depth;
        }
        else
        {
            return 10 - depth;
        }
    }

    if (depth == 9)
    {
        return 0;
    }

    if (is_max)
    {
        player = 'O';
        opponent = 'X';
        best_score = -1000;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = player;

                    score = minimax(depth + 1, !is_max);

                    if (score > best_score)
                    {
                        best_score = score;
                    }

                    board[i][j] = ' ';
                }
            }
        }

        return best_score;
    }
    else
    {
        player = 'X';
        opponent = 'O';
        best_score = 1000;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = player;

                    score = minimax(depth + 1, !is_max);

                    if (score < best_score)
                    {
                        best_score = score;
                    }

                    board[i][j] = ' ';
                }
            }
        }

        return best_score;
    }
}

void computer_move()
{
    int i, j, score, best_score = -1000;
    char player = 'O';

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;

                score = minimax(0, 0);

                board[i][j] = ' ';

                if (score > best_score)
                {
                    best_score = score;
                    board[i][j] = player;
                }
            }
        }
    }
}

int main()
{
    int i, j, player = 1;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X | Player 2: O\n");
    printf("---------\n");

    while (!check_win() && player <= 9)
    {
        if (player % 2 == 1)
        {
            printf("Player 1's turn (X):\n");
            printf("Enter the row and column number (1-3): ");
            scanf("%d %d", &i, &j);
            i--;
            j--;

            if (board[i][j] == ' ')
            {
                board[i][j] = 'X';
                player++;
            }
            else
            {
                printf("That space is already taken. Please choose another.\n");
            }
        }
        else
        {
            printf("Computer's turn (O):\n");
            computer_move();
            player++;
        }

        display_board();
    }

    if (check_win())
    {
        if (player % 2 == 0)
        {
            printf("Player 1 wins!");
        }
        else
        {
            printf("Computer wins!");
        }
    }
    else
    {
        printf("It's a tie!");
    }

    return 0;
}