//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30  // Change this to adjust the size of the map
#define WALL_CHAR '#'  // The character used to represent walls
#define FLOOR_CHAR '.'  // The character used to represent floors

// This struct represents a single cell in the grid
typedef struct {
    char type;
    int visited;
} Cell;

// This function randomly generates the map
void generate_map(Cell map[MAP_SIZE][MAP_SIZE]) {
    int i, j;

    // Set all cells as walls to start
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j].type = WALL_CHAR;
            map[i][j].visited = 0;
        }
    }

    // Choose a random starting cell
    int start_x = rand() % MAP_SIZE;
    int start_y = rand() % MAP_SIZE;

    // Mark the starting cell as visited and a floor cell
    map[start_x][start_y].type = FLOOR_CHAR;
    map[start_x][start_y].visited = 1;

    // This loop will randomly generate the rest of the map
    while (1) {
        // Pick a random cell
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;

        // If the cell has already been visited, skip it
        if (map[x][y].visited) {
            continue;
        }

        // Choose a random adjacent cell
        int adjacent_x, adjacent_y;
        do {
            int direction = rand() % 4;
            switch (direction) {
                case 0:
                    adjacent_x = x + 1;
                    adjacent_y = y;
                    break;
                case 1:
                    adjacent_x = x - 1;
                    adjacent_y = y;
                    break;
                case 2:
                    adjacent_x = x;
                    adjacent_y = y + 1;
                    break;
                case 3:
                    adjacent_x = x;
                    adjacent_y = y - 1;
                    break;
            }
        } while (adjacent_x < 0 || adjacent_x >= MAP_SIZE || adjacent_y < 0 || adjacent_y >= MAP_SIZE || !map[adjacent_x][adjacent_y].visited);

        // Create a hallway between the two cells
        int hallway_x = (x + adjacent_x) / 2;
        int hallway_y = (y + adjacent_y) / 2;
        map[hallway_x][hallway_y].type = FLOOR_CHAR;

        // Mark the current cell as visited and a floor cell
        map[x][y].type = FLOOR_CHAR;
        map[x][y].visited = 1;

        // If there are no more unvisited cells, break out of the loop
        for (i = 0; i < MAP_SIZE; i++) {
            for (j = 0; j < MAP_SIZE; j++) {
                if (!map[i][j].visited) {
                    break;
                }
            }
            if (!map[i][j].visited) {
                break;
            }
        }
        if (!map[i][j].visited) {
            continue;
        } else {
            break;
        }
    }
}

// This function prints the map
void print_map(Cell map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j].type);
        }
        printf("\n");
    }
}

// The main function simply calls generate_map and print_map
int main() {
    Cell map[MAP_SIZE][MAP_SIZE];
    srand(time(NULL));
    generate_map(map);
    print_map(map);
    return 0;
}