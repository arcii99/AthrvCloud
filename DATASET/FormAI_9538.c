//FormAI DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE]; // initialize an empty checkerboard

void init_board() {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(i % 2 == j % 2) {
                if(i < 3)
                    board[i][j] = 'X';
                else if(i > 4)
                    board[i][j] = 'O';
                else
                    board[i][j] = ' ';
            }
            else
                board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;

    printf("  ");
    for(i = 0; i < SIZE; i++)
        printf("%d ", i+1);
    printf("\n");

    for(i = 0; i < SIZE; i++) {
        printf("%d ", i+1);
        for(j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int is_valid_move(int src_x, int src_y, int dest_x, int dest_y, char player) {
    // Check that the destination is within the bounds of the board.
    if(dest_x < 0 || dest_x >= SIZE || dest_y < 0 || dest_y >= SIZE)
        return 0;

    // Check that the destination is empty.
    if(board[dest_x][dest_y] != ' ')
        return 0;

    // Check that the player is moving their own piece.
    if(player == 'X' && board[src_x][src_y] != 'X')
        return 0;
    if(player == 'O' && board[src_x][src_y] != 'O')
        return 0;

    // Check that the move is diagonal.
    if(abs(dest_x - src_x) != abs(dest_y - src_y))
        return 0;

    // Check that the move is by exactly one row and one column.
    if(abs(dest_x - src_x) != 1)
        return 0;
    if(abs(dest_y - src_y) != 1)
        return 0;

    return 1;
}

int check_move(char player) {
    int src_x, src_y, dest_x, dest_y;
    printf("%c's turn. Enter move: ", player);
    scanf("%d %d %d %d", &src_x, &src_y, &dest_x, &dest_y);

    if(!is_valid_move(src_x-1, src_y-1, dest_x-1, dest_y-1, player)) {
        printf("Invalid move, try again.\n");
        return check_move(player);
    }

    if(player == 'X') {
        if(dest_x == SIZE-1)
            board[dest_x][dest_y] = 'K';
        else
            board[dest_x][dest_y] = 'X';
        board[src_x-1][src_y-1] = ' ';
    }
    else {
        if(dest_x == 0)
            board[dest_x][dest_y] = 'K';
        else
            board[dest_x][dest_y] = 'O';
        board[src_x-1][src_y-1] = ' ';
    }

    return 1;
}

int main() {
    int i, j;
    char player = 'X';

    init_board();

    while(1) {
        print_board();
        if(player == 'X') {
            if(!check_move(player))
                continue;
            player = 'O';
        }
        else {
            if(!check_move(player))
                continue;
            player = 'X';
        }
    }

    return 0;
}