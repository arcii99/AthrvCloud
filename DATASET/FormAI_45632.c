//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

// Map tiles
typedef enum Tile {
    EMPTY,
    WALL,
    FLOOR
} Tile;

// Player object
typedef struct Player {
    int x;
    int y;
    int health;
    int damage;
} Player;

// Game state
typedef struct State {
    Tile map[WIDTH][HEIGHT];
    Player player;
} State;

// Generate a random integer between min and max (inclusive)
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Initialize the game state
void init_state(State* state) {
    // Initialize the map with empty tiles
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            state->map[x][y] = EMPTY;
        }
    }

    // Generate walls around the edge of the map
    for (int x = 0; x < WIDTH; x++) {
        state->map[x][0] = WALL;
        state->map[x][HEIGHT-1] = WALL;
    }
    for (int y = 0; y < HEIGHT; y++) {
        state->map[0][y] = WALL;
        state->map[WIDTH-1][y] = WALL;
    }

    // Generate floors using a random walk algorithm
    int x = rand_range(1, WIDTH-2);
    int y = rand_range(1, HEIGHT-2);
    int dir_x = rand_range(-1, 1);
    int dir_y = rand_range(-1, 1);
    for (int i = 0; i < WIDTH * HEIGHT / 3; i++) {
        state->map[x][y] = FLOOR;
        x += dir_x;
        y += dir_y;
        if (x < 1 || x > WIDTH-2 || y < 1 || y > HEIGHT-2) {
            // If we hit the edge of the map, turn around
            x -= dir_x;
            y -= dir_y;
            dir_x = rand_range(-1, 1);
            dir_y = rand_range(-1, 1);
        }
    }

    // Place the player in a random location
    state->player.x = rand_range(1, WIDTH-2);
    state->player.y = rand_range(1, HEIGHT-2);
    state->player.health = 100;
    state->player.damage = 10;
}

// Print the game state to the console
void draw_state(State* state) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == state->player.x && y == state->player.y) {
                printf("@");
            } else if (state->map[x][y] == WALL) {
                printf("#");
            } else if (state->map[x][y] == FLOOR) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game state
    State state;
    init_state(&state);

    // Main game loop
    while (1) {
        // Draw the game state
        draw_state(&state);

        // Get player input
        char input = getchar();
        if (input == 'q') {
            break;
        } else if (input == 'h') {
            state.player.x -= 1;
        } else if (input == 'j') {
            state.player.y += 1;
        } else if (input == 'k') {
            state.player.y -= 1;
        } else if (input == 'l') {
            state.player.x += 1;
        }

        // Check for collisions with walls
        if (state.map[state.player.x][state.player.y] == WALL) {
            state.player.x -= (input == 'h') ? -1 : (input == 'l') ? 1 : 0;
            state.player.y -= (input == 'k') ? -1 : (input == 'j') ? 1 : 0;
        }
    }

    return 0;
}