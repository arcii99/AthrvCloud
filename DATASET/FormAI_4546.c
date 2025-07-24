//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef enum {EMPTY, WALL, FLOOR} MapTiles;

MapTiles map[MAP_HEIGHT][MAP_WIDTH];
int visited[MAP_HEIGHT][MAP_WIDTH];

// Function used to randomize values
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_map() {
    // Set all tiles to walls
    for (int i=0; i<MAP_HEIGHT; i++) {
        for (int j=0; j<MAP_WIDTH; j++) {
            map[i][j] = WALL;
        }
    }
    
    // Randomize starting position
    int x = rand_range(1, MAP_WIDTH-2);
    int y = rand_range(1, MAP_HEIGHT-2);
    
    // Set starting position as floor
    map[y][x] = FLOOR;
    visited[y][x] = 1;
    
    // Recursive depth-first search algorithm for maze generation
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int stack_x[MAP_WIDTH * MAP_HEIGHT];
    int stack_y[MAP_WIDTH * MAP_HEIGHT];
    int top = 0;
    
    while (1) {
        int found = 0;
        
        for (int i=0; i<4; i++) {
            // Check adjacent cell
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 1 || nx >= MAP_WIDTH-1 || ny < 1 || ny >= MAP_HEIGHT-1) {
                continue;
            }
            
            if (visited[ny][nx] == 1) {
                continue;
            }
            
            // Check if adjacent cell has at least 3 floor neighbors
            int floor_neighbors = 0;
            for (int j=0; j<4; j++) {
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                
                if (nnx < 0 || nnx >= MAP_WIDTH || nny < 0 || nny >= MAP_HEIGHT) {
                    continue;
                }
                
                if (map[nny][nnx] == FLOOR) {
                    floor_neighbors++;
                }
            }
            
            if (floor_neighbors >= 3) {
                found = 1;
                stack_x[top] = x;
                stack_y[top] = y;
                top++;
                
                // Carve out the wall to the adjacent cell
                map[ny][nx] = FLOOR;
                visited[ny][nx] = 1;
                x = nx;
                y = ny;
                break;
            }
        }
        
        if (found == 0) {
            if (top == 0) {
                break;
            }
            top--;
            x = stack_x[top];
            y = stack_y[top];
        }
    }
}

void print_map() {
    for (int i=0; i<MAP_HEIGHT; i++) {
        for (int j=0; j<MAP_WIDTH; j++) {
            if (map[i][j] == EMPTY) {
                printf(" ");
            } else if (map[i][j] == WALL) {
                printf("#");
            } else if (map[i][j] == FLOOR) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    generate_map();
    print_map();
    return 0;
}