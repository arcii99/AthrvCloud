//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#define ROW 8
#define COL 8

void print_board(char board[][COL]) {
    printf("\n     1   2   3   4   5   6   7   8\n");
    printf("   +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < ROW; i++) {
        printf(" %c |", 'A' + i);
        for (int j = 0; j < COL; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
}

int validate_move(int piece_x, int piece_y, int new_x, int new_y, char board[][COL], char player) {
    if (new_x < 0 || new_x >= ROW || new_y < 0 || new_y >= COL) {
        printf("Invalid move! Position out of the board.\n");
        return 0;
    }

    if (board[new_x][new_y] != ' ') {
        printf("Invalid move! The selected position is already occupied.\n");
        return 0;
    }

    int row_direction = 1;
    if (player == 'O') {
        row_direction = -1;
    }

    if (new_y == piece_y + 1 || new_y == piece_y - 1) {
        if (new_x== piece_x + row_direction) {
            return 1;
        }
    } else if (new_y == piece_y + 2 || new_y == piece_y - 2) {
        if (new_x == piece_x + 2 * row_direction && board[piece_x + row_direction][(piece_y + new_y) / 2] != ' ' && board[piece_x + row_direction][(piece_y + new_y) / 2] != player) {
            return 2;
        }
    }

    printf("Invalid move! A piece can only move diagonally and only one or two steps.\n");
    return 0;
}

void move_piece(int piece_x, int piece_y, int new_x, int new_y, char board[][COL], char player) {
    board[new_x][new_y] = player;
    board[piece_x][piece_y] = ' ';

    if ((player == 'X' && new_x == ROW - 1) || (player == 'O' && new_x == 0)) {
        board[new_x][new_y] = player == 'X' ? 'K' : 'Q';
    }
}

int main() {
    char board[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else if (i < 3) {
                board[i][j] = 'X';
            } else if (i > 4) {
                board[i][j] = 'O';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    char player = 'X';
    int game_over = 0;
    int total_moves = 0;
    while (!game_over) {
        print_board(board);

        printf("Player %c, it's your turn.\n", player);

        char move[4];
        printf("Enter the move in the format 'A1-B2': ");
        scanf(" %s", move);

        int piece_y = move[0] - 'A';
        int piece_x = move[1] - '1';
        int new_y = move[3] - 'A';
        int new_x = move[4] - '1';
        
        int valid_move = validate_move(piece_x, piece_y, new_x, new_y, board, player);
        if (valid_move) {
            move_piece(piece_x, piece_y, new_x, new_y, board, player);

            if (valid_move == 2) {
                board[piece_x + (new_x - piece_x) / 2][piece_y + (new_y - piece_y) / 2] = ' ';
            }

            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }

            total_moves++;

            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (board[i][j] == 'X' || board[i][j] == 'O') {
                        if (validate_move(i, j, i + 1, j + 1, board, player)) {
                            goto next_move;
                        }
                        if (validate_move(i, j, i + 1, j - 1, board, player)) {
                            goto next_move;
                        }
                        if (validate_move(i, j, i + 2, j + 2, board, player)) {
                            goto next_move;
                        }
                        if (validate_move(i, j, i + 2, j - 2, board, player)) {
                            goto next_move;
                        }
                    }
                }
            }

            game_over = 1;
            printf("GAME OVER.\n");
        } else {
            printf("Try again, Player %c.\n", player);
        }

        next_move: ;
    }

    print_board(board);
    printf("Total moves: %d\n", total_moves);

    return 0;
}