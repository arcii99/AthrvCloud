//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS] = {
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
    {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'}
};

void print_board(void) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_piece(int row, int col, int new_row, int new_col) {
    board[new_row][new_col] = board[row][col];
    board[row][col] = '_';
}

int is_valid_move(int row, int col, int new_row, int new_col, char player) {
    // Check if destination is empty
    if(board[new_row][new_col] != '_') {
        return 0;
    }
    // Check if moving in the right direction
    if(player == 'b' && new_row >= row) {
        return 0;
    }
    if(player == 'r' && new_row <= row) {
        return 0;
    }
    // Check if moving diagonally
    if((new_row == row+1 || new_row == row-1) && (new_col == col+1 || new_col == col-1)) {
        return 1;
    }
    // Check if jumping over a piece
    if((new_row == row+2 || new_row == row-2) && (new_col == col+2 || new_col == col-2)) {
        int jumped_row = (new_row < row) ? row-1 : row+1;
        int jumped_col = (new_col < col) ? col-1 : col+1;
        if(board[jumped_row][jumped_col] == '_') {
            return 0;
        }
        if(board[jumped_row][jumped_col] == player || board[jumped_row][jumped_col] == toupper(player)) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int is_game_over(void) {
    int i, j;
    int r_count = 0, b_count = 0;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 'r' || board[i][j] == 'R') {
                r_count++;
            } else if(board[i][j] == 'b' || board[i][j] == 'B') {
                b_count++;
            }
        }
    }
    if(r_count == 0) {
        printf("You Win, Black Player!\n");
        return 1;
    }
    if(b_count == 0) {
        printf("You Win, Red Player!\n");
        return 1;
    }
    return 0;   
}

int main(void) {
    int current_row, current_col, new_row, new_col, valid_move;
    char player = 'r';
    print_board();
    while(1) {
        printf("%c's Turn.\n", player);
        printf("Enter the current row and column (e.g. 3 2): ");
        scanf("%d %d", &current_row, &current_col);
        printf("Enter the new row and column (e.g. 4 1): ");
        scanf("%d %d", &new_row, &new_col);
        valid_move = is_valid_move(current_row, current_col, new_row, new_col, player);
        if(valid_move) {
            move_piece(current_row, current_col, new_row, new_col);
            if(player == 'r' && new_row == 0) {
                board[new_row][new_col] = 'R';
            }
            if(player == 'b' && new_row == 7) {
                board[new_row][new_col] = 'B';
            }
            print_board();
            if(is_game_over()) {
                break;
            }
            if(board[new_row][new_col] == 'r' || board[new_row][new_col] == 'b') {
                player = (player == 'r') ? 'b' : 'r';
            }
        } else {
            printf("Invalid Move. Try Again.\n");
        }
    }
    return 0;
}