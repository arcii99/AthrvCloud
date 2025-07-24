//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the map dimensions and starting location
#define MAP_ROWS 10
#define MAP_COLS 10
#define START_ROW 5
#define START_COL 5

// Define structs for the map and the current location
typedef struct {
    int map[MAP_ROWS][MAP_COLS];
} Map;

typedef struct {
    int row;
    int col;
} Location;

// Define function prototypes
void initializeMap(Map *map);
void printMap(Map *map, Location *location);
void navigate(Map *map, Location *location);

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the map and starting location
    Map map;
    initializeMap(&map);
    Location location = {START_ROW, START_COL};

    // Print the initial map and location
    printf("Starting location: row %d, col %d\n\n", location.row, location.col);
    printMap(&map, &location);

    // Start the navigation loop
    navigate(&map, &location);

    // Print a message to indicate the end of the program
    printf("End of program\n");

    return 0;
}

// Initialize the map with random values
void initializeMap(Map *map) {
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLS; col++) {
            map->map[row][col] = rand() % 2;
        }
    }
}

// Print the map with the current location
void printMap(Map *map, Location *location) {
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLS; col++) {
            if (row == location->row && col == location->col) {
                printf("O");
            } else if (map->map[row][col] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Navigate through the map until the exit is found
void navigate(Map *map, Location *location) {
    while (1) {
        // Check if the current location is at the edge of the map
        if (location->row == 0 || location->row == MAP_ROWS - 1 ||
            location->col == 0 || location->col == MAP_COLS - 1) {
            printf("Exit found at row %d, col %d\n", location->row, location->col);
            break;
        }

        // Check the adjacent cells and choose a direction to move in
        int moveDir = rand() % 4;
        switch (moveDir) {
            case 0:
                if (map->map[location->row - 1][location->col] == 0) {
                    location->row--;
                }
                break;
            case 1:
                if (map->map[location->row][location->col + 1] == 0) {
                    location->col++;
                }
                break;
            case 2:
                if (map->map[location->row + 1][location->col] == 0) {
                    location->row++;
                }
                break;
            case 3:
                if (map->map[location->row][location->col - 1] == 0) {
                    location->col--;
                }
                break;
        }

        // Print the new map and location
        printMap(map, location);
    }
}