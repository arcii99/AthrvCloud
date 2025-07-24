//FormAI DATASET v1.0 Category: Checkers Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BLACK 'B'
#define WHITE 'W'
#define KING 'K'
#define SPACE ' '
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board();
void print_board();
int is_valid_move(int, int, int, int, char);
int is_capture_move(int, int, int, int, char);
int find_possible_moves(int, int);
int can_piece_capture(int, int, char);
void move_piece(int, int, int, int, char);
void remove_captured_piece(int, int, int, int, char);

int main()
{
    initialize_board();
    print_board();
    int player = 1;
    int row1, col1, row2, col2;

    while (1)
    {
        printf("\n\nPlayer %d's turn\n", player);
        printf("Enter row and column of piece to move (e.g. 1 2): ");
        scanf("%d %d", &row1, &col1);

        if (board[row1][col1] == SPACE || board[row1][col1] == WHITE || board[row1][col1] == BLACK)
        {
            if (can_piece_capture(row1, col1, board[row1][col1]))
            {
                printf("You must make a capture move.\n");
                continue;
            }

            printf("Enter row and column of destination (e.g. 3 4): ");
            scanf("%d %d", &row2, &col2);

            if (is_valid_move(row1, col1, row2, col2, board[row1][col1]))
            {
                move_piece(row1, col1, row2, col2, board[row1][col1]);

                if (can_piece_capture(row2, col2, board[row2][col2]))
                {
                    printf("You can still capture. ");
                    row1 = row2;
                    col1 = col2;
                    find_possible_moves(row1, col1);
                    continue;
                }
            }
            else
            {
                printf("Invalid move.\n");
                find_possible_moves(row1, col1);
                continue;
            }
        }
        else
        {
            printf("Invalid piece selection.\n");
            find_possible_moves(row1, col1);
            continue;
        }

        print_board();

        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    return 0;
}

void initialize_board()
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if ((i + j) % 2 == 0 && i < 3)
                board[i][j] = BLACK;
            else if ((i + j) % 2 == 0 && i > 4)
                board[i][j] = WHITE;
            else
                board[i][j] = SPACE;
        }
    }
}

void print_board()
{
    int i, j;

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", BOARD_SIZE - i);

        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    printf("  a b c d e f g h\n");
}

int is_valid_move(int row1, int col1, int row2, int col2, char piece)
{
    if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE)
        return 0;

    if (board[row2][col2] != SPACE)
        return 0;

    if (piece == WHITE && row1 >= row2)
        return 0;

    if (piece == BLACK && row1 <= row2)
        return 0;

    if ((abs(row1 - row2) == 1 && abs(col1 - col2) == 1) || is_capture_move(row1, col1, row2, col2, piece))
        return 1;

    return 0;
}

int is_capture_move(int row1, int col1, int row2, int col2, char piece)
{
    if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE)
        return 0;

    if (board[row2][col2] != SPACE)
        return 0;

    int i, j;

    if (piece == WHITE || piece == KING)
    {
        if (row1 - 2 == row2 && col1 - 2 == col2 && (board[row1 - 1][col1 - 1] == BLACK || board[row1 - 1][col1 - 1] == KING))
            return 1;
        if (row1 - 2 == row2 && col1 + 2 == col2 && (board[row1 - 1][col1 + 1] == BLACK || board[row1 - 1][col1 + 1] == KING))
            return 1;

        if (piece == KING)
        {
            if (row1 + 2 == row2 && col1 - 2 == col2 && (board[row1 + 1][col1 - 1] == BLACK || board[row1 + 1][col1 - 1] == KING))
                return 1;
            if (row1 + 2 == row2 && col1 + 2 == col2 && (board[row1 + 1][col1 + 1] == BLACK || board[row1 + 1][col1 + 1] == KING))
                return 1;
        }
    }

    if (piece == BLACK || piece == KING)
    {
        if (row1 + 2 == row2 && col1 - 2 == col2 && (board[row1 + 1][col1 - 1] == WHITE || board[row1 + 1][col1 - 1] == KING))
            return 1;
        if (row1 + 2 == row2 && col1 + 2 == col2 && (board[row1 + 1][col1 + 1] == WHITE || board[row1 + 1][col1 + 1] == KING))
            return 1;

        if (piece == KING)
        {
            if (row1 - 2 == row2 && col1 - 2 == col2 && (board[row1 - 1][col1 - 1] == WHITE || board[row1 - 1][col1 - 1] == KING))
                return 1;
            if (row1 - 2 == row2 && col1 + 2 == col2 && (board[row1 - 1][col1 + 1] == WHITE || board[row1 - 1][col1 + 1] == KING))
                return 1;
        }
    }

    return 0;
}

int find_possible_moves(int row, int col)
{
    int i, j;
    int has_capture_move = 0;

    for (i = row - 2; i <= row + 2; i++)
    {
        for (j = col - 2; j <= col + 2; j++)
        {
            if (is_capture_move(row, col, i, j, board[row][col]))
            {
                printf("Possible capture move: %d %d\n", i, j);
                has_capture_move = 1;
            }
        }
    }

    if (!has_capture_move)
    {
        for (i = row - 1; i <= row + 1; i++)
        {
            for (j = col - 1; j <= col + 1; j++)
            {
                if (is_valid_move(row, col, i, j, board[row][col]))
                {
                    printf("Possible move: %d %d\n", i, j);
                }
            }
        }
    }

    return has_capture_move;
}


int can_piece_capture(int row, int col, char piece)
{
    int i, j;

    for (i = row - 2; i <= row + 2; i++)
    {
        for (j = col - 2; j <= col + 2; j++)
        {
            if (is_capture_move(row, col, i, j, piece))
            {
                return 1;
            }
        }
    }

    return 0;
}

void move_piece(int row1, int col1, int row2, int col2, char piece)
{
    board[row2][col2] = piece;
    board[row1][col1] = SPACE;

    if (row2 == 0 && piece == WHITE)
    {
        board[row2][col2] = KING;
    }

    if (row2 == BOARD_SIZE - 1 && piece == BLACK)
    {
        board[row2][col2] = KING;
    }

    if (is_capture_move(row1, col1, row2, col2, piece))
    {
        remove_captured_piece(row1, col1, row2, col2, piece);
    }
}

void remove_captured_piece(int row1, int col1, int row2, int col2, char piece)
{
    int row3 = (row1 + row2) / 2;
    int col3 = (col1 + col2) / 2;

    board[row3][col3] = SPACE;
}