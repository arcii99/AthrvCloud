//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define RED 1
#define BLACK 2
#define RED_KING 3
#define BLACK_KING 4

typedef struct {
    int row;
    int col;
} move;

int board[BOARD_SIZE][BOARD_SIZE] = {
    {0,2,0,2,0,2,0,2},
    {2,0,2,0,2,0,2,0},
    {0,2,0,2,0,2,0,2},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
};

void print_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(move mv, int player) {
    if(board[mv.row][mv.col] != EMPTY) return false;
    
    // Check if regular move
    int enemy = (player == RED) ? BLACK : RED;
    int dir = (player == RED) ? 1 : -1;
    
    if(mv.row == (0+3*(player == BLACK)) || mv.row == (BOARD_SIZE-1-3*(player == RED))) return false;
    
    if(abs(mv.row - mv.col) % 2 == 1 && abs(mv.row - mv.col) % 2 == 1) return false;
    
    if(mv.row - dir < 0 || mv.row - dir >= BOARD_SIZE || 
       mv.col - 1 < 0 || mv.col + 1 >= BOARD_SIZE) return false;

    if(mv.row - dir < 0 || mv.row - dir >= BOARD_SIZE || 
       mv.col + 1 < 0 || mv.col + 1 >= BOARD_SIZE) return false;

    if(board[mv.row - dir][mv.col - 1] == enemy &&
       board[mv.row - 2*dir][mv.col + 2*dir] == EMPTY) return true;

    return false;
}

void make_move(move mv, int player) {
    if(is_valid_move(mv, player)) {
        board[mv.row][mv.col] = player;
        int dir = (player == RED) ? 1 : -1;
        int enemy = (player == RED) ? BLACK : RED;
        
        if(mv.row - dir == 0 || mv.row - dir == BOARD_SIZE - 1) {
            board[mv.row][mv.col] = (player == RED) ? RED_KING : BLACK_KING;
        }
        
        if(mv.row == 2 || mv.row == BOARD_SIZE-3) {
            if(board[mv.row + dir][mv.col + 1] == enemy) {
                board[mv.row + dir][mv.col + 1] = EMPTY;
            }
            else {
                board[mv.row + dir][mv.col - 1] = EMPTY;
            }
        }
    }
}

int main() {
    printf("Welcome to checkers game!\n");
    print_board();
    move mv = {2,1};
    make_move(mv, RED);
    printf("\nAfter move:\n");
    print_board();
    return 0;
}