//FormAI DATASET v1.0 Category: Chess engine ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
int game_over = 0;
char player = 'w';

void init_board();
void print_board();
void move_piece(int start_row, int start_col, int end_row, int end_col);
void evaluate_move(int start_row, int start_col, int end_row, int end_col);
int check_move(int start_row, int start_col, int end_row, int end_col);
int check_pawn(int start_row, int start_col, int end_row, int end_col);
int check_rook(int start_row, int start_col, int end_row, int end_col);
int check_knight(int start_row, int start_col, int end_row, int end_col);
int check_bishop(int start_row, int start_col, int end_row, int end_col);
int check_queen(int start_row, int start_col, int end_row, int end_col);
int check_king(int start_row, int start_col, int end_row, int end_col);
int check_obstacle(int start_row, int start_col, int end_row, int end_col);
int check_castling(int start_row, int start_col, int end_row, int end_col);

int main() {
    init_board();
    print_board();

    while (!game_over) {
        printf("Player %c, make your move (ex: a2 a4): ", player);
        char move[5];
        scanf("%s", move);
        int start_col = move[0] - 'a';
        int start_row = BOARD_SIZE - (move[1] - '0');
        int end_col = move[2] - 'a';
        int end_row = BOARD_SIZE - (move[3] - '0');
        move_piece(start_row, start_col, end_row, end_col);
        print_board();
        if (player == 'w') {
            player = 'b';
        } else {
            player = 'w';
        }
    }

    return 0;
}

