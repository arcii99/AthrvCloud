//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[WIDTH][HEIGHT];

void generate_maze(int x, int y) {
    maze[x][y] = 1;
 
    int directions[4][2] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
 
    for (int i = 0; i < 4; i++) {
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];
 
        if (new_x < 0 || new_x >= WIDTH || new_y < 0 || new_y >= HEIGHT) {
            continue;
        }
 
        if (maze[new_x][new_y] != 0) {
            continue;
        }
 
        maze[x + directions[i][0] / 2][y + directions[i][1] / 2] = 1;
 
        generate_maze(new_x, new_y);
    }
}

void print_maze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[x][y] == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[x][y] = 0;
        }
    }
 
    int start_x = rand() % WIDTH;
    int start_y = rand() % HEIGHT;
 
    generate_maze(start_x, start_y);
 
    print_maze();
 
    return 0;
}