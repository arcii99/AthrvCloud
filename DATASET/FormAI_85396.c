//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

// Struct representing each cell in the dungeon
typedef struct cell {
    char icon;      // Character representation of the cell
    int visited;    // Flag for whether or not the cell has been visited
} cell;

// Dungeon map represented as 2D array of cells
cell map[HEIGHT][WIDTH];

// Function to generate the dungeon
void generateDungeon() {
    // Initialize random seed
    srand(time(NULL));

    // Place walls on the edges of the map
    for (int i = 0; i < WIDTH; i++) {
        map[0][i].icon = '#';
        map[HEIGHT-1][i].icon = '#';
    }
    for (int i = 0; i < HEIGHT; i++) {
        map[i][0].icon = '#';
        map[i][WIDTH-1].icon = '#';
    }

    // Carve out the dungeon using a random walk algorithm
    int cur_x = WIDTH/2, cur_y = HEIGHT/2;
    map[cur_y][cur_x].icon = '.';
    map[cur_y][cur_x].visited = 1;
    while (1) {
        int dir = rand() % 4;

        // Move in a random direction
        switch (dir) {
            case 0:
                if (cur_y > 1 && !map[cur_y-2][cur_x].visited) {
                    map[cur_y-1][cur_x].icon = '.';
                    map[cur_y-2][cur_x].icon = '.';
                    map[cur_y-2][cur_x].visited = 1;
                    cur_y -= 2;
                }
                break;
            case 1:
                if (cur_x < WIDTH-2 && !map[cur_y][cur_x+2].visited) {
                    map[cur_y][cur_x+1].icon = '.';
                    map[cur_y][cur_x+2].icon = '.';
                    map[cur_y][cur_x+2].visited = 1;
                    cur_x += 2;
                }
                break;
            case 2:
                if (cur_y < HEIGHT-2 && !map[cur_y+2][cur_x].visited) {
                    map[cur_y+1][cur_x].icon = '.';
                    map[cur_y+2][cur_x].icon = '.';
                    map[cur_y+2][cur_x].visited = 1;
                    cur_y += 2;
                }
                break;
            case 3:
                if (cur_x > 1 && !map[cur_y][cur_x-2].visited) {
                    map[cur_y][cur_x-1].icon = '.';
                    map[cur_y][cur_x-2].icon = '.';
                    map[cur_y][cur_x-2].visited = 1;
                    cur_x -= 2;
                }
                break;
        }

        // Check if we're done
        int done = 1;
        for (int i = 1; i < HEIGHT-1; i += 2) {
            for (int j = 1; j < WIDTH-1; j += 2) {
                if (!map[i][j].visited)
                    done = 0;
            }
        }
        if (done)
            break;
    }

    // Place the player at a random location in the dungeon
    while (1) {
        int x = rand() % (WIDTH-2) + 1;
        int y = rand() % (HEIGHT-2) + 1;
        if (map[y][x].icon == '.') {
            map[y][x].icon = '@';
            break;
        }
    }
}

int main() {
    // Generate the dungeon
    generateDungeon();

    // Print out the map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j].icon);
        }
        printf("\n");
    }

    return 0;
}