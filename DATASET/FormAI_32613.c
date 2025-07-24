//FormAI DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[8][8]; // initialize the board

void print_board() {
    printf("   0  1  2  3  4  5  6  7\n");
    printf(" +----------------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) printf("  ");
            else if (board[i][j] == 1) printf("b ");
            else if (board[i][j] == 2) printf("w ");
        }
        printf("|\n");
    }
    printf(" +----------------------+\n");
}

void init_board() {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(i < 3) {
                if((i + j) % 2 == 0) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
            else if(i > 4) {
                if((i + j) % 2 == 0) {
                    board[i][j] = 2;
                }
                else {
                    board[i][j] = 0;
                }
            }
            else {
                board[i][j] = 0;
            }
        }
    }
}

void move_piece() {
    int x, y, i, j;
    printf("Enter the coordinates of the piece you want to move (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the coordinates of the square where you want to move the piece (i j): ");
    scanf("%d %d", &i, &j);
    
    if(board[x][y] == 0) {
        printf("There is no piece at that position.\n");
        move_piece();
    }
    else if(board[i][j] != 0) {
        printf("There is already a piece at that position.\n");
        move_piece();
    }
    else {
        int dx, dy;
        int player = board[x][y];
        if(player == 1) {
            dx = -1;
        } else {
            dx = 1;
        }
        dy = abs(y - j);
        if(dy == 1) {
            if(abs(x - i) == 1) {
                board[i][j] = player;
                board[x][y] = 0;
            } else if(abs(x - i) == 2 && board[(i + x)/2][(j + y)/2] != player && board[(i + x)/2][(j + y)/2] != 0) {
                board[i][j] = player;
                board[x][y] = 0;
                board[(i + x)/2][(j + y)/2] = 0;
            } else {
                printf("Invalid move.\n");
                move_piece();
            }
        } else if(dy == 0) {
            if(abs(x - i) == 1) {
                board[i][j] = player;
                board[x][y] = 0;
            } else if(abs(x - i) == 2 && board[(i + x)/2][(j + y)/2] != player && board[(i + x)/2][(j + y)/2] != 0) {
                board[i][j] = player;
                board[x][y] = 0;
                board[(i + x)/2][(j + y)/2] = 0;
            } else {
                printf("Invalid move.\n");
                move_piece();
            }
        } else {
            printf("Invalid move.\n");
            move_piece();
        }
    }
}

int count_pieces(int player) {
    int count = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
            }
        }
    }
    return count;
}

int is_game_over() { 
    if(count_pieces(1) == 0 || count_pieces(2) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    init_board();
    while(!is_game_over()) {
        print_board();
        move_piece();
    }
    printf("\nGAME OVER\n");
    printf("Player 1: %d\n", count_pieces(1));
    printf("Player 2: %d\n", count_pieces(2));
    return 0;
}