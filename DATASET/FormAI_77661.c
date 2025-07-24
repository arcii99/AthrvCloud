//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for map size and feature generation
#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define NUM_ROOMS 10
#define ROOM_MIN_WIDTH 4
#define ROOM_MAX_WIDTH 10
#define ROOM_MIN_HEIGHT 4
#define ROOM_MAX_HEIGHT 7

// Define constants for map features
#define SPACE ' '
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

// Define structure for player character
typedef struct {
    int x;
    int y;
} Player;

// Define 2D array for map
char map[MAP_WIDTH][MAP_HEIGHT];

// Function to initialize map with spaces
void initMap() {
    for(int x=0; x<MAP_WIDTH; x++) {
        for(int y=0; y<MAP_HEIGHT; y++) {
            map[x][y] = SPACE;
        }
    }
}

// Function to generate rectangular room
void generateRoom(int x, int y, int width, int height) {
    for(int i=x; i<x+width; i++) {
        for(int j=y; j<y+height; j++) {
            if(i == x || i == x+width-1 || j == y || j == y+height-1) {
                map[i][j] = WALL;
            } else {
                map[i][j] = FLOOR;
            }
        }
    }
}

// Function to generate map with rooms
void generateMap() {
    // Seed random number generator
    srand(time(NULL));

    // Generate rooms
    for(int i=0; i<NUM_ROOMS; i++) {
        int x = rand() % (MAP_WIDTH-ROOM_MAX_WIDTH-1) + 1;
        int y = rand() % (MAP_HEIGHT-ROOM_MAX_HEIGHT-1) + 1;
        int width = rand() % (ROOM_MAX_WIDTH-ROOM_MIN_WIDTH+1) + ROOM_MIN_WIDTH;
        int height = rand() % (ROOM_MAX_HEIGHT-ROOM_MIN_HEIGHT+1) + ROOM_MIN_HEIGHT;
        generateRoom(x, y, width, height);
    }
}

// Function to print map to console
void printMap(Player player) {
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {
            if(x == player.x && y == player.y) {
                printf("%c", PLAYER);
            } else {
                printf("%c", map[x][y]);
            }
        }
        printf("\n");
    }
}

// Main function to run game loop
int main() {
    // Initialize map and generate features
    initMap();
    generateMap();

    // Initialize player character
    Player player;
    player.x = MAP_WIDTH/2;
    player.y = MAP_HEIGHT/2;

    // Print initial map
    printMap(player);

    // Game loop
    char input;
    while(1) {
        // Read input from user
        scanf(" %c", &input);

        // Move player character
        switch(input) {
            case 'w':
                if(player.y-1 >= 0 && map[player.x][player.y-1] != WALL) {
                    player.y--;
                }
                break;
            case 'a':
                if(player.x-1 >= 0 && map[player.x-1][player.y] != WALL) {
                    player.x--;
                }
                break;
            case 's':
                if(player.y+1 < MAP_HEIGHT && map[player.x][player.y+1] != WALL) {
                    player.y++;
                }
                break;
            case 'd':
                if(player.x+1 < MAP_WIDTH && map[player.x+1][player.y] != WALL) {
                    player.x++;
                }
                break;
            case 'q':
                printf("Exiting game...\n");
                return 0;
        }

        // Print updated map
        system("clear"); // Clear console before printing new map
        printMap(player);
    }
}