//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

// Initialize the game board to all zeroes
void initialize_board(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

// Print the game board to the console
void print_board(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Move the player's ship to the left or right
void move_ship(int *ship_pos, int direction) {
    if (direction == -1 && *ship_pos > 0) {
        *ship_pos -= 1;
    } else if (direction == 1 && *ship_pos < BOARD_WIDTH-1) {
        *ship_pos += 1;
    }
}

// Spawn an invader in a random column of the top row of the board
void spawn_invader(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int col = rand() % BOARD_WIDTH;
    board[0][col] = 1;
}

// Move all invaders down by one row and spawn a new invader at the top
void move_invaders(int board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = BOARD_HEIGHT-1; i >= 0; i--) {
        for (int j = BOARD_WIDTH-1; j >= 0; j--) {
            if (board[i][j] == 1 && i < BOARD_HEIGHT-1) {
                board[i+1][j] = 1;
                board[i][j] = 0;
            }
        }
    }
    spawn_invader(board);
}

int main() {
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int ship_pos = BOARD_WIDTH/2;
    bool game_over = false;

    // Set random seed to current time
    srand(time(NULL));

    // Initialize board and print it
    initialize_board(board);
    print_board(board);

    // Game loop
    while (!game_over) {
        // Move invaders and print board
        move_invaders(board);
        print_board(board);

        // Move player's ship left or right according to input
        int input = getchar();
        if (input == 'a') {
            move_ship(&ship_pos, -1);
        } else if (input == 'd') {
            move_ship(&ship_pos, 1);
        }

        // Check if player's ship was hit by an invader
        if (board[BOARD_HEIGHT-1][ship_pos] == 1) {
            printf("Game over!\n");
            game_over = true;
        }

        // Wait for 100 milliseconds
        usleep(100000);
    }

    return 0;
}