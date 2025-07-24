//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL 0
#define PATH 1

int maze[MAZE_SIZE][MAZE_SIZE];

void generate_maze(int x, int y) {
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int rand_dir, count = 0, new_x, new_y;
    
    while (count < 4) {
        rand_dir = rand() % 4;
        new_x = x + directions[rand_dir][0];
        new_y = y + directions[rand_dir][1];
        
        if (new_x >= MAZE_SIZE || new_x < 0 || new_y >= MAZE_SIZE || new_y < 0) {
            count++;
            continue;
        }
        
        if (maze[new_y][new_x] == WALL) {
            maze[new_y][new_x] = PATH;
            if (rand_dir == 0)
                generate_maze(new_x, new_y-1);
            else if (rand_dir == 1)
                generate_maze(new_x, new_y+1);
            else if (rand_dir == 2)
                generate_maze(new_x-1, new_y);
            else
                generate_maze(new_x+1, new_y);
        }
        count++;
    }
}

void print_maze() {
    int i, j;
    for (i=0; i<MAZE_SIZE; i++) {
        for (j=0; j<MAZE_SIZE; j++) {
            if (maze[i][j] == WALL)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int start_x, start_y;
    
    // Initialize maze
    int i, j;
    for (i=0; i<MAZE_SIZE; i++) {
        for (j=0; j<MAZE_SIZE; j++) {
            if (i == 0 || i == MAZE_SIZE-1 || j == 0 || j == MAZE_SIZE-1)
                maze[i][j] = WALL; // set outer walls
            else
                maze[i][j] = PATH; // set pathways
        }
    }
    
    // Generate maze
    start_x = rand() % (MAZE_SIZE-2) + 1;
    start_y = rand() % (MAZE_SIZE-2) + 1;
    maze[start_y][start_x] = PATH; // starting point for maze generation
    generate_maze(start_x, start_y);
    
    // Print maze
    printf("Maze:\n");
    print_maze();
    
    return 0;
}