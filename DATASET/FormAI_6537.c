//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>

#define BOARD_SIZE 8

void init_board(char board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if ((row + col) % 2 == 0 && row < 3) {
                board[row][col] = 'B';
            } else if ((row + col) % 2 == 0 && row > 4) {
                board[row][col] = 'W';
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

void display_board(char board[][BOARD_SIZE]) {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; ++col) {
        printf(" %d ", col + 1);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        printf("%c ", 'A' + row);
        for (int col = 0; col < BOARD_SIZE; ++col) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

int get_piece(char board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return -1;
    }
    return board[row][col];
}

int is_valid_move(int r1, int c1, int r2, int c2, char turn, char board[][BOARD_SIZE]){
    if (board[r2][c2] != ' ') {
        return 0;
    }
    
    if (turn == 'B' && r1 < r2) {
        return 0;
    }
    
    if (turn == 'W' && r1 > r2) {
        return 0;
    }
    
    if (abs(r1 - r2) == 1 && abs(c1 - c2) == 1) {
        return 1;
    }
    
    if (abs(r1 - r2) == 2 && abs(c1 - c2) == 2) {
        int jump_row = (r1 + r2) / 2;
        int jump_col = (c1 + c2) / 2;
        if (get_piece(board, jump_row, jump_col) != (turn == 'B' ? 'W' : 'B')) {
            return 0;
        }
        return 2;
    }
    return 0;
}

int make_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2) {
    int move_type = is_valid_move(r1, c1, r2, c2, board[r1][c1], board);
    if (move_type == 0) {
        return 0;
    }
    
    board[r2][c2] = board[r1][c1];
    board[r1][c1] = ' ';
    
    if (move_type == 2) {
        int jump_row = (r1 + r2) / 2;
        int jump_col = (c1 + c2) / 2;
        board[jump_row][jump_col] = ' ';
    }
    
    return 1;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    printf("Welcome to Checkers!\n");
    display_board(board);

    int game_over = 0;
    char turn = 'B';
    while (!game_over) {
        printf("%c's Turn\n", turn);
        printf("Enter move (e.g. A3-B4): ");
        char from[3], to[3];
        scanf("%s-%s", from, to);
        int r1 = from[0] - 'A', c1 = from[1] - '1';
        int r2 = to[0] - 'A', c2 = to[1] - '1';
        
        if (make_move(board, r1, c1, r2, c2)) {
            display_board(board);
            if (turn == 'B') {
                turn = 'W';
            } else {
                turn = 'B';
            }
        }
    }

    return 0;
}