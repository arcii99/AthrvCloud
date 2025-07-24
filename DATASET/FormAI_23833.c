//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: real-life
#include <stdio.h>

// Define constants
#define ROWS 20
#define COLS 30
#define NUM_PELLETS 100
#define GHOSTS 4

// Define global variables
int pellets_left = NUM_PELLETS; // keep track of number of pellets left
int pacman_lives = 3; // number of lives pacman has left

// Initialize the game board
int board[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1},
    {1,2,1,1,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1},
    {1,5,1,0,1,2,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,1,5,1},
    {1,2,1,1,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1},
    {1,2,2,2,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,2,2,2,2,1},
    {1,1,1,1,1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,1,1,1,2,1,1,1},
    {0,0,0,0,1,2,1,2,1,2,1,1,1,3,1,1,1,1,3,1,1,2,1,0,0,0,2,1,0,0},
    {1,1,1,1,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,1,1,1,2,1,1,1},
    {0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,2,1,0,0},
    {1,1,1,1,1,2,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,1},
    {0,0,0,0,1,2,1,2,1,1,1,3,1,0,0,0,3,1,0,0,1,2,1,0,0,0,2,1,0,0},
    {1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1},
    {1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1},
    {1,5,2,2,2,2,1,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,2,2,2,5,1},
    {1,1,1,1,1,2,1,2,1,2,2,2,2,0,2,2,2,2,0,2,1,2,1,1,1,1,2,1,1,1},
    {0,0,0,0,1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0,0,0,2,1,0,0},
    {1,1,1,1,1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,1,1,1,2,1,1,1},
    {0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,2,1,0,0},
    {1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1},
};

// Define a struct for the ghosts
struct ghost {
    int row;
    int col;
    int direction;
};

// Define function to move pacman
void move_pacman(int *row, int *col, char direction) {
    switch (direction) {
        case 'w':
            if (*row > 0 && board[*row-1][*col] != 1) {
                *row -= 1;
            }
            break;
        case 'a':
            if (*col > 0 && board[*row][*col-1] != 1) {
                *col -= 1;
            }
            break;
        case 's':
            if (*row < ROWS-1 && board[*row+1][*col] != 1) {
                *row += 1;
            }
            break;
        case 'd':
            if (*col < COLS-1 && board[*row][*col+1] != 1) {
                *col += 1;
            }
            break;
    }
    // check if pacman collided with a pellet
    if (board[*row][*col] == 2) {
        board[*row][*col] = 0; // remove pellet from board
        pellets_left -= 1; // subtract from pellets_left count
    }
}

// Define function to move a ghost
void move_ghost(struct ghost *g) {
    int row = g->row;
    int col = g->col;
    int dir = g->direction;
    // check if ghost can move in current direction
    int valid_move = 0;
    switch (dir) {
        case 0:
            if (row > 0 && board[row-1][col] != 1) {
                row -= 1;
                valid_move = 1;
            }
            break;
        case 1:
            if (col > 0 && board[row][col-1] != 1) {
                col -= 1;
                valid_move = 1;
            }
            break;
        case 2:
            if (row < ROWS-1 && board[row+1][col] != 1) {
                row += 1;
                valid_move = 1;
            }
            break;
        case 3:
            if (col < COLS-1 && board[row][col+1] != 1) {
                col += 1;
                valid_move = 1;
            }
            break;
    }
    // if move is invalid, choose a new direction at random
    if (!valid_move) {
        do {
            dir = rand() % 4;
        } while ((dir == 0 && row == 0) || (dir == 1 && col == 0) || (dir == 2 && row == ROWS-1) || (dir == 3 && col == COLS-1) || board[row][col] == 1);
    }
    // update ghost's position and direction
    g->row = row;
    g->col = col;
    g->direction = dir;
}

// Define function to print the game board
void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("#");
                    break;
                case 2:
                    printf(".");
                    break;
                case 3:
                    printf("O");
                    break;
                case 4:
                    printf("M");
                    break;
                case 5:
                    printf("P");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    // Define initial positions of pacman and ghosts
    int pacman_row = 3;
    int pacman_col = 1;
    struct ghost ghosts[GHOSTS] = {
        {8, 8, 0},
        {8, 9, 3},
        {9, 8, 2},
        {9, 9, 3}
    };
    // Main game loop
    while (1) {
        // Clear the screen and print the board
        system("clear");
        print_board();
        // Get user input and move pacman
        char c;
        printf("Pellets left: %d\n", pellets_left);
        printf("Lives left: %d\n", pacman_lives);
        printf("Use WASD to move: ");
        scanf(" %c", &c);
        move_pacman(&pacman_row, &pacman_col, c);
        // Move ghosts
        for (int i = 0; i < GHOSTS; i++) {
            move_ghost(&ghosts[i]);
            // check if pacman collided with a ghost
            if (pacman_row == ghosts[i].row && pacman_col == ghosts[i].col) {
                pacman_lives -= 1; // subtract from lives_left count
                if (pacman_lives == 0) {
                    printf("Game over!\n");
                    return 0;
                }
                // reset positions of pacman and ghosts
                pacman_row = 3;
                pacman_col = 1;
                for (int j = 0; j < GHOSTS; j++) {
                    ghosts[j].row = 8;
                    ghosts[j].col = 8+j;
                    ghosts[j].direction = 0;
                }
            }
        }
        // check if all pellets have been collected
        if (pellets_left == 0) {
            printf("You win!\n");
            return 0;
        }
    }
    return 0;
}