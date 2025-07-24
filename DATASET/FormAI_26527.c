//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 10

void print_board(char board[ROWS][COLS], int score);
void move_ship(char board[ROWS][COLS], int move);
void move_invaders(char board[ROWS][COLS], int direction, int *score);
void shoot_bomb(char board[ROWS][COLS], int *game_over);
void check_collision(char board[ROWS][COLS], int *score);
int recursive_game(char board[ROWS][COLS], int score);

int main(void) {
    // Initialize board
    char board[ROWS][COLS] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'I', 'I', 'I', ' ', ' ', ' ', ' '},
        {' ', ' ', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' '}
    };

    // Start game recursively
    int score = recursive_game(board, 0);

    // Game over message and final score
    printf("GAME OVER! Final Score: %d\n", score);

    return 0;
}

int recursive_game(char board[ROWS][COLS], int score) {
    // Display board and current score
    print_board(board, score);

    // Move ship left (0), right (1), or stay (2)
    int move;
    printf("Move ship: 0 (left), 1 (right), 2 (stay): ");
    scanf("%d", &move);
    move_ship(board, move);

    // Randomly move invaders left (-1), right (1), or stay (0)
    srand(time(NULL));
    int direction = rand() % 3 - 1;
    move_invaders(board, direction, &score);

    // Randomly shoot bomb
    shoot_bomb(board, &score);

    // Check for collision between bomb and ship or bomb and invaders
    int game_over = 0;
    check_collision(board, &game_over);

    // If game over, return final score
    if (game_over) {
        return score;
    } else { // Otherwise, continue game recursively
        return recursive_game(board, score);
    }
}

void print_board(char board[ROWS][COLS], int score) {
    // Clear screen
    system("clear");

    // Print score
    printf("Score: %d\n", score);

    // Print board
    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void move_ship(char board[ROWS][COLS], int move) {
    // Find current position of ship and erase
    int curr_row, curr_col;
    for (int row=ROWS-1; row >= 0; row--) {
        for (int col=0; col < COLS; col++) {
            if (board[row][col] == 'S') {
                curr_row = row;
                curr_col = col;
                board[row][col] = ' ';
            }
        }
    }

    // Move ship left or right or stay in current position
    if (move == 0 && curr_col > 0) { // Left
        board[curr_row][curr_col-1] = 'S';
    } else if (move == 1 && curr_col < COLS-1) { // Right
        board[curr_row][curr_col+1] = 'S';
    } else { // Stay
        board[curr_row][curr_col] = 'S';
    }
}

void move_invaders(char board[ROWS][COLS], int direction, int *score) {
    // Find current position of invaders and erase
    int curr_row, curr_col;
    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            if (board[row][col] == 'I') {
                curr_row = row;
                curr_col = col;
                board[row][col] = ' ';
            }
        }
    }

    // Move invaders left or right or stay in current position
    if (direction == -1 && curr_col > 0) { // Left
        board[curr_row][curr_col-1] = 'I';
    } else if (direction == 1 && curr_col < COLS-1) { // Right
        board[curr_row][curr_col+1] = 'I';
    } else { // Stay
        board[curr_row][curr_col] = 'I';
    }

    // Update score if invaders reach bottom row
    if (curr_row == ROWS-1) {
        (*score)++;
    }
}

void shoot_bomb(char board[ROWS][COLS], int *game_over) {
    // Randomly shoot bomb from random invader in second row
    srand(time(NULL));
    int invader_col = rand() % COLS;
    board[1][invader_col] = 'B';

    // Move bomb down rows until it reaches bottom row and erase
    for (int row=1; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            if (board[row][col] == 'B') {
                board[row][col] = ' ';
                if (row == ROWS-1) { // Bomb hit the ship
                    *game_over = 1;
                } else {
                    board[row+1][col] = 'B';
                }
            }
        }
    }
}

void check_collision(char board[ROWS][COLS], int *score) {
    // Check for collision between bomb and ship
    int ship_col;
    for (int row=ROWS-1; row >= 0; row--) {
        for (int col=0; col < COLS; col++) {
            if (board[row][col] == 'S') {
                ship_col = col;
            }
            if (board[row][col] == 'B' && row == ROWS-1 && col == ship_col) {
                *score = -1; // Signal game over
                return;
            }
        }
    }

    // Check for collision between bomb and invaders
    for (int row=0; row < ROWS; row++) {
        for (int col=0; col < COLS; col++) {
            if (board[row][col] == 'B') {
                // Check if bomb hit an invader
                if (row < ROWS-1 && board[row+1][col] == 'I') {
                    board[row][col] = ' ';
                    board[row+1][col] = ' ';
                    (*score)++;
                    return;
                }

                // Check if bomb hit another bomb
                if (row < ROWS-1 && board[row+1][col] == 'B') {
                    board[row][col] = ' ';
                    board[row+1][col] = ' ';
                    return;
                }
            }
        }
    }
}