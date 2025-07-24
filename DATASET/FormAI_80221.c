//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdbool.h>
#include <stdio.h>

#define SIZE 8

void init_board(char board[][SIZE]);
void print_board(char board[][SIZE]);
bool is_legal_move(char board[][SIZE], int player, int row1, int col1, int row2, int col2);
void make_move(char board[][SIZE], int row1, int col1, int row2, int col2);
bool is_game_over(char board[][SIZE]);
int count_pieces(char board[][SIZE], char piece);

int main()
{
    char board[SIZE][SIZE];
    int player = 1;
    int row1, col1, row2, col2;

    init_board(board);

    printf("Welcome to Checkers Game!\n");
    printf("Player 1 starts first.\n\n");

    while (!is_game_over(board))
    {
        print_board(board);

        printf("Player %d's turn.\n", player);

        do
        {
            printf("Enter the row and column of the piece you want to move: ");
            scanf("%d %d", &row1, &col1);
            printf("Enter the row and column of the location you want to move it to: ");
            scanf("%d %d", &row2, &col2);
        } while (!is_legal_move(board, player, row1, col1, row2, col2));

        make_move(board, row1, col1, row2, col2);

        player = (player == 1) ? 2 : 1; // switch player
    }

    print_board(board);

    int num_p1 = count_pieces(board, '1');
    int num_p2 = count_pieces(board, '2');

    printf("Game over!\n\n");

    if (num_p1 > num_p2)
    {
        printf("Player 1 wins with %d pieces!\n", num_p1);
    }
    else if (num_p2 > num_p1)
    {
        printf("Player 2 wins with %d pieces!\n", num_p2);
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

void init_board(char board[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j] = ' ';
            }
            else if (i < 3)
            {
                board[i][j] = '2';
            }
            else if (i > 4)
            {
                board[i][j] = '1';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(char board[][SIZE])
{
    int i, j;
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d", i+1);
        for (j = 0; j < SIZE; j++)
        {
            printf(" | %c ", board[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("    a   b   c   d   e   f   g   h\n");
}

bool is_legal_move(char board[][SIZE], int player, int row1, int col1, int row2, int col2)
{
    // check if the move is legal
    if (row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE)
    {
        printf("Invalid move: out of bounds.\n");
        return false;
    }
    if (board[row2][col2] != ' ')
    {
        printf("Invalid move: destination is occupied.\n");
        return false;
    }

    char piece;
    if (player == 1)
    {
        piece = '1';
        if (board[row1][col1] != piece && board[row1][col1] != '3')
        {
            printf("Invalid move: you do not have a piece there.\n");
            return false;
        }
    }
    else if (player == 2)
    {
        piece = '2';
        if (board[row1][col1] != piece && board[row1][col1] != '4')
        {
            printf("Invalid move: you do not have a piece there.\n");
            return false;
        }
    }

    int row_diff = row2 - row1;
    int col_diff = col2 - col1;

    if (piece == '1' || piece == '3')
    {
        if (row_diff <= 0)
        {
            printf("Invalid move: you can only move forward.\n");
            return false;
        }
    }
    else if (piece == '2' || piece == '4')
    {
        if (row_diff >= 0)
        {
            printf("Invalid move: you can only move forward.\n");
            return false;
        }
    }

    if (row_diff == 1 && col_diff == -1)
    {
        if (player == 1 && board[row2][col2] == '2')
        {
            printf("Invalid move: you cannot capture your own piece.\n");
            return false;
        }
        if (player == 2 && board[row2][col2] == '1')
        {
            printf("Invalid move: you cannot capture your own piece.\n");
            return false;
        }
        return true;
    }
    else if (row_diff == 1 && col_diff == 1)
    {
        if (player == 1 && board[row2][col2] == '2')
        {
            printf("Invalid move: you cannot capture your own piece.\n");
            return false;
        }
        if (player == 2 && board[row2][col2] == '1')
        {
            printf("Invalid move: you cannot capture your own piece.\n");
            return false;
        }
        return true;
    }
    else if (row_diff == 2 && col_diff == -2)
    {
        int row_middle = row1 + 1;
        int col_middle = col1 - 1;
        if (player == 1 && (board[row_middle][col_middle] == '2' || board[row_middle][col_middle] == '4'))
        {
            board[row_middle][col_middle] = ' ';
            return true;
        }
        if (player == 2 && (board[row_middle][col_middle] == '1' || board[row_middle][col_middle] == '3'))
        {
            board[row_middle][col_middle] = ' ';
            return true;
        }
        printf("Invalid move: you can only capture an opponent's piece.\n");
        return false;
    }
    else if (row_diff == 2 && col_diff == 2)
    {
        int row_middle = row1 + 1;
        int col_middle = col1 + 1;
        if (player == 1 && (board[row_middle][col_middle] == '2' || board[row_middle][col_middle] == '4'))
        {
            board[row_middle][col_middle] = ' ';
            return true;
        }
        if (player == 2 && (board[row_middle][col_middle] == '1' || board[row_middle][col_middle] == '3'))
        {
            board[row_middle][col_middle] = ' ';
            return true;
        }
        printf("Invalid move: you can only capture an opponent's piece.\n");
        return false;
    }

    printf("Invalid move: not a legal move.\n");
    return false;
}

void make_move(char board[][SIZE], int row1, int col1, int row2, int col2)
{
    char piece = board[row1][col1];
    board[row2][col2] = piece;
    board[row1][col1] = ' ';

    if (piece == '1' && row2 == SIZE-1)
        board[row2][col2] = '3';
    if (piece == '2' && row2 == 0)
        board[row2][col2] = '4';
}

bool is_game_over(char board[][SIZE])
{
    if (count_pieces(board, '1') == 0 || count_pieces(board, '3') == 0)
        return true;
    if (count_pieces(board, '2') == 0 || count_pieces(board, '4') == 0)
        return true;

    int i, j;
    bool found = false;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '1' || board[i][j] == '3')
            {
                int row, col;
                for (row = i-2; row <= i+2; row+=4)
                {
                    for (col = j-2; col <= j+2; col+=4)
                    {
                        if (row >=0 && row < SIZE && col >=0 && col < SIZE)
                        {
                            if (board[row][col] == ' ')
                            {
                                if (is_legal_move(board, 1, i, j, row, col))
                                {
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
            else if (board[i][j] == '2' || board[i][j] == '4')
            {
                int row, col;
                for (row = i-2; row <= i+2; row+=4)
                {
                    for (col = j-2; col <= j+2; col+=4)
                    {
                        if (row >=0 && row < SIZE && col >=0 && col < SIZE)
                        {
                            if (board[row][col] == ' ')
                            {
                                if (is_legal_move(board, 2, i, j, row, col))
                                {
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return !found;
}

int count_pieces(char board[][SIZE], char piece)
{
    int count = 0;
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == piece)
                count++;
        }
    }
    return count;
}