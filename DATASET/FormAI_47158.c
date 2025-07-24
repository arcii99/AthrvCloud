//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int x, y;
} coord;

typedef enum {
    EMPTY,
    RED_PIECE,
    BLACK_PIECE,
    RED_KING,
    BLACK_KING
} piece;

// Function to print the game board
void print_board(piece board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case EMPTY:
                    printf("_ ");
                    break;
                case RED_PIECE:
                    printf("r ");
                    break;
                case BLACK_PIECE:
                    printf("b ");
                    break;
                case RED_KING:
                    printf("R ");
                    break;
                case BLACK_KING:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to move a piece
bool move_piece(coord start, coord end, piece board[BOARD_SIZE][BOARD_SIZE]) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    if (dx != dy || dx > 2 || start.x < 0 || start.x >= BOARD_SIZE || start.y < 0 || start.y >= BOARD_SIZE || end.x < 0 || end.x >= BOARD_SIZE || end.y < 0 || end.y >= BOARD_SIZE) {
        return false;
    }
    piece p = board[start.x][start.y];
    if (p == EMPTY) {
        return false;
    }
    if (dx == 1) {
        // Normal move
        if (board[end.x][end.y] != EMPTY) {
            return false;
        }
        if (p == RED_PIECE && end.x > start.x || p == BLACK_PIECE && end.x < start.x) {
            // Can only move forward
            return false;
        }
        board[start.x][start.y] = EMPTY;
        board[end.x][end.y] = p;
        return true;
    } else {
        // Capture move
        int mid_x = (start.x + end.x) / 2;
        int mid_y = (start.y + end.y) / 2;
        piece mid = board[mid_x][mid_y];
        if (p == RED_PIECE && end.x > start.x || p == BLACK_PIECE && end.x < start.x || mid == EMPTY || (p == RED_PIECE && (mid == RED_PIECE || mid == RED_KING)) || (p == BLACK_PIECE && (mid == BLACK_PIECE || mid == BLACK_KING))) {
            return false;
        }
        board[start.x][start.y] = EMPTY;
        board[mid_x][mid_y] = EMPTY;
        board[end.x][end.y] = p;
        if (end.x == 0 && p == BLACK_PIECE) {
            // Promote to king
            board[end.x][end.y] = BLACK_KING;
        } else if (end.x == BOARD_SIZE - 1 && p == RED_PIECE) {
            // Promote to king
            board[end.x][end.y] = RED_KING;
        }
        return true;
    }
}

// Function to check if a player has won
bool game_over(piece board[BOARD_SIZE][BOARD_SIZE]) {
    bool red_pieces = false;
    bool black_pieces = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED_PIECE || board[i][j] == RED_KING) {
                red_pieces = true;
            } else if (board[i][j] == BLACK_PIECE || board[i][j] == BLACK_KING) {
                black_pieces = true;
            }
            if (red_pieces && black_pieces) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    piece board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE},
        {RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY},
        {EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE, EMPTY, RED_PIECE},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY},
        {EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE},
        {BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY, BLACK_PIECE, EMPTY}
    };
    coord start, end;
    char input[10];
    bool red_turn = true;
    bool game_on = true;
    while (game_on) {
        print_board(board);
        printf("Enter move (format: [start x] [start y] [end x] [end y]): ");
        fgets(input, 10, stdin);
        sscanf(input, "%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
        if (!move_piece(start, end, board)) {
            printf("Invalid move!\n");
            continue;
        }
        if (game_over(board)) {
            printf("Game over!\n");
            game_on = false;
        }
        red_turn = !red_turn;
    }
    return 0;
}