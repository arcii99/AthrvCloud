//FormAI DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

struct move {
    int row;
    int col;
};

int is_valid_move(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    
    if (board[row][col] != ' ') {
        return 0;
    }
    
    return 1;
}

void get_valid_moves(int player, struct move moves[], int *num_moves) {
    int i, j;
    char piece;
    struct move m;
    
    *num_moves = 0;
    
    if (player == 1) {
        piece = 'X';
    } else {
        piece = 'O';
    }
    
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == piece) {
                m.row = i - 1;
                m.col = j - 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i - 1;
                m.col = j;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i - 1;
                m.col = j + 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i;
                m.col = j - 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i;
                m.col = j + 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i + 1;
                m.col = j - 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i + 1;
                m.col = j;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
                
                m.row = i + 1;
                m.col = j + 1;
                if (is_valid_move(m.row, m.col)) {
                    moves[*num_moves] = m;
                    *num_moves += 1;
                }
            }
        }
    }
}

int make_move(int player, int row, int col) {
    int i, j;
    char piece;
    
    if (player == 1) {
        piece = 'X';
    } else {
        piece = 'O';
    }
    
    if (!is_valid_move(row, col)) {
        return 0;
    }
    
    board[row][col] = piece;
    
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && row+i >= 0 && row+i < BOARD_SIZE && col+j >= 0 && col+j < BOARD_SIZE && board[row+i][col+j] == piece) {
                int m = 0;
                while (is_valid_move(row+i+m*(i!=0), col+j+m*(j!=0))) {
                    m++;
                }
                if (m > 0 && row+i+m*(i!=0) >= 0 && row+i+m*(i!=0) < BOARD_SIZE && col+j+m*(j!=0) >= 0 && col+j+m*(j!=0) < BOARD_SIZE && board[row+i+m*(i!=0)][col+j+m*(j!=0)] != piece) {
                    for (int n = 1; n < m; n++) {
                        board[row+i+n*(i!=0)][col+j+n*(j!=0)] = piece;
                    }
                }
            }
        }
    }
    
    return 1;
}

int main() {
    int player = 1, x, y, num_moves = 0;
    char input[10];
    struct move moves[BOARD_SIZE * BOARD_SIZE];
    
    memset(board, ' ', BOARD_SIZE*BOARD_SIZE);
    
    board[3][3] = 'X';
    board[3][4] = 'O';
    board[4][3] = 'O';
    board[4][4] = 'X';
    
    while (1) {
        get_valid_moves(player, moves, &num_moves);
        
        if (num_moves == 0) {
            printf("Player %d has no valid moves. Switching to player %d\n", player, 3 - player);
            player = 3 - player;
            continue;
        }
        
        for (int i = 0; i < num_moves; i++) {
            printf("(%d, %d) ", moves[i].row, moves[i].col);
        }
        printf("\n");
        
        printf("Player %d, enter your move (row, col): ", player);
        fgets(input, 10, stdin);
        
        x = input[0] - '0';
        y = input[2] - '0';
        
        if (make_move(player, x, y)) {
            player = 3 - player;
        } else {
            printf("Invalid move. Try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}