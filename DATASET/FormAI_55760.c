//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Function prototypes
void initializeMap(char map[][COLS]);
void displayMap(char map[][COLS]);
void placePacman(char map[][COLS], int row, int col);
void placeGhosts(char map[][COLS], int num_ghosts);
int movePacman(char map[][COLS], int* row, int* col, int direction);
int moveGhost(char map[][COLS], int* row, int* col);
bool checkCollision(int row1, int col1, int row2, int col2);

int main() {
    char map[ROWS][COLS];
    int num_ghosts = 3;
    int pacman_row = ROWS/2;
    int pacman_col = COLS/2;
    int direction;

    srand(time(NULL));  // Set seed for random number generator

    initializeMap(map);
    placePacman(map, pacman_row, pacman_col);
    placeGhosts(map, num_ghosts);
    displayMap(map);

    while (true) {
        printf("Use arrow keys to move Pac-Man.\n");
        direction = getchar();
        getchar();  // Capture newline character
        if (direction == 27) {  // Escape key
            printf("Goodbye!\n");
            break;
        }
        if (direction == 65)
            movePacman(map, &pacman_row, &pacman_col, 0);  // Up
        else if (direction == 66)
            movePacman(map, &pacman_row, &pacman_col, 1);  // Down
        else if (direction == 67)
            movePacman(map, &pacman_row, &pacman_col, 2);  // Right
        else if (direction == 68)
            movePacman(map, &pacman_row, &pacman_col, 3);  // Left
        else
            printf("Invalid input.\n");

        for (int i = 0; i < num_ghosts; i++)
            moveGhost(map, &pacman_row, &pacman_col);
        displayMap(map);
    }

    return 0;
}

// Initialize map with walls and empty spaces
void initializeMap(char map[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((j == 0) || (j == COLS-1) || (i == 0) || (i == ROWS-1))
                map[i][j] = '|';  // Border wall
            else
                map[i][j] = ' ';  // Empty space
        }
    }
}

// Print map to screen
void displayMap(char map[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Place Pac-Man on the map at given position
void placePacman(char map[][COLS], int row, int col) {
    map[row][col] = 'C';
}

// Place n ghosts on the map in random positions
void placeGhosts(char map[][COLS], int num_ghosts) {
    int ghost_row, ghost_col;
    for (int i = 0; i < num_ghosts; i++) {
        do {
            ghost_row = rand()%ROWS;
            ghost_col = rand()%COLS;
        } while (map[ghost_row][ghost_col] != ' ');  // Don't place on top of other object
        map[ghost_row][ghost_col] = 'O';
    }
}

// Move Pac-Man and check for collision with ghosts
// Return 0 if Pac-Man is caught, 1 otherwise
int movePacman(char map[][COLS], int* row, int* col, int direction) {
    int new_row = *row;
    int new_col = *col;

    if (direction == 0)
        new_row--;
    else if (direction == 1)
        new_row++;
    else if (direction == 2)
        new_col++;
    else if (direction == 3)
        new_col--;

    // Check if new position is a wall
    if (map[new_row][new_col] == '|')
        return 1;

    // Check for collision with ghosts
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'O') {
                if (checkCollision(new_row, new_col, i, j))
                    return 0;
            }
        }
    }

    // Update Pac-Man position
    map[*row][*col] = ' ';
    *row = new_row;
    *col = new_col;
    map[*row][*col] = 'C';

    return 1;
}

// Move a ghost in random direction
// Return 0 if ghost catches Pac-Man, 1 otherwise
int moveGhost(char map[][COLS], int* row, int* col) {
    int ghost_row = *row;
    int ghost_col = *col;

    // Look for a ghost on the map
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'O') {
                ghost_row = i;
                ghost_col = j;
                break;
            }
        }
    }
    // Move ghost in random direction
    switch (rand() % 4) {
        case 0:
            ghost_row--;
            break;
        case 1:
            ghost_row++;
            break;
        case 2:
            ghost_col++;
            break;
        case 3:
            ghost_col--;
            break;
    }
    // Check if new position is a wall
    if (map[ghost_row][ghost_col] == '|')
        return 1;

    // Check for collision with Pac-Man
    if (checkCollision(ghost_row, ghost_col, *row, *col))
        return 0;

    // Update ghost position
    map[*row][*col] = ' ';
    *row = ghost_row;
    *col = ghost_col;
    map[*row][*col] = 'O';

    return 1;
}

// Check if two positions are the same
bool checkCollision(int row1, int col1, int row2, int col2) {
    if ((row1 == row2) && (col1 == col2))
        return true;
    return false;
}