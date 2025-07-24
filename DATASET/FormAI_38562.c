//FormAI DATASET v1.0 Category: Checkers Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COLUMN 8

char board[ROW][COLUMN];
char player1 = 'B';
char player2 = 'W';

void initialize_board()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
        {
            if ((row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1))
            {
                if (row < 3)
                {
                    board[row][col] = player1;
                }
                else if (row > 4)
                {
                    board[row][col] = player2;
                }
                else
                {
                    board[row][col] = ' ';
                }
            }
            else
            {
                board[row][col] = ' ';
            }
        }
    }
}

void display_board()
{
    printf("   ");
    for (int col = 0; col < COLUMN; col++)
    {
        printf("%d   ", col);
    }
    printf("\n");

    for (int row = 0; row < ROW; row++)
    {
        printf(" %d ", row);
        for (int col = 0; col < COLUMN; col++)
        {
            printf("| %c ", board[row][col]);
        }
        printf("| %d\n", row);
    }

    printf("   ");
    for (int col = 0; col < COLUMN; col++)
    {
        printf("%d   ", col);
    }
    printf("\n");
}

bool check_move(int from_row, int from_col, int to_row, int to_col, char player)
{
    if (to_row < 0 || to_row >= ROW || to_col < 0 || to_col >= COLUMN)
    {
        return false;
    }

    if (board[to_row][to_col] != ' ')
    {
        return false;
    }

    if (player == player1)
    {
        if (board[from_row][from_col] == 'B')
        {
            if ((to_row - from_row) == 1 && abs(to_col - from_col) == 1)
            {
                return true;
            }
            else if ((to_row - from_row) == 2 && abs(to_col - from_col) == 2)
            {
                int middle_row = (to_row + from_row) / 2;
                int middle_col = (to_col + from_col) / 2;

                if (board[middle_row][middle_col] == 'W')
                {
                    return true;
                }
            }
        }
        else if (board[from_row][from_col] == 'BK')
        {
            if ((abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) ||
                (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2))
            {
                int middle_row = (to_row + from_row) / 2;
                int middle_col = (to_col + from_col) / 2;

                if (board[middle_row][middle_col] == 'W' || board[middle_row][middle_col] == 'WK')
                {
                    return true;
                }
            }
        }
    }
    else if (player == player2)
    {
        if (board[from_row][from_col] == 'W')
        {
            if ((to_row - from_row) == -1 && abs(to_col - from_col) == 1)
            {
                return true;
            }
            else if ((to_row - from_row) == -2 && abs(to_col - from_col) == 2)
            {
                int middle_row = (to_row + from_row) / 2;
                int middle_col = (to_col + from_col) / 2;

                if (board[middle_row][middle_col] == 'B')
                {
                    return true;
                }
            }
        }
        else if (board[from_row][from_col] == 'WK')
        {
            if ((abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) ||
                (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2))
            {
                int middle_row = (to_row + from_row) / 2;
                int middle_col = (to_col + from_col) / 2;

                if (board[middle_row][middle_col] == 'B' || board[middle_row][middle_col] == 'BK')
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool check_all_moves(char player)
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COLUMN; col++)
        {
            if (board[row][col] == player || board[row][col] == player + 32)
            {
                if (player == player1)
                {
                    if (check_move(row, col, row + 1, col + 1, player) ||
                        check_move(row, col, row + 1, col - 1, player) ||
                        check_move(row, col, row + 2, col + 2, player) ||
                        check_move(row, col, row + 2, col - 2, player))
                    {
                        return true;
                    }
                }
                else if (player == player2)
                {
                    if (check_move(row, col, row - 1, col + 1, player) ||
                        check_move(row, col, row - 1, col - 1, player) ||
                        check_move(row, col, row - 2, col + 2, player) ||
                        check_move(row, col, row - 2, col - 2, player))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

void make_move(int from_row, int from_col, int to_row, int to_col, char player)
{
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';

    if (player == player1 && to_row == ROW - 1 && board[to_row][to_col] == 'B')
    {
        board[to_row][to_col] = 'BK';
    }
    else if (player == player2 && to_row == 0 && board[to_row][to_col] == 'W')
    {
        board[to_row][to_col] = 'WK';
    }
}

void play_game()
{
    initialize_board();
    display_board();

    int turn = 1;
    char current_player = player1;

    while (true)
    {
        printf("\n===== Turn %d =====\n", turn);

        if (!check_all_moves(current_player))
        {
            printf("%c has no valid move left. ", current_player);
            if (current_player == player1)
            {
                printf("%c wins!", player2);
            }
            else
            {
                printf("%c wins!", player1);
            }
            break;
        }

        int from_row, from_col, to_row, to_col;
        printf("Choose a piece to move (row col): ");
        scanf("%d %d", &from_row, &from_col);

        while (board[from_row][from_col] != current_player && board[from_row][from_col] != current_player + 32)
        {
            printf("Invalid choice. Choose a valid piece to move (row col): ");
            scanf("%d %d", &from_row, &from_col);
        }

        printf("Choose a destination for the piece (row col): ");
        scanf("%d %d", &to_row, &to_col);

        while (!check_move(from_row, from_col, to_row, to_col, current_player))
        {
            printf("Invalid destination. Choose a valid destination for the piece (row col): ");
            scanf("%d %d", &to_row, &to_col);
        }

        make_move(from_row, from_col, to_row, to_col, current_player);
        display_board();

        if (current_player == player1)
        {
            current_player = player2;
        }
        else
        {
            current_player = player1;
        }

        turn++;
    }
}

int main()
{
    printf("Welcome to Checkers Game!\n");
    printf("=========================\n\n");

    printf("Instructions:\n");
    printf("1. Black pieces move only diagonally forward to the left or right. \n");
    printf("2. White pieces move only diagonally backward to the left or right.\n");
    printf("3. A piece can capture another piece by jumping over it diagonally to the left or right.\n");
    printf("4. A piece that reaches the opposite end of the board is promoted to a king, which can move diagonally backward and forward.\n");
    printf("5. The game is won by capturing all of an opponent's pieces or blocking them.\n\n");

    play_game();

    return 0;
}