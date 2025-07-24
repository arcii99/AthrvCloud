//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8
#define EMPTY '-'
#define BLACK 'B'
#define WHITE 'W'

char board[ROWS][COLS];

void initialize_board() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i < 3 || i > 4) {
                if((i+j)%2 == 0) {
                    board[i][j] = EMPTY;
                } else {
                    board[i][j] = (i < 3) ? WHITE : BLACK;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board() {
    int i, j;
    printf("\n     1  2  3  4  5  6  7  8 \n");
    printf("   -------------------------\n");
    for(i = 0; i < ROWS; i++) {
        printf("%d |", i+1);
        for(j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("| %d\n", i+1);
    }
    printf("   -------------------------\n");
    printf("     1  2  3  4  5  6  7  8 \n");
}

int is_jump(int row1, int col1, int row2, int col2) {
    int row_mid = (row1 + row2) / 2;
    int col_mid = (col1 + col2) / 2;
    if(board[row2][col2] != EMPTY || board[row_mid][col_mid] == EMPTY) {
        return 0;
    }
    if(board[row1][col1] == WHITE && row2 > row1) {
        return 0;
    }
    if(board[row1][col1] == BLACK && row2 < row1) {
        return 0;
    }
    if(abs(row1-row2) == 2 && abs(col1-col2) == 2) {
        return 1;
    }
    return 0;
}

int is_move_valid(int row1, int col1, int row2, int col2) {
    if(row2 < 0 || row2 > ROWS-1 || col2 < 0 || col2 > COLS-1) {
        return 0;
    }
    if(board[row2][col2] != EMPTY) {
        return 0;
    }
    if(board[row1][col1] == WHITE && row2 > row1) {
        return 0;
    }
    if(board[row1][col1] == BLACK && row2 < row1) {
        return 0;
    }
    if(abs(row1-row2) == 1 && abs(col1-col2) == 1) {
        return 1;
    }
    if(is_jump(row1, col1, row2, col2)) {
        return 1;
    }
    return 0;
}

int player_can_jump(int player) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == ((player == 1) ? WHITE : BLACK)) {
                if(is_move_valid(i, j, i+2, j+2) || is_move_valid(i, j, i+2, j-2) || is_move_valid(i, j, i-2, j+2) || is_move_valid(i, j, i-2, j-2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int game_over() {
    int i, j, black_count = 0, white_count = 0;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == BLACK) {
                black_count++;
            } else if(board[i][j] == WHITE) {
                white_count++;
            }
        }
    }
    return (black_count == 0 || white_count == 0 || !player_can_jump(1) || !player_can_jump(2));
}

void make_move(int row1, int col1, int row2, int col2) {
    int row_mid = (row1 + row2) / 2;
    int col_mid = (col1 + col2) / 2;
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = EMPTY;
    if(abs(row1-row2) == 2 && abs(col1-col2) == 2) {
        board[row_mid][col_mid] = EMPTY;
    }
}

int main() {
    initialize_board();
    int player = 1, moves, i, j, row1, col1, row2, col2;
    while(!game_over()) {
        print_board();
        printf("Player %d's turn:\n", player);
        moves = 0;
        while(moves == 0) {
            printf("Enter a piece to move (row column): ");
            scanf("%d %d", &row1, &col1);
            if(board[row1-1][col1-1] == ((player == 1) ? WHITE : BLACK)) {
                printf("Enter a place to move to (row column): ");
                scanf("%d %d", &row2, &col2);
                if(is_move_valid(row1-1, col1-1, row2-1, col2-1)) {
                    make_move(row1-1, col1-1, row2-1, col2-1);
                    moves = 1;
                } else {
                    printf("Invalid move, please try again.\n");
                }
            } else {
                printf("Invalid piece, please try again.\n");
            }
        }
        if(player_can_jump(player) && is_jump(row2-1, col2-1, row2-3, col2-3)) {
            for(i = -1; i <= 1; i += 2) {
                for(j = -1; j <= 1; j += 2) {
                    if(is_move_valid(row2-1, col2-1, row2+i, col2+j)) {
                        printf("Jump available, must jump.\n");
                        row1 = row2;
                        col1 = col2;
                        row2 = row2+i*2;
                        col2 = col2+j*2;
                        make_move(row1-1, col1-1, row2-1, col2-1);
                        break;
                    }
                }
            }
        } else {
            player = (player == 1) ? 2 : 1;
        }
    }
    print_board();
    if(player_can_jump(player)) {
        printf("Player %d wins!\n", player);
    } else {
        printf("Game over, no moves left!\n");
    }
    return 0;
}