void init_board() {
    memset(board, ' ', sizeof(board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    board[0][0] = 'R';
    board[0][7] = 'R';
    board[7][0] = 'r';
    board[7][7] = 'r';
    board[0][1] = 'N';
    board[0][6] = 'N';
    board[7][1] = 'n';
    board[7][6] = 'n';
    board[0][2] = 'B';
    board[0][5] = 'B';
    board[7][2] = 'b';
    board[7][5] = 'b';
    board[0][3] = 'Q';
    board[7][3] = 'q';
    board[0][4] = 'K';
    board[7][4] = 'k';
}

void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf(" %d\n", BOARD_SIZE - i);
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");
}

void move_piece(int start_row, int start_col, int end_row, int end_col) {
    if (start_row < 0 || start_row >= BOARD_SIZE ||
        start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE ||
        end_col < 0 || end_col >= BOARD_SIZE) {
        printf("Invalid move: Out of bounds\n");
        return;
    }

    if (board[start_row][start_col] == ' ') {
        printf("Invalid move: No piece at start position\n");
        return;
    }

    if (tolower(board[start_row][start_col]) != player) {
        printf("Invalid move: Opponent's piece at start position\n");
        return;
    }

    if (check_move(start_row, start_col, end_row, end_col) == 0) {
        printf("Invalid move: Illegal move\n");
        return;
    }

    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
}

void evaluate_move(int start_row, int start_col, int end_row, int end_col) {
    if (board[start_row][start_col] == 'P' || board[start_row][start_col] == 'p') {
        check_pawn(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'R' || board[start_row][start_col] == 'r') {
        check_rook(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'N' || board[start_row][start_col] == 'n') {
        check_knight(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'B' || board[start_row][start_col] == 'b') {
        check_bishop(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'Q' || board[start_row][start_col] == 'q') {
        check_queen(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'K' || board[start_row][start_col] == 'k') {
        check_king(start_row, start_col, end_row, end_col);
    }
}

int check_move(int start_row, int start_col, int end_row, int end_col) {
    if (board[end_row][end_col] != ' ' && tolower(board[start_row][start_col]) == tolower(board[end_row][end_col])) {
        return 0;
    }
    return check_obstacle(start_row, start_col, end_row, end_col);
}

int check_pawn(int start_row, int start_col, int end_row, int end_col) {
    int delta = 1;
    if (board[start_row][start_col] == 'P') {
        delta = -1;
    }
    if (start_col == end_col && board[end_row][end_col] == ' ' && (end_row - start_row) == delta) {
        return 1;        
    } else if (start_col == end_col && board[end_row][end_col] == ' ' && (end_row - start_row) == delta * 2 && start_row == (board[start_row][start_col] == 'P' ? 6 : 1)) {
        if (board[start_row + delta][start_col] == ' ') {
            return 1;
        }
    } else if (abs(start_col - end_col) == 1 && board[end_row][end_col] != ' ' && (end_row - start_row) == delta) {
        return 1;
    }
    return 0;
}

int check_rook(int start_row, int start_col, int end_row, int end_col) {
    if (start_col == end_col) {
        int delta = end_row > start_row ? 1 : -1;
        for (int i = start_row + delta; i != end_row; i += delta) {
            if (board[i][start_col] != ' ') {
                return 0;
            }
        }
        return 1;
    } else if (start_row == end_row) {
        int delta = end_col > start_col ? 1 : -1;
        for (int i = start_col + delta; i != end_col; i += delta) {
            if (board[start_row][i] != ' ') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int check_knight(int start_row, int start_col, int end_row, int end_col) {
    int delta_row = abs(end_row - start_row);
    int delta_col = abs(end_col - start_col);
    if (delta_row == 2 && delta_col == 1) {
        return 1;
    } else if (delta_row == 1 && delta_col == 2) {
        return 1;
    }    
    return 0;
}

int check_bishop(int start_row, int start_col, int end_row, int end_col) {
    int delta_row = end_row > start_row ? 1 : -1;
    int delta_col = end_col > start_col ? 1 : -1;
    if (abs(start_row - end_row) == abs(start_col - end_col)) {
        for (int i = 1; i < abs(start_row - end_row); i++) {
            if (board[start_row + i * delta_row][start_col + i * delta_col] != ' ') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int check_queen(int start_row, int start_col, int end_row, int end_col) {
    if (check_rook(start_row, start_col, end_row, end_col) || check_bishop(start_row, start_col, end_row, end_col)) {
        return 1;
    }
    return 0;
}

int check_king(int start_row, int start_col, int end_row, int end_col) {
    int delta_row = abs(end_row - start_row);
    int delta_col = abs(end_col - start_col);
    if (delta_row <= 1 && delta_col <= 1) {
        return 1;
    } else if (delta_row == 0 && delta_col == 2 && (board[start_row][start_col] == 'K' || board[start_row][start_col] == 'k')) {
        return check_castling(start_row, start_col, end_row, end_col);
    }
    return 0;
}

int check_obstacle(int start_row, int start_col, int end_row, int end_col) {
    if (board[start_row][start_col] == 'P' || board[start_row][start_col] == 'p') {
        return check_pawn(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'R' || board[start_row][start_col] == 'r') {
        return check_rook(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'N' || board[start_row][start_col] == 'n') {
        return check_knight(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'B' || board[start_row][start_col] == 'b') {
        return check_bishop(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'Q' || board[start_row][start_col] == 'q') {
        return check_queen(start_row, start_col, end_row, end_col);
    } else if (board[start_row][start_col] == 'K' || board[start_row][start_col] == 'k') {
        return check_king(start_row, start_col, end_row, end_col);
    }
    return 0;
}

int check_castling(int start_row, int start_col, int end_row, int end_col) {
    if (player == 'w' && start_row == 0 && start_col == 4 && end_row == 0 && (end_col == 2 || end_col == 6)) {
        if (end_col == 2) {
            if (board[0][0] == 'R' && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ') {
                board[0][2] = 'K';
                board[0][3] = 'N';
                board[0][0] = ' ';
                board[0][4] = ' ';
                return 1;
            }
        } else if (end_col == 6) {
            if (board[0][7] == 'R' && board[0][6] == ' ' && board[0][5] == ' ') {
                board[0][6] = 'K';
                board[0][5] = 'N';
                board[0][7] = ' ';
                board[0][4] = ' ';
                return 1;
            }
        }
    } else if (player == 'b' && start_row == 7 && start_col == 4 && end_row == 7 && (end_col == 2 || end_col == 6)) {
        if (end_col == 2) {
            if (board[7][0] == 'r' && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ') {
                board[7][2] = 'k';
                board[7][3] = 'n';
                board[7][0] = ' ';
                board[7][4] = ' ';
                return 1;
            }
        } else if (end_col == 6) {
            if (board[7][7] == 'r' && board[7][6] == ' ' && board[7][5] == ' ') {
                board[7][6] = 'k';
                board[7][5] = 'n';
                board[7][7] = ' ';
                board[7][4] = ' ';
                return 1;
            }
        }
    }
    return 0;
}