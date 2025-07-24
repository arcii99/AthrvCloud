//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

struct piece {
    bool king;
    char symbol;
};

struct player {
    int direction;
    struct piece pieces[12];
};

struct player players[2] = {
    {1, {{false, 'o'}}},
    {-1, {{false, 'x'}}}
};

void initialize_board() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = players[0].pieces[(i*BOARD_SIZE/2)+j/2].symbol;
                } else if (i > 4) {
                    board[i][j] = players[1].pieces[((BOARD_SIZE-i)*BOARD_SIZE/2)-j/2-1].symbol;
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = '.';
            }
        }
    }
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool in_bounds(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

bool is_empty(int row, int col) {
    return (in_bounds(row, col) && board[row][col] == ' ');
}

bool is_piece(int row, int col, char piece) {
    return (in_bounds(row, col) && board[row][col] == piece);
}

bool can_capture(int row, int col, int player_idx) {
    char piece = players[player_idx].pieces[0].symbol;
    char king = (players[player_idx].pieces[0].king) ? 'K' : piece-'a'+'A';
    if (is_piece(row, col, piece) || is_piece(row, col, king)) {
        if (is_piece(row+players[player_idx].direction, col-1, piece) || is_piece(row+players[player_idx].direction, col-1, king)) {
            if (is_empty(row+players[player_idx].direction*2, col-2)) {
                return true;
            }
        }
        if (is_piece(row+players[player_idx].direction, col+1, piece) || is_piece(row+players[player_idx].direction, col+1, king)) {
            if (is_empty(row+players[player_idx].direction*2, col+2)) {
                return true;
            }
        }
        if (king && (is_piece(row-players[player_idx].direction, col-1, piece) || is_piece(row-players[player_idx].direction, col-1, king))) {
            if (is_empty(row-players[player_idx].direction*2, col-2)) {
                return true;
            }
        }
        if (king && (is_piece(row-players[player_idx].direction, col+1, piece) || is_piece(row-players[player_idx].direction, col+1, king))) {
            if (is_empty(row-players[player_idx].direction*2, col+2)) {
                return true;
            }
        }
    }
    return false;
}

bool can_move(int row, int col, int player_idx) {
    char piece = players[player_idx].pieces[0].symbol;
    char king = (players[player_idx].pieces[0].king) ? 'K' : piece-'a'+'A';
    if (is_piece(row, col, piece) || is_piece(row, col, king)) {
        if (is_empty(row+players[player_idx].direction, col-1) || is_empty(row+players[player_idx].direction, col+1)) {
            return true;
        }
        if (king && (is_empty(row-players[player_idx].direction, col-1) || is_empty(row-players[player_idx].direction, col+1))) {
            return true;
        }
    }
    return false;
}

void move_piece(int row, int col, int new_row, int new_col, int player_idx) {
    char piece = board[row][col];
    board[row][col] = ' ';
    board[new_row][new_col] = piece;
    if (new_row == (players[player_idx].direction == 1 ? 0 : BOARD_SIZE-1)) {
        players[player_idx].pieces[row*BOARD_SIZE+col/2].king = true;
        players[player_idx].pieces[row*BOARD_SIZE+col/2].symbol = 'K';
    }
    if (abs(row-new_row) == 2) {
        board[row+(new_row-row)/2][col+(new_col-col)/2] = ' ';
        for (int i=0; i<BOARD_SIZE*BOARD_SIZE/2; i++) {
            if (players[!player_idx].pieces[i].symbol == board[row+(new_row-row)/2][col+(new_col-col)/2]) {
                players[!player_idx].pieces[i] = players[!player_idx].pieces[BOARD_SIZE*BOARD_SIZE/2-1];
                break;
            }
        }
    }
}

bool has_moves(int player_idx) {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            if (can_move(i, j, player_idx) || can_capture(i, j, player_idx)) {
                return true;
            }
        }
    }
    return false;
}

void play_game() {
    initialize_board();
    int turn = 0;
    bool game_over = false;
    while (!game_over) {
        printf("Player %d's turn:\n", turn % 2 + 1);
        print_board();
        bool valid_move = false;
        while (!valid_move) {
            int row, col, new_row, new_col;
            printf("Enter row and column of piece to move: ");
            scanf("%d %d", &row, &col);
            printf("Enter row and column to move to: ");
            scanf("%d %d", &new_row, &new_col);
            if (is_piece(row, col, players[turn % 2].pieces[0].symbol) || is_piece(row, col, 'K') || is_piece(row, col, 'X')) {
                if (can_capture(row, col, turn % 2)) {
                    if (abs(row-new_row) == 2 && abs(col-new_col) == 2) {
                        move_piece(row, col, new_row, new_col, turn % 2);
                        if (can_capture(new_row, new_col, turn % 2)) {
                            row = new_row;
                            col = new_col;
                            printf("Capture another piece.\n");
                        } else {
                            valid_move = true;
                        }
                    } else {
                        printf("You must capture a piece.\n");
                    }
                } else if (can_move(row, col, turn % 2)) {
                    if (abs(row-new_row) == 1 && abs(col-new_col) == 1) {
                        move_piece(row, col, new_row, new_col, turn % 2);
                        valid_move = true;
                    } else {
                        printf("Invalid move.\n");
                    }
                } else {
                    printf("Piece cannot move.\n");
                }
            } else {
                printf("No piece there.\n");
            }
        }
        turn++;
        if (!has_moves(turn % 2)) {
            printf("Player %d has no moves left. ", turn % 2 + 1);
            printf("Player %d wins!\n", !(turn % 2) + 1);
            game_over = true;
        }
    }
}

int main() {
    play_game();
    return 0;
}