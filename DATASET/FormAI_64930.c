//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configuration for game
#define GRID_SIZE 4         // size of grid (4x4)
#define TARGET 2048         // target number to win the game
#define MAX_MOVES 100       // maximum number of moves allowed

// Display characters for different tiles
#define EMPTY ' '
#define H_BORDER '|'
#define V_BORDER '-'

// Grid properties
int grid[GRID_SIZE][GRID_SIZE];
int score = 0;
int moves = 0;

// Initialize grid with empty tiles
void init_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Print the grid
void print_grid() {
    printf("+");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("|");
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("   |");
            } else {
                printf(" %3d|", grid[i][j]);
            }
        }
        printf("\n+");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Get a random empty tile in the grid
void get_random_empty_tile(int *x, int *y) {
    int empty_tiles = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                empty_tiles++;
            }
        }
    }
    if (empty_tiles == 0) {
        *x = -1;
        *y = -1;
    } else {
        int choice = rand() % empty_tiles + 1;
        empty_tiles = 0;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] == 0) {
                    empty_tiles++;
                    if (empty_tiles == choice) {
                        *x = i;
                        *y = j;
                        return;
                    }
                }
            }
        }
    }
}

// Add a new tile to the grid
void add_new_tile() {
    int x, y;
    get_random_empty_tile(&x, &y);
    if (x != -1 && y != -1) {
        if (rand() % 100 < 90) {
            grid[x][y] = 2;
        } else {
            grid[x][y] = 4;
        }
    }
}

// Combine tiles to form new number
void combine_tiles(int x1, int y1, int x2, int y2) {
    grid[x1][y1] = grid[x1][y1] + grid[x2][y2];
    score += grid[x1][y1];
    grid[x2][y2] = 0;
}

// Move tiles left towards empty tiles
void move_tiles_left() {
    for (int i = 0; i < GRID_SIZE; i++) {
        int last_num = 0;
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                if (last_num == 0) {
                    last_num = grid[i][j];
                } else {
                    if (last_num == grid[i][j]) {
                        combine_tiles(i, j, i, j - 1);
                        last_num = 0;
                    } else {
                        last_num = grid[i][j];
                        if (j != 0) {
                            grid[i][j - 1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

// Move tiles right towards empty tiles
void move_tiles_right() {
    for (int i = 0; i < GRID_SIZE; i++) {
        int last_num = 0;
        for (int j = GRID_SIZE - 1; j >= 0; j--) {
            if (grid[i][j] != 0) {
                if (last_num == 0) {
                    last_num = grid[i][j];
                } else {
                    if (last_num == grid[i][j]) {
                        combine_tiles(i, j, i, j + 1);
                        last_num = 0;
                    } else {
                        last_num = grid[i][j];
                        if (j != GRID_SIZE - 1) {
                            grid[i][j + 1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

// Move tiles up towards empty tiles
void move_tiles_up() {
    for (int j = 0; j < GRID_SIZE; j++) {
        int last_num = 0;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (grid[i][j] != 0) {
                if (last_num == 0) {
                    last_num = grid[i][j];
                } else {
                    if (last_num == grid[i][j]) {
                        combine_tiles(i, j, i - 1, j);
                        last_num = 0;
                    } else {
                        last_num = grid[i][j];
                        if (i != 0) {
                            grid[i - 1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

// Move tiles down towards empty tiles
void move_tiles_down() {
    for (int j = 0; j < GRID_SIZE; j++) {
        int last_num = 0;
        for (int i = GRID_SIZE - 1; i >= 0; i--) {
            if (grid[i][j] != 0) {
                if (last_num == 0) {
                    last_num = grid[i][j];
                } else {
                    if (last_num == grid[i][j]) {
                        combine_tiles(i, j, i + 1, j);
                        last_num = 0;
                    } else {
                        last_num = grid[i][j];
                        if (i != GRID_SIZE - 1) {
                            grid[i + 1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

// Check if the game is won
int check_win() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == TARGET) {
                return 1;
            }
        }
    }
    return 0;
}

// Check if the game is lost
int check_loss() {
    if (moves >= MAX_MOVES) {
        return 1;
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
            if (i != GRID_SIZE - 1 && grid[i][j] == grid[i + 1][j]) {
                return 0;
            }
            if (j != GRID_SIZE - 1 && grid[i][j] == grid[i][j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int choice;
    srand(time(NULL));
    init_grid();

    while (1) {
        printf("Score: %d\n", score);
        printf("Moves: %d/%d\n", moves, MAX_MOVES);
        print_grid();

        printf("Enter direction (1: Left, 2: Right, 3: Up, 4: Down): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_tiles_left();
                break;
            case 2:
                move_tiles_right();
                break;
            case 3:
                move_tiles_up();
                break;
            case 4:
                move_tiles_down();
                break;
            default:
                printf("Invalid direction.\n");
                continue;
        }

        add_new_tile();
        moves++;

        if (check_win()) {
            print_grid();
            printf("You won! Congratulations :)\n");
            break;
        }

        if (check_loss()) {
            print_grid();
            printf("You lost! Better luck next time :(\n");
            break;
        }
    }

    return 0;
}