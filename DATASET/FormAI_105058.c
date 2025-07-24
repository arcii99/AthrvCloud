//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our custom types
typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    EMPTY,
    PLAYER,
    MONSTER
} Tile;

// Define the grid size
#define GRID_SIZE 10

// Define the maximum number of monsters
#define MAX_MONSTERS 5

// Function to generate a random position on the grid
Position generate_random_position() {
    Position pos;
    pos.x = rand() % GRID_SIZE;
    pos.y = rand() % GRID_SIZE;
    return pos;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize the grid with empty tiles
    Tile grid[GRID_SIZE][GRID_SIZE];
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            grid[x][y] = EMPTY;
        }
    }
    
    // Place the player at a random position
    Position player_pos = generate_random_position();
    grid[player_pos.x][player_pos.y] = PLAYER;
    printf("Player spawned at (%d, %d)\n", player_pos.x, player_pos.y);
    
    // Spawn monsters at random positions
    for (int i = 0; i < MAX_MONSTERS; i++) {
        Position monster_pos = generate_random_position();
        while (grid[monster_pos.x][monster_pos.y] != EMPTY) {
            monster_pos = generate_random_position();
        }
        grid[monster_pos.x][monster_pos.y] = MONSTER;
        printf("Monster %d spawned at (%d, %d)\n", i+1, monster_pos.x, monster_pos.y);
    }
    
    // Game loop
    while (1) {
        // Print the grid
        printf("Current state:\n");
        for (int x = 0; x < GRID_SIZE; x++) {
            for (int y = 0; y < GRID_SIZE; y++) {
                switch (grid[x][y]) {
                    case EMPTY:
                        printf(".");
                        break;
                    case PLAYER:
                        printf("@");
                        break;
                    case MONSTER:
                        printf("M");
                        break;
                }
            }
            printf("\n");
        }
        
        // Ask the player to move
        char input;
        printf("Enter movement (W/A/S/D): ");
        fflush(stdout);
        scanf(" %c", &input);
        
        // Update player position
        grid[player_pos.x][player_pos.y] = EMPTY;
        switch (input) {
            case 'W':
                if (player_pos.y > 0) {
                    player_pos.y--;
                }
                break;
            case 'A':
                if (player_pos.x > 0) {
                    player_pos.x--;
                }
                break;
            case 'S':
                if (player_pos.y < GRID_SIZE-1) {
                    player_pos.y++;
                }
                break;
            case 'D':
                if (player_pos.x < GRID_SIZE-1) {
                    player_pos.x++;
                }
                break;
            default:
                printf("Invalid input!\n");
                continue;
        }
        grid[player_pos.x][player_pos.y] = PLAYER;
        
        // Check if the player collided with a monster
        if (grid[player_pos.x][player_pos.y] == MONSTER) {
            printf("You lose!\n");
            break;
        }
        
        // Check if there are no more monsters
        int has_monsters = 0;
        for (int x = 0; x < GRID_SIZE; x++) {
            for (int y = 0; y < GRID_SIZE; y++) {
                if (grid[x][y] == MONSTER) {
                    has_monsters = 1;
                    break;
                }
            }
            if (has_monsters) {
                break;
            }
        }
        if (!has_monsters) {
            printf("You win!\n");
            break;
        }
    }
    
    return 0;
}