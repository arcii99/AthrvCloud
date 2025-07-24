//FormAI DATASET v1.0 Category: Checkers Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define ROW 8
#define COL 8
#define PIECES 12

void print_board(char board[ROW][COL]);
void initialize_board(char board[ROW][COL]);
int move_piece(char board[ROW][COL], int player, int src_row, int src_col, int dest_row, int dest_col);
int check_valid_move(char board[ROW][COL], int player, int src_row, int src_col, int dest_row, int dest_col);
int is_attack_move(char board[ROW][COL], int src_row, int src_col, int dest_row, int dest_col);

int main()
{
    char board[ROW][COL];
    initialize_board(board);

    int turn = 0;
    int player = 1;

    while (1) {
        print_board(board);

        printf("\nTurn %d - Player %d\n", turn, player);

        int src_row, src_col, dest_row, dest_col;
        printf("Enter current position: ");
        scanf("%d %d", &src_row, &src_col);

        printf("Enter destination position: ");
        scanf("%d %d", &dest_row, &dest_col);

        if (move_piece(board, player, src_row, src_col, dest_row, dest_col)) {
            turn++;

            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }

        printf("\n");
    }

    return 0;
}

void print_board(char board[ROW][COL])
{
    printf("\n     A  B  C  D  E  F  G  H\n");
    printf("   -------------------------\n");
    for (int i = 0; i < ROW; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < COL; j++) {
            printf("%c |", board[i][j]);
        }
        printf("\n");
        printf("   -------------------------\n");
    }
}

void initialize_board(char board[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    if (i < 3) {
                        board[i][j] = 'x';
                    } else if (i > 4) {
                        board[i][j] = 'o';
                    } else {
                        board[i][j] = ' ';
                    }
                } else {
                    board[i][j] = ' ';
                }
            } else {
                if (j % 2 == 0) {
                    board[i][j] = ' ';
                } else {
                    if (i < 3) {
                        board[i][j] = 'x';
                    } else if (i > 4) {
                        board[i][j] = 'o';
                    } else {
                        board[i][j] = ' ';
                    }
                }
            }
        }
    }
}

int move_piece(char board[ROW][COL], int player, int src_row, int src_col, int dest_row, int dest_col)
{
    int valid_move = check_valid_move(board, player, src_row, src_col, dest_row, dest_col);

    if (valid_move) {
        board[dest_row][dest_col] = board[src_row][src_col];
        board[src_row][src_col] = ' ';

        if (is_attack_move(board, src_row, src_col, dest_row, dest_col)) {
            if (player == 1) {
                board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] = ' ';
            } else {
                board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] = ' ';
            }
        }

        return 1;
    } else {
        printf("\nInvalid move. Try again.\n");
        return 0;
    }
}

int check_valid_move(char board[ROW][COL], int player, int src_row, int src_col, int dest_row, int dest_col)
{
    if (dest_row < 0 || dest_row > 7 || dest_col < 0 || dest_col > 7) {
        return 0;
    }

    if (board[dest_row][dest_col] != ' ') {
        return 0;
    }

    if (player == 1) {
        if (board[src_row][src_col] != 'x' && board[src_row][src_col] != 'X') {
            return 0;
        }
    } else {
        if (board[src_row][src_col] != 'o' && board[src_row][src_col] != 'O') {
            return 0;
        }
    }

    // check if move is diagonal
    int row_diff = abs(src_row - dest_row);
    int col_diff = abs(src_col - dest_col);
    if (row_diff != col_diff) {
        return 0;
    }

    // check if move is only one or two steps
    if (row_diff != 1 && row_diff != 2) {
        return 0;
    }

    // check if piece is only moving forward
    if (player == 1 && dest_row > src_row) {
        return 0;
    } else if (player == 2 && dest_row < src_row) {
        return 0;
    }

    if (row_diff == 2) {
        // check if there is a piece to jump over
        if (dest_row > src_row) {
            if (dest_col > src_col) {
                if (board[src_row + 1][src_col + 1] == ' ') {
                    return 0;
                }
            } else {
                if (board[src_row + 1][src_col - 1] == ' ') {
                    return 0;
                }
            }
        } else {
            if (dest_col > src_col) {
                if (board[src_row - 1][src_col + 1] == ' ') {
                    return 0;
                }
            } else {
                if (board[src_row - 1][src_col - 1] == ' ') {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int is_attack_move(char board[ROW][COL], int src_row, int src_col, int dest_row, int dest_col)
{
    int row_diff = abs(src_row - dest_row);
    int col_diff = abs(src_col - dest_col);

    if (row_diff == 2 && col_diff == 2) {
        if (board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] == 'x' || board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] == 'o' || board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] == 'X' || board[(src_row + dest_row) / 2][(src_col + dest_col) / 2] == 'O') {
            return 1;
        }
    }

    return 0;
}