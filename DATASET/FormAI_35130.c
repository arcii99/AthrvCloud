//FormAI DATASET v1.0 Category: Chess AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum size of the chessboard and the maximum number of moves
#define BOARD_SIZE 8
#define MAX_MOVES 100

// define the colors of the pieces on the board
#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'

// define the possible directions that a piece can move
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1

// function to print the current state of the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a given position is within the bounds of the board
int in_bounds(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// function to check if a given position is empty
int is_empty(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    return board[x][y] == EMPTY;
}

// function to check if a given position is occupied by an enemy piece
int is_enemy(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char color) {
    return board[x][y] != EMPTY && board[x][y] != color;
}

// function to check if a given position can be attacked by a pawn of the given color
int can_pawn_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char color) {
    int direction = color == BLACK ? DOWN : UP;
    int left_x = x + direction;
    int left_y = y + LEFT;
    int right_x = x + direction;
    int right_y = y + RIGHT;
    return in_bounds(left_x, left_y) && is_enemy(board, left_x, left_y, color) ||
           in_bounds(right_x, right_y) && is_enemy(board, right_x, right_y, color);
}

// function to check if a given position can be attacked by a rook of the given color
int can_rook_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char color) {
    int directions[4][2] = {{LEFT, 0}, {0, UP}, {RIGHT, 0}, {0, DOWN}};
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int curr_x = x + dx;
        int curr_y = y + dy;
        while (in_bounds(curr_x, curr_y)) {
            if (is_enemy(board, curr_x, curr_y, color)) {
                return 1;
            } else if (!is_empty(board, curr_x, curr_y)) {
                break;
            }
            curr_x += dx;
            curr_y += dy;
        }
    }
    return 0;
}

// main function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    char player = WHITE;
    int moves[MAX_MOVES][4];
    int move_count = 0;

    printf("Welcome to Chess AI! The current board is:\n");
    print_board(board);

    // check if the player is in check
    int is_check = 0;
    int king_x, king_y;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player + 32) {
                king_x = i;
                king_y = j;
            }
        }
    }
    if (can_pawn_attack(board, king_x, king_y, player) ||
        can_rook_attack(board, king_x, king_y, player)) {
        printf("Player %c is in check!\n", player);
        is_check = 1;
    }

    // get player input and execute their move
    while (1) {
        int start_x, start_y, end_x, end_y;
        printf("Player %c, enter your move (e.g. a2 to a4): ", player);
        char input[6];
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%c%d to %c%d", &start_y, &start_x, &end_y, &end_x) != 4) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        start_x--;
        start_y -= 'a';
        end_x--;
        end_y -= 'a';
        if (!in_bounds(start_x, start_y) || !in_bounds(end_x, end_y)) {
            printf("Invalid position. Try again.\n");
            continue;
        }
        if (is_empty(board, start_x, start_y)) {
            printf("There is no piece there. Try again.\n");
            continue;
        }
        if (board[start_x][start_y] != player + 32) {
            printf("You can only move your own pieces. Try again.\n");
            continue;
        }
        if (!is_empty(board, end_x, end_y) && !is_enemy(board, end_x, end_y, player)) {
            printf("You cannot capture your own pieces. Try again.\n");
            continue;
        }
        board[end_x][end_y] = board[start_x][start_y];
        board[start_x][start_y] = EMPTY;
        moves[move_count][0] = start_x;
        moves[move_count][1] = start_y;
        moves[move_count][2] = end_x;
        moves[move_count][3] = end_y;
        move_count++;

        // check if the player is in checkmate
        if (is_check && !can_pawn_attack(board, king_x, king_y, player) &&
            !can_rook_attack(board, king_x, king_y, player)) {
            printf("Player %c is in checkmate! Game over.\n", player);
            return 0;
        }

        // switch players
        player = player == WHITE ? BLACK : WHITE;

        printf("The current board is:\n");
        print_board(board);
    }
    return 0;
}