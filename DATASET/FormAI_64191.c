//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10    // Size of the grid
#define MAX_MOVES 50    // Maximum number of moves allowed
#define SEED time(NULL) // Seed for the random number generator

// Structure for a position in the grid
typedef struct {
    int x;
    int y;
} Position;

// Function declarations
void print_grid(int grid[][GRID_SIZE]);
Position move(Position current, int direction);
int is_valid_move(Position current, int direction);
int get_random_direction(void);

int main(void) {
    // Seed the random number generator
    srand(SEED);

    // Initialize the grid
    int grid[GRID_SIZE][GRID_SIZE] = {0};

    // Initialize the player's starting position
    Position player = {GRID_SIZE / 2, GRID_SIZE / 2};

    // Print the starting grid and position
    print_grid(grid);
    printf("Player position: (%d, %d)\n", player.x, player.y);

    // Start the game loop
    for (int moves = 0; moves < MAX_MOVES; moves++) {
        // Get a random direction to move in
        int direction = get_random_direction();

        // Move the player
        if (is_valid_move(player, direction)) {
            player = move(player, direction);
        }

        // Print the updated grid and position
        print_grid(grid);
        printf("Player position: (%d, %d)\n", player.x, player.y);
    }

    printf("Game over.\n");

    return 0;
}

/**
 * Prints the grid to stdout.
 * @param grid the grid to print
 */
void print_grid(int grid[][GRID_SIZE]) {
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Moves the player one step in the specified direction.
 * @param current the player's current position
 * @param direction the direction to move in
 * @return the player's new position after the move
 */
Position move(Position current, int direction) {
    switch (direction) {
    case 0: // Up
        current.y--;
        break;
    case 1: // Down
        current.y++;
        break;
    case 2: // Left
        current.x--;
        break;
    case 3: // Right
        current.x++;
        break;
    default: // Should never happen
        exit(1);
    }
    return current;
}

/**
 * Determines whether the specified move is valid or not.
 * @param current the player's current position
 * @param direction the direction to move in
 * @return 1 if the move is valid, 0 otherwise
 */
int is_valid_move(Position current, int direction) {
    switch (direction) {
    case 0: // Up
        return current.y > 0;
    case 1: // Down
        return current.y < GRID_SIZE - 1;
    case 2: // Left
        return current.x > 0;
    case 3: // Right
        return current.x < GRID_SIZE - 1;
    default: // Should never happen
        return 0;
    }
}

/**
 * Returns a random direction to move in.
 * @return a random direction (0 = up, 1 = down, 2 = left, 3 = right)
 */
int get_random_direction(void) {
    return rand() % 4;
}