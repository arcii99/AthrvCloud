//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define constants for map sizes and max objects
#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_OBJECTS 10

// Define constants for game elements
#define PLAYER '@'
#define WALL '#'
#define FLOOR '.'
#define ENEMY 'E'
#define TREASURE '$'

// Define struct for game objects
typedef struct {
    char type;
    int x;
    int y;
} Object;

// Define function for printing the game map
void print_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Define function for generating random integers
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Define function for generating the game map
void generate_map(char map[MAP_HEIGHT][MAP_WIDTH], Object objects[MAX_OBJECTS], int *num_objects) {
    // Initialize the map with walls and floors
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                map[i][j] = WALL;
            } else {
                map[i][j] = FLOOR;
            }
        }
    }
    
    // Add random objects to the map
    *num_objects = 0;
    while (*num_objects < MAX_OBJECTS) {
        int x = random_int(1, MAP_WIDTH - 2);
        int y = random_int(1, MAP_HEIGHT - 2);
        char type = FLOOR;
        switch (random_int(1, 4)) {
            case 1:
                type = ENEMY;
                break;
            case 2:
                type = TREASURE;
                break;
            default:
                break;
        }
        if (map[y][x] == FLOOR) {
            objects[*num_objects] = (Object) {type, x, y};
            map[y][x] = type;
            *num_objects += 1;
        }
    }
}

// Define function for moving the player
void move_player(char map[MAP_HEIGHT][MAP_WIDTH], int *player_x, int *player_y, int dx, int dy) {
    int new_x = *player_x + dx;
    int new_y = *player_y + dy;
    if (map[new_y][new_x] == FLOOR || map[new_y][new_x] == ENEMY || map[new_y][new_x] == TREASURE) {
        *player_x = new_x;
        *player_y = new_y;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the game map
    char map[MAP_HEIGHT][MAP_WIDTH];
    Object objects[MAX_OBJECTS];
    int num_objects;
    generate_map(map, objects, &num_objects);
    
    // Initialize the player position
    int player_x = 2;
    int player_y = 2;
    
    // Start the game loop
    bool running = true;
    while (running) {
        // Print the game map
        system("clear");
        print_map(map);
        
        // Move the player based on user input
        printf("Use arrow keys to move, Q to quit\n");
        char input = getchar();
        switch (input) {
            case 'q':
            case 'Q':
                running = false;
                break;
            case 'w':
            case 'W':
                move_player(map, &player_x, &player_y, 0, -1);
                break;
            case 'a':
            case 'A':
                move_player(map, &player_x, &player_y, -1, 0);
                break;
            case 's':
            case 'S':
                move_player(map, &player_x, &player_y, 0, 1);
                break;
            case 'd':
            case 'D':
                move_player(map, &player_x, &player_y, 1, 0);
                break;
            default:
                break;
        }
        
        // Check if the player has encountered an object
        for (int i = 0; i < num_objects; i++) {
            if (objects[i].x == player_x && objects[i].y == player_y) {
                switch (objects[i].type) {
                    case ENEMY:
                        printf("You encountered an enemy!\n");
                        break;
                    case TREASURE:
                        printf("You found some treasure!\n");
                        break;
                    default:
                        break;
                }
                // Remove the object from the map and the objects array
                map[player_y][player_x] = FLOOR;
                for (int j = i; j < num_objects - 1; j++) {
                    objects[j] = objects[j+1];
                }
                num_objects -= 1;
                break;
            }
        }
    }
    
    return 0;
}