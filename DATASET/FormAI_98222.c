//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void print_maze(int maze[WIDTH][HEIGHT]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf(maze[j][i] ? " " : "#");
        }
        printf("\n");
    }
}

void generate_maze(int maze[WIDTH][HEIGHT], int x, int y) {
    int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int random_index;
    int temp_x, temp_y;

    // marking the current cell as visited
    maze[x][y] = 1;

    // shuffle the directions array randomly
    for(int i=3; i>=0; i--) {
        random_index = rand() % (i+1);

        int temp1 = directions[i][0];
        int temp2 = directions[i][1];
        directions[i][0] = directions[random_index][0];
        directions[i][1] = directions[random_index][1];
        directions[random_index][0] = temp1;
        directions[random_index][1] = temp2;
    }

    // recursive calls to unvisited neighbours
    for(int i=0; i<4; i++) {
        temp_x = x + directions[i][0];
        temp_y = y + directions[i][1];

        if(temp_x >= 0 && temp_x < WIDTH && temp_y >= 0 && temp_y < HEIGHT && !maze[temp_x][temp_y]) {
            // removing a wall
            if(directions[i][0] == 1) {
                maze[x][y+1] = 1;
            } else if(directions[i][0] == -1) {
                maze[x][y-1] = 1;
            } else if(directions[i][1] == 1) {
                maze[x+1][y] = 1;
            } else {
                maze[x-1][y] = 1;
            }

            generate_maze(maze, temp_x, temp_y);
        }
    }
}

int main() {
    int maze[WIDTH][HEIGHT] = {0};

    srand(time(NULL));

    // start from a random cell
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;

    generate_maze(maze, x, y);

    print_maze(maze);

    return 0;
}