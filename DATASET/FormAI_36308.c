//FormAI DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Representing the game board with a 2D array
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board with pieces at their starting positions
void initialize_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == 2) {
                if (j % 2 == 0) {
                    board[i][j] = 'W';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i == 1) {
                if (j % 2 == 1) {
                    board[i][j] = 'W';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i == 5 || i == 7) {
                if (j % 2 == 1) {
                    board[i][j] = 'B';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i == 6) {
                if (j % 2 == 0) {
                    board[i][j] = 'B';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Print the board
void print_board() {
    int i, j;

    printf("  0 1 2 3 4 5 6 7\n");
    printf("-----------------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

// Check if the move is valid
int is_valid_move(int source_x, int source_y, int dest_x, int dest_y, char player) {
    if (dest_x < 0 || dest_x >= BOARD_SIZE || dest_y < 0 || dest_y >= BOARD_SIZE) {
        // Destination is out of bounds
        return 0;
    }

    if (source_x == dest_x && source_y == dest_y) {
        // Source and destination are the same
        return 0;
    }

    if (board[dest_x][dest_y] != ' ') {
        // Destination is not empty
        return 0;
    }

    if (player == 'W') {
        if (board[source_x][source_y] != 'W' && board[source_x][source_y] != 'K') {
            // Source does not contain a white piece
            return 0;
        }

        if (dest_x < source_x) {
            // White pieces can only move downwards
            return 0;
        }

        if (abs(dest_x - source_x) != 1 || abs(dest_y - source_y) != 1) {
            // White pieces can only move diagonally by one space
            return 0;
        }

        return 1;
    } else {
        if (board[source_x][source_y] != 'B' && board[source_x][source_y] != 'K') {
            // Source does not contain a black piece
            return 0;
        }

        if (dest_x > source_x) {
            // Black pieces can only move upwards
            return 0;
        }

        if (abs(dest_x - source_x) != 1 || abs(dest_y - source_y) != 1) {
            // Black pieces can only move diagonally by one space
            return 0;
        }

        return 1;
    }
}

// Make a move
void make_move(int source_x, int source_y, int dest_x, int dest_y, char player) {
    // If the move is made by a king, we do not remove the piece from the board
    if (board[source_x][source_y] == 'K') {
        board[source_x][source_y] = ' ';
        board[dest_x][dest_y] = 'K';
        return;
    }

    // Move the piece to the destination
    board[dest_x][dest_y] = board[source_x][source_y];
    board[source_x][source_y] = ' ';

    // If the piece is at the edge of the board, promote it to a king
    if (dest_x == 0 && board[dest_x][dest_y] == 'B') {
        board[dest_x][dest_y] = 'K';
    } else if (dest_x == BOARD_SIZE - 1 && board[dest_x][dest_y] == 'W') {
        board[dest_x][dest_y] = 'K';
    }
}

int main() {
    int game_over = 0, white_turn = 1;
    int source_x, source_y, dest_x, dest_y;
    char player;

    initialize_board();

    while (!game_over) {
        print_board();

        if (white_turn) {
            printf("White player's turn\n");
            player = 'W';
        } else {
            printf("Black player's turn\n");
            player = 'B';
        }

        printf("Enter source coordinates: ");
        scanf("%d %d", &source_x, &source_y);
        printf("Enter destination coordinates: ");
        scanf("%d %d", &dest_x, &dest_y);

        if (is_valid_move(source_x, source_y, dest_x, dest_y, player)) {
            make_move(source_x, source_y, dest_x, dest_y, player);
            white_turn = !white_turn;
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}