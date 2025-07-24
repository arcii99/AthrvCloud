//FormAI DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define N 8

void initialize_board(char board[][N]);
void print_board(char board[][N]);
void make_move(char board[][N], int from_x, int from_y, int to_x, int to_y);
int check_for_winner(char board[][N]);

int main() {
    char board[N][N];
    int from_x, from_y, to_x, to_y, turn = 1;
    initialize_board(board);
    while (1) {
        printf("Turn %d:\n", turn);
        print_board(board);
        printf("Player %d, please enter the coordinates of the piece you want to move (x y): ", turn);
        scanf("%d %d", &from_x, &from_y);
        printf("Player %d, please enter the coordinates of the square you want to move to (x y): ", turn);
        scanf("%d %d", &to_x, &to_y);
        make_move(board, from_x, from_y, to_x, to_y);
        int winner = check_for_winner(board);
        if (winner) {
            printf("Player %d is the winner!\n", winner);
            break;
        }
        turn = (turn == 1) ? 2 : 1;
    }
    return 0;
}

void initialize_board(char board[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i % 2 == j % 2) {
                if (i < 3) {
                    board[i][j] = 'X';
                } else if (i > 4) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(char board[][N]) {
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < N; i++) {
        printf("%d ", i);
        for (j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move(char board[][N], int from_x, int from_y, int to_x, int to_y) {
    if (board[from_x][from_y] == ' ') {
        printf("No piece to move at (%d, %d)\n", from_x, from_y);
        return;
    }
    if (board[to_x][to_y] != ' ') {
        printf("Cannot move to (%d, %d), square is already occupied\n", to_x, to_y);
        return;
    }
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    if (board[from_x][from_y] == 'X') {
        if (dx == -1 && abs(dy) == 1 && board[to_x][to_y] == ' ') {
            board[to_x][to_y] = 'X';
            board[from_x][from_y] = ' ';
        }
        else if (dx == -2 && abs(dy) == 2 && board[from_x-1][from_y+dy/2] == 'O' && board[to_x][to_y] == ' ') {
            board[to_x][to_y] = 'X';
            board[from_x][from_y] = ' ';
            board[from_x-1][from_y+dy/2] = ' ';
        } else {
            printf("Invalid move\n");
        }
    } else if (board[from_x][from_y] == 'O') {
        if (dx == 1 && abs(dy) == 1 && board[to_x][to_y] == ' ') {
            board[to_x][to_y] = 'O';
            board[from_x][from_y] = ' ';
        } else if (dx == 2 && abs(dy) == 2 && board[from_x+1][from_y+dy/2] == 'X' && board[to_x][to_y] == ' ') {
            board[to_x][to_y] = 'O';
            board[from_x][from_y] = ' ';
            board[from_x+1][from_y+dy/2] = ' ';
        } else {
            printf("Invalid move\n");
        }
    }
}

int check_for_winner(char board[][N]) {
    int i, j, count_X = 0, count_O = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'x') count_X++;
            if (board[i][j] == 'O' || board[i][j] == 'o') count_O++;
        }
    }
    if (count_X == 0) {
        return 2;
    } else if (count_O == 0) {
        return 1;
    } else {
        return 0;
    }
}