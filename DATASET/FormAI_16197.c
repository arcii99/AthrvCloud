//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 15
#define COLS 20
#define EMPTY ' '
#define DOT '.'
#define WALL '*'
#define PACMAN 'P'
#define GHOST 'G'
#define SPEED 250 // in milliseconds

// Define global variables
char grid[ROWS][COLS];
int pacman_row, pacman_col, score;

// Define function prototypes
void initialize_grid();
void print_grid();
int get_random(int min, int max);
int move_ghosts();
int move_pacman(int d_row, int d_col);
void add_dot();
void play_game();

// Define the main function
int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Initialize the grid
    initialize_grid();
    
    // Add the dots to the grid
    add_dot();
    
    // Play the game
    play_game();
    
    return 0;
}

// Define the function that initializes the grid
void initialize_grid() {
    int i, j;
    
    // Set all the cells to EMPTY
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = EMPTY;
        }
    }
    
    // Add the walls to the grid
    for(i = 0; i < ROWS; i++) {
        grid[i][0] = WALL;
        grid[i][COLS - 1] = WALL;
    }
    for(j = 0; j < COLS; j++) {
        grid[0][j] = WALL;
        grid[ROWS - 1][j] = WALL;
    }
    
    // Add the Pac-Man and the ghosts to the grid
    pacman_row = get_random(1, ROWS - 2);
    pacman_col = get_random(1, COLS - 2);
    grid[pacman_row][pacman_col] = PACMAN;
    for(i = 0; i < 4; i++) {
        int ghost_row = get_random(1, ROWS - 2);
        int ghost_col = get_random(1, COLS - 2);
        while(grid[ghost_row][ghost_col] != EMPTY) {
            ghost_row = get_random(1, ROWS - 2);
            ghost_col = get_random(1, COLS - 2);
        }
        grid[ghost_row][ghost_col] = GHOST;
    }
    
    // Initialize the score
    score = 0;
}

// Define the function that prints the grid
void print_grid() {
    int i, j;
    
    // Clear the console
    system("clear");
    
    // Print the grid
    for(i = 0; i < ROWS; i++) {
        printf("|");
        for(j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("|\n");
    }
    
    // Print the score
    printf("Score: %d\n", score);
}

// Define the function that generates a random number between min and max (inclusive)
int get_random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Define the function that moves the ghosts
int move_ghosts() {
    int i, j;
    
    for(i = 1; i < ROWS - 1; i++) {
        for(j = 1; j < COLS - 1; j++) {
            if(grid[i][j] == GHOST) {
                int d_row = get_random(-1, 1);
                int d_col = get_random(-1, 1);
                while(d_row == 0 && d_col == 0) {
                    d_row = get_random(-1, 1);
                    d_col = get_random(-1, 1);
                }
                if(grid[i + d_row][j + d_col] == EMPTY) {
                    grid[i][j] = EMPTY;
                    grid[i + d_row][j + d_col] = GHOST;
                }
                else if(grid[i + d_row][j + d_col] == PACMAN) {
                    grid[i][j] = EMPTY;
                    return -1;
                }
            }
        }
    }
    
    return 0;
}

// Define the function that moves the Pac-Man in the direction given by d_row and d_col
int move_pacman(int d_row, int d_col) {
    if(grid[pacman_row + d_row][pacman_col + d_col] == EMPTY) {
        grid[pacman_row][pacman_col] = EMPTY;
        pacman_row += d_row;
        pacman_col += d_col;
        grid[pacman_row][pacman_col] = PACMAN;
        return 0;
    }
    else if(grid[pacman_row + d_row][pacman_col + d_col] == DOT) {
        grid[pacman_row][pacman_col] = EMPTY;
        pacman_row += d_row;
        pacman_col += d_col;
        grid[pacman_row][pacman_col] = PACMAN;
        score++;
        return 1;
    }
    else if(grid[pacman_row + d_row][pacman_col + d_col] == GHOST) {
        return -1;
    }
    else {
        return 0;
    }
}

// Define the function that adds the dots to the grid
void add_dot() {
    int i, j;
    
    for(i = 1; i < ROWS - 1; i++) {
        for(j = 1; j < COLS - 1; j++) {
            if(grid[i][j] == EMPTY && get_random(0, 1) == 1) {
                grid[i][j] = DOT;
            }
        }
    }
}

// Define the function that plays the game
void play_game() {
    int d_row = 0, d_col = 0;
    
    // Print the initial state of the grid
    print_grid();
    
    // Loop until the game is over
    while(1) {
        // Wait for input
        switch(getchar()) {
            case 'w':
                d_row = -1;
                d_col = 0;
                break;
            case 'a':
                d_row = 0;
                d_col = -1;
                break;
            case 's':
                d_row = 1;
                d_col = 0;
                break;
            case 'd':
                d_row = 0;
                d_col = 1;
                break;
            default:
                d_row = 0;
                d_col = 0;
                break;
        }
        
        // Move the Pac-Man
        int result = move_pacman(d_row, d_col);
        if(result == -1) {
            printf("Game over! You were caught!\n");
            break;
        }
        
        // Move the ghosts
        result = move_ghosts();
        if(result == -1) {
            printf("Game over! You caught all the ghosts!\n");
            break;
        }
        
        // Add new dots to the grid
        add_dot();
        
        // Print the current state of the grid
        print_grid();
        
        // Wait for a short time
        usleep(SPEED * 1000);
    }
}