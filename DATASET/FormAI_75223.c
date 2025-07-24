//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>

void print_board(int board[][8]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i=0; i<8; i++) {
        printf("%d ", i);
        for (int j=0; j<8; j++) {
            switch(board[i][j]) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("w ");
                    break;
                case 2:
                    printf("b ");
                    break;
                case 3:
                    printf("W ");
                    break;
                case 4:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void initialize_board(int board[][8]) {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (i<3 && (i+j)%2==0) {
                board[i][j] = 2;
            }
            else if (i>4 && (i+j)%2==0) {
                board[i][j] = 1;
            }
            else {
                board[i][j] = 0;
            }
        }
    }
}

int move_piece(int old_row, int old_col, int new_row, int new_col, int board[][8], int turn) {
    if (new_row < 0 || new_col < 0 || new_row > 7 || new_col > 7) {
        return 0;
    }
    if (board[new_row][new_col] != 0) {
        return 0;
    }
    int distance = old_col - new_col;
    if (turn == 1 && (distance == -1 || distance == 1)) {
        if (new_row == old_row+1) {
            board[old_row][old_col] = 0;
            board[new_row][new_col] = 1;
            return 1;
        }
        else if (new_row == old_row+2 && board[old_row+1][old_col+distance] == 2) {
            board[old_row][old_col] = 0;
            board[old_row+1][old_col+distance] = 0;
            board[new_row][new_col] = 1;
            return 1;
        }
    }
    else if (turn == 2 && (distance == 1 || distance == -1)) {
        if (new_row == old_row-1) {
            board[old_row][old_col] = 0;
            board[new_row][new_col] = 2;
            return 1;
        }
        else if (new_row == old_row-2 && board[old_row-1][old_col+distance] == 1) {
            board[old_row][old_col] = 0;
            board[old_row-1][old_col+distance] = 0;
            board[new_row][new_col] = 2;
            return 1;
        }
    }
    else if (turn == 3 && (distance == -1 || distance == 1)) {
        if (new_row == old_row+1 || new_row == old_row-1) {
            board[old_row][old_col] = 0;
            board[new_row][new_col] = 3;
            return 1;
        }
        else if (new_row == old_row+2 && board[old_row+1][old_col+distance] == 2) {
            board[old_row][old_col] = 0;
            board[old_row+1][old_col+distance] = 0;
            board[new_row][new_col] = 3;
            return 1;
        }
        else if (new_row == old_row-2 && board[old_row-1][old_col+distance] == 2) {
            board[old_row][old_col] = 0;
            board[old_row-1][old_col+distance] = 0;
            board[new_row][new_col] = 3;
            return 1;
        }
    }
    else if (turn == 4 && (distance == 1 || distance == -1)) {
        if (new_row == old_row+1 || new_row == old_row-1) {
            board[old_row][old_col] = 0;
            board[new_row][new_col] = 4;
            return 1;
        }
        else if (new_row == old_row+2 && board[old_row+1][old_col+distance] == 1) {
            board[old_row][old_col] = 0;
            board[old_row+1][old_col+distance] = 0;
            board[new_row][new_col] = 4;
            return 1;
        }
        else if (new_row == old_row-2 && board[old_row-1][old_col+distance] == 1) {
            board[old_row][old_col] = 0;
            board[old_row-1][old_col+distance] = 0;
            board[new_row][new_col] = 4;
            return 1;
        }
    }
    return 0;
}

int main() {
    int board[8][8];
    initialize_board(board);
    int turn = 1;
    while (1) {
        print_board(board);
        printf("Turn %d:\n", turn);
        int old_row, old_col, new_row, new_col;
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &old_row, &old_col);
        printf("Enter the row and column of the spot you want to move to: ");
        scanf("%d %d", &new_row, &new_col);
        if (move_piece(old_row, old_col, new_row, new_col, board, turn)) {
            if (turn == 1) {
                if (new_row == 7) {
                    board[new_row][new_col] = 3;
                }
                turn = 2;
            }
            else if (turn == 2) {
                if (new_row == 0) {
                    board[new_row][new_col] = 4;
                }
                turn = 1;
            }
            else if (turn == 3) {
                if (new_row == 7) {
                    board[new_row][new_col] = 4;
                }
                else if (new_row == 0) {
                    board[new_row][new_col] = 2;
                }
                turn = 4;
            }
            else if (turn == 4) {
                if (new_row == 7) {
                    board[new_row][new_col] = 4;
                }
                else if (new_row == 0) {
                    board[new_row][new_col] = 1;
                }
                turn = 1;
            }
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}