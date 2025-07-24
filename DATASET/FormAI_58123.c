//FormAI DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define BLACK 1
#define WHITE 2
#define EMPTY 0

int board[8][8] = { //initializing the empty board
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0},
};

void display_board() { //displaying the board
    printf("\n  0 1 2 3 4 5 6 7\n");
    printf("  ----------------\n");
    for(int i=0; i<8; i++) {
        printf("%d|", i);
        for(int j=0; j<8; j++) {
            if(board[i][j] == EMPTY) {
                printf(" |");
            }
            else {
                printf("%d|", board[i][j]);
            }
        }
        printf("%d",i);
        printf("\n");
    }
    printf("  ----------------\n");
    printf("  0 1 2 3 4 5 6 7\n");
}

void move_piece(int start_x, int start_y, int end_x, int end_y) { //moving a piece from start to end
    board[end_x][end_y] = board[start_x][start_y];
    board[start_x][start_y] = EMPTY;
}

int valid_move(int player, int start_x, int start_y, int end_x, int end_y) { //checking if move is valid
    if(board[end_x][end_y] != EMPTY) {
        return 0;
    }
    if(player == BLACK) {
        if((end_x == start_x-1) && (end_y == start_y+1 || end_y == start_y-1)) {
            return 1;
        }
        if((end_x == start_x-2) && (end_y == start_y+2) && (board[start_x-1][start_y+1] == WHITE)) {
            board[start_x-1][start_y+1] = EMPTY;
            return 1;
        }
        if((end_x == start_x-2) && (end_y == start_y-2) && (board[start_x-1][start_y-1] == WHITE)) {
            board[start_x-1][start_y-1] = EMPTY;
            return 1;
        }
    }
    else if(player == WHITE) {
        if((end_x == start_x+1) && (end_y == start_y+1 || end_y == start_y-1)) {
            return 1;
        }
        if((end_x == start_x+2) && (end_y == start_y+2) && (board[start_x+1][start_y+1] == BLACK)) {
            board[start_x+1][start_y+1] = EMPTY;
            return 1;
        }
        if((end_x == start_x+2) && (end_y == start_y-2) && (board[start_x+1][start_y-1] == BLACK)) {
            board[start_x+1][start_y-1] = EMPTY;
            return 1;
        }
    }
    return 0;
}

int game_over() { //checking if game is over
    int black_pieces = 0, white_pieces = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == BLACK || board[i][j] == 1) {
                black_pieces++;
            }
            else if(board[i][j] == WHITE || board[i][j] == 2) {
                white_pieces++;
            }
        }
    }
    if(black_pieces == 0 || white_pieces == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int player = BLACK, gameover = 0, start_x, start_y, end_x, end_y;
    while(!gameover) {
        display_board();
        printf("\nPlayer %d's move\n", player);
        printf("Enter start position (row column): ");
        scanf("%d %d", &start_x, &start_y);
        printf("Enter end position (row column): ");
        scanf("%d %d", &end_x, &end_y);

        if(valid_move(player, start_x, start_y, end_x, end_y)) {
            move_piece(start_x, start_y, end_x, end_y);
            if(player == BLACK) {
                player = WHITE;
            }
            else if(player == WHITE) {
                player = BLACK;
            }
        }
        if(game_over()) {
            printf("Game over! ");
            if(player == BLACK) {
                printf("Player 2 (White) wins!");
            }
            else {
                printf("Player 1 (Black) wins!");
            }
            gameover = 1;
        }
    }
    return 0;
}