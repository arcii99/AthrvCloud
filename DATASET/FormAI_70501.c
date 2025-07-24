//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define KING 3

int board[SIZE][SIZE] = { // Initialize board with pieces
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

int player = BLACK; // Set starting player
int game_over = 0; // Variable to check if game is over

// Function to print board
void print_board() {
    printf("\n     0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("   +----------------+\n");
        printf(" %d |", i);
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf("  ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
                case KING:
                    printf("K ");
                    break;
            }
        }
        printf("|\n");
    }
    printf("   +----------------+\n");
}

// Function to check if move is valid
int is_valid_move(int from_x, int from_y, int to_x, int to_y) {
    // Check if move is within board boundaries
    if (to_x < 0 || to_x >= SIZE || to_y < 0 || to_y >= SIZE) {
        return 0;
    }

    // Check if destination is empty
    if (board[to_x][to_y] != EMPTY) {
        return 0;
    }

    // Check if piece is moving in correct direction
    if (player == BLACK && to_x > from_x) {
        return 0;
    } else if (player == WHITE && to_x < from_x) {
        return 0;
    }

    // Check if piece is not moving diagonally
    if (from_x == to_x || from_y == to_y) {
        return 0;
    }

    // Check if piece is not moving more than 2 spaces
    if (abs(from_x - to_x) > 2 || abs(from_y - to_y) > 2) {
        return 0;
    }

    // Check if piece is jumping over another piece
    if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 2) {
        int x = (from_x + to_x) / 2;
        int y = (from_y + to_y) / 2;
        if (board[x][y] == EMPTY || board[x][y] == player) {
            return 0;
        } else {
            return 1;
        }
    }

    return 1;
}

// Function to move piece
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;

    // Check if piece becomes king
    if ((player == BLACK && to_x == 0) || (player == WHITE && to_x == SIZE - 1)) {
        board[to_x][to_y] = KING;
    }

    // Check if piece is jumping over another piece
    if (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 2) {
        int x = (from_x + to_x) / 2;
        int y = (from_y + to_y) / 2;
        board[x][y] = EMPTY;
    }
}

// Function to check if player can make any moves
int can_move() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
                if (is_valid_move(i, j, i + 1, j + 1) || is_valid_move(i, j, i + 1, j - 1) || is_valid_move(i, j, i - 1, j + 1) || is_valid_move(i, j, i - 1, j - 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to switch player
void switch_player() {
    if (player == BLACK) {
        player = WHITE;
    } else {
        player = BLACK;
    }
}

// Function to check if game is over
void check_game_over() {
    int black_pieces = 0;
    int white_pieces = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLACK || board[i][j] == KING) {
                black_pieces++;
            } else if (board[i][j] == WHITE || board[i][j] == KING) {
                white_pieces++;
            }
        }
    }

    if (black_pieces == 0 || white_pieces == 0) {
        game_over = 1;
        printf("\nGame over!");
        if (black_pieces == 0) {
            printf("\nWhite wins!");
        } else {
            printf("\nBlack wins!");
        }
    }
}

int main() {
    srand(time(NULL)); // Set seed for random number generator

    printf("Welcome to Checkers!\n");
    print_board();

    while (!game_over) {
        printf("\nPlayer %d's turn:\n", player);
        if (!can_move()) {
            printf("No moves available, skipping turn.\n");
            switch_player();
            continue;
        }

        int from_x, from_y, to_x, to_y;
        do {
            printf("Enter piece coordinates and destination coordinates (x y x y): ");
            scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        } while (!is_valid_move(from_x, from_y, to_x, to_y));

        move_piece(from_x, from_y, to_x, to_y);
        print_board();
        check_game_over();
        switch_player();
    }

    return 0;
}