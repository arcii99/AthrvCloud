//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 20
#define WALL_CHAR '#'
#define DOT_CHAR '.'
#define EMPTY_CHAR ' '
#define PACMAN_CHAR 'P'

int board[BOARD_SIZE][BOARD_SIZE];
int pac_x, pac_y;
int score = 0;

void initialize_board() {
    // Set up the walls
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][0] = WALL_CHAR;
        board[0][i] = WALL_CHAR;
        board[i][BOARD_SIZE-1] = WALL_CHAR;
        board[BOARD_SIZE-1][i] = WALL_CHAR;
    }
    // Fill the rest of the board with dots 
    for (int i = 1; i < BOARD_SIZE-1; i++) {
        for (int j = 1; j < BOARD_SIZE-1; j++) {
            board[i][j] = DOT_CHAR;
        }
    }
    // Place Pac-Man in the center
    pac_x = BOARD_SIZE/2;
    pac_y = BOARD_SIZE/2;
    board[pac_x][pac_y] = PACMAN_CHAR;
}

void display_board() {
    printf("Score: %d\n", score);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_pacman(int dx, int dy) {
    int new_x = pac_x + dx;
    int new_y = pac_y + dy;
    char new_cell = board[new_x][new_y];
    if (new_cell == WALL_CHAR) {
        // Pac-Man cannot move through walls
        return;
    }
    if (new_cell == DOT_CHAR) {
        // Pac-Man eats the dot and gains a point
        score++;
    }
    // Update the board and Pac-Man's position 
    board[pac_x][pac_y] = EMPTY_CHAR;
    pac_x = new_x;
    pac_y = new_y;
    board[pac_x][pac_y] = PACMAN_CHAR;
}

int main() {
    initialize_board();
    while (true) {
        display_board();
        // Wait for user input
        char input = getchar();
        // Move Pac-Man accordingly
        switch (input) {
            case 'w': move_pacman(-1, 0); break;
            case 'a': move_pacman(0, -1); break;
            case 's': move_pacman(1, 0); break;
            case 'd': move_pacman(0, 1); break;
            default: break;
        }
        // Clear the console and print the updated board
        system("clear");
    }
}