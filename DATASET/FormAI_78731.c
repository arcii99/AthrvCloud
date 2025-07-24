//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define DIM 8

int board[DIM][DIM];

void initialize_board() {
    for(int i=0; i<DIM; i++) {
        for(int j=0; j<DIM; j++) {
            if(i%2 == j%2) {
                if(i<3) board[i][j] = 1;
                else if(i>4) board[i][j] = 2;
                else board[i][j] = 0;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board() {
    printf("\n  A B C D E F G H\n");
    for(int i=0; i<DIM; i++) {
        printf("%d ", i+1);
        for(int j=0; j<DIM; j++) {
            switch(board[i][j]) {
                case 0: printf(". "); break;
                case 1: printf("O "); break;
                case 2: printf("X "); break;
                case 3: printf("K "); break;
            }
        }
        printf("%d\n", i+1);
    }
    printf("  A B C D E F G H\n");
}

int move(int curr_player, int row, int col, int n_row, int n_col) {
    // check all the invalid moves
    if(n_row < 0 || n_col < 0 || n_row >= DIM || n_col >= DIM) {
        printf("Invalid move: out of bounds.\n");
        return 0;
    }
    if(board[n_row][n_col] != 0) {
        printf("Invalid move: the target cell is occupied.\n");
        return 0;
    }
    if(curr_player == 1 && row < n_row) {
        printf("Invalid move: wrong direction.\n");
        return 0;
    }
    if(curr_player == 2 && row > n_row) {
        printf("Invalid move: wrong direction.\n");
        return 0;
    }
    if(board[row][col] == 1 && n_row - row > 1) {
        if(board[row+1][col+1] != 2 && board[row+1][col-1] != 2) {
            printf("Invalid move: can't jump over an empty cell.\n");
            return 0;
        } else if(n_col - col > 1 && board[row+1][col+1] != 2) {
            printf("Invalid move: can't make a diagonal move.\n");
            return 0;
        } else if(col - n_col > 1 && board[row+1][col-1] != 2) {
            printf("Invalid move: can't make a diagonal move.\n");
            return 0;
        } else {
            board[row+1][(col+n_col)/2] = 0;
        }
    }
    if(board[row][col] == 2 && row - n_row > 1) {
        if(board[row-1][col+1] != 1 && board[row-1][col-1] != 1) {
            printf("Invalid move: can't jump over an empty cell.\n");
            return 0;
        } else if(n_col - col > 1 && board[row-1][col+1] != 1) {
            printf("Invalid move: can't make a diagonal move.\n");
            return 0;
        } else if(col - n_col > 1 && board[row-1][col-1] != 1) {
            printf("Invalid move: can't make a diagonal move.\n");
            return 0;
        } else {
            board[row-1][(col+n_col)/2] = 0;
        }
    }
    // make the move
    board[n_row][n_col] = curr_player;
    board[row][col] = 0;
    // check if a pawn is promoted to king
    if(curr_player == 1 && n_row == DIM-1) board[n_row][n_col] = 3;
    if(curr_player == 2 && n_row == 0) board[n_row][n_col] = 3;
    return 1;
}

int check_win(int curr_player) {
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<DIM; i++) {
        for(int j=0; j<DIM; j++) {
            if(board[i][j] == curr_player || board[i][j] == curr_player+2) count1++;
            if(board[i][j] == 3-curr_player || board[i][j] == 3-curr_player+2) count2++;
        }
    }
    if(count1 == 0) return 2;
    if(count2 == 0) return 1;
    return 0;
}

int main() {
    int curr_player = 1;
    int game_over = 0;
    int row, col, n_row, n_col;
    initialize_board();
    while(!game_over) {
        print_board();
        printf("Player %d's turn.\n", curr_player);
        printf("Enter the row and column of the piece you want to move and the row and column of the target cell:\n");
        scanf("%d%d%d%d", &row, &col, &n_row, &n_col);
        if(move(curr_player, row-1, col-1, n_row-1, n_col-1)) {
            int res = check_win(curr_player);
            if(res != 0) {
                printf("Player %d wins!\n", res);
                game_over = 1;
            } else {
                curr_player = 3 - curr_player;
            }
        }
    }
    return 0;
}