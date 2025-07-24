//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

// Define Pac-Man and Ghost positions
int pacman_row = ROWS/2, pacman_col = COLS/2;
int ghost_row = ROWS/4, ghost_col = COLS/4;

// Define the game board
char board[ROWS][COLS] = {
    "###################",
    "#...........#.....#",
    "#.###.####.#.###.#",
    "#.#.......#.#.....#",
    "#.#####.#.#.#.###.#",
    "#.......#.#.#.....#",
    "#####.#.#.#.#.#####",
    "......#.#.#.#.....#",
    "#####.#.#.#.#.#####",
    "#...........#.....#",
    "#.###.#.#####.#.#.#",
    "#.#...#.......#.#.#",
    "#.#.#########.#.#.#",
    "#.#.............#.#",
    "###################"
};

void print_board() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == pacman_row && j == pacman_col) {
                printf("P");
            } else if (i == ghost_row && j == ghost_col) {
                printf("G");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Game loop
    while (1) {
        print_board();
        
        // Move Pac-Man
        char move;
        printf("Enter a move (w,a,s,d): ");
        scanf(" %c", &move);
        switch (move) {
            case 'w':
                if (board[pacman_row-1][pacman_col] != '#') {
                    pacman_row--;
                }
                break;
            case 'a':
                if (board[pacman_row][pacman_col-1] != '#') {
                    pacman_col--;
                }
                break;
            case 's':
                if (board[pacman_row+1][pacman_col] != '#') {
                    pacman_row++;
                }
                break;
            case 'd':
                if (board[pacman_row][pacman_col+1] != '#') {
                    pacman_col++;
                }
                break;
            default:
                printf("Invalid move!\n");
        }
        
        // Move Ghost
        int ghost_move = rand() % 4; // Generate random number between 0 and 3
        switch (ghost_move) {
            case 0:
                if (board[ghost_row-1][ghost_col] != '#') {
                    ghost_row--;
                }
                break;
            case 1:
                if (board[ghost_row][ghost_col-1] != '#') {
                    ghost_col--;
                }
                break;
            case 2:
                if (board[ghost_row+1][ghost_col] != '#') {
                    ghost_row++;
                }
                break;
            case 3:
                if (board[ghost_row][ghost_col+1] != '#') {
                    ghost_col++;
                }
                break;
        }
        
        // Check for win or loss
        if (pacman_row == ghost_row && pacman_col == ghost_col) {
            printf("Game over! Ghost caught Pac-Man.\n");
            break;
        } else if (board[pacman_row][pacman_col] == '.') {
            board[pacman_row][pacman_col] = ' '; // Remove pellet
        }
        
        // Check for victory
        int pellets_remaining = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == '.') {
                    pellets_remaining++;
                }
            }
        }
        if (pellets_remaining == 0) {
            printf("You win! All pellets have been eaten.\n");
            break;
        }
    }
    
    return 0;
}