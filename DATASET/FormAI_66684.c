//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {EMPTY, BLACK, WHITE} piece;

typedef struct {
    int row;
    int col;
} move;

void initialize_board(piece board[][BOARD_SIZE]);
void print_board(piece board[][BOARD_SIZE]);
int is_move_valid(piece board[][BOARD_SIZE], int player, move mv);
void make_move(piece board[][BOARD_SIZE], int player, move mv);
int is_game_over(piece board[][BOARD_SIZE]);
int has_won(piece board[][BOARD_SIZE], int player);

int main() {
    piece board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    int current_player = BLACK;
    while(!is_game_over(board)) {
        printf("It is %s's turn.\n", current_player == BLACK ? "black" : "white");
        move mv;
        mv.row = mv.col = -1;
        while(!is_move_valid(board, current_player, mv)) {
            printf("Enter your move (row col): ");
            scanf("%d %d", &mv.row, &mv.col);
        }
        make_move(board, current_player, mv);
        print_board(board);
        current_player = current_player == BLACK ? WHITE : BLACK;
    }
    if(has_won(board, BLACK)) {
        printf("Black wins!\n");
    } else if(has_won(board, WHITE)) {
        printf("White wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}

void initialize_board(piece board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i < 3) {
                board[i][j] = WHITE;
            } else if(i > 4) {
                board[i][j] = BLACK;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(piece board[][BOARD_SIZE]) {
    int i, j;
    printf("  ");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == EMPTY ? '.' : board[i][j] == BLACK ? 'B' : 'W');
        }
        printf("%d ", i);
        printf("\n");
    }
    printf("  ");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int is_move_valid(piece board[][BOARD_SIZE], int player, move mv) {
    if(mv.row < 0 || mv.row >= BOARD_SIZE || mv.col < 0 || mv.col >= BOARD_SIZE) {
        return 0;
    }
    if(board[mv.row][mv.col] != EMPTY) {
        return 0;
    }
    if(player == BLACK) {
        if(mv.row <= 0 || mv.row >= BOARD_SIZE || mv.col <= 0 || mv.col >= BOARD_SIZE) {
            return 0;
        }
        if((board[mv.row-1][mv.col-1] != WHITE || board[mv.row-1][mv.col+1] != WHITE) && mv.row < BOARD_SIZE-1) {
            return 0;
        }
        return 1;
    } else { // white player
        if(mv.row <= 0 || mv.row >= BOARD_SIZE || mv.col <= 0 || mv.col >= BOARD_SIZE) {
            return 0;
        }
        if((board[mv.row+1][mv.col-1] != BLACK || board[mv.row+1][mv.col+1] != BLACK) && mv.row > 0) {
            return 0;
        }
        return 1;
    }
}

void make_move(piece board[][BOARD_SIZE], int player, move mv) {
    board[mv.row][mv.col] = player;
}

int is_game_over(piece board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int has_won(piece board[][BOARD_SIZE], int player) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                if(player == BLACK && (i == BOARD_SIZE-1 || board[i+1][j-1] == WHITE || board[i+1][j+1] == WHITE)) {
                    return 1;
                } else if(player == WHITE && (i == 0 || board[i-1][j-1] == BLACK || board[i-1][j+1] == BLACK)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